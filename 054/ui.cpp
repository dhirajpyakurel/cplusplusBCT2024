#include "fonograf.hpp"
#include "vendor/rogueutil.h"
#include <thread>

namespace ru = rogueutil;

void Fonograf::print_centered_line_of_text(std::string text) {
    int cols = ru::tcols();
    int center_start = (cols / 2) - (text.size() / 2);

    for (int i = 0; i < center_start; i++) {
        std::cout << " ";
    }

    std::cout << text << "\n";
}

void Fonograf::print_ui_header() {
    ru::setColor(ru::GREEN);
    print_centered_line_of_text("Fonograf.");
    ru::resetColor();

    ru::rutil_print("\n");

    /* Now playing section */
    if (player_state != PlayerState::NO_TRACK_CHOSEN) {
        if (player_state == PlayerState::PAUSED) {
            ru::setColor(ru::YELLOW);
            ru::rutil_print("Paused: ");
            ru::resetColor();

            ru::rutil_print(current_track->filepath + "\n");
        } else {
            ru::setColor(ru::YELLOW);
            ru::rutil_print("Now playing: ");
            ru::resetColor();

            ru::rutil_print(current_track->filepath + "\n");
        }

        ru::setColor(ru::YELLOW);
        ru::rutil_print("Duration: ");
        ru::resetColor();

        std::stringstream ss;
        ss << duration / 60 << " min " << (duration - ((duration / 60) * 60))
           << " sec\n";
        ru::rutil_print(ss.str());

        if (remaining_duration > 0) {
            ru::setColor(ru::YELLOW);
            ru::rutil_print("Remaining: ");
            ru::resetColor();

            std::stringstream ts;
            ts << remaining_duration / 60 << " min "
               << (remaining_duration - ((remaining_duration / 60) * 60))
               << " sec\n";
            ru::rutil_print(ts.str());
        } else {
            ru::setColor(ru::YELLOW);
            ru::rutil_print("Track has ended.\n");
            ru::resetColor();
        }
    } else {
        ru::setColor(ru::YELLOW);
        ru::rutil_print("No track chosen.\n");
        ru::resetColor();
    }

    ru::rutil_print("\n");

    /* Tracks list */
    ru::setColor(ru::YELLOW);
    ru::rutil_print("Tracks found: \n");
    ru::resetColor();

    int i = 1;
    for (const auto& track : tracks_in_directory) {
        ru::setColor(ru::MAGENTA);
        ru::rutil_print("\t [" + std::to_string(i) + "] ");
        ru::resetColor();

        ru::rutil_print(track.filepath + "\n");
        i++;
    }

    if (tracks_in_directory.empty()) {
        ru::rutil_print("No songs found in this folder.\n");
    }

    ru::rutil_print("\n");

    /* Controls */
    ru::setColor(ru::YELLOW);
    ru::rutil_print("Controls: \n");
    ru::resetColor();

    if (player_state != PlayerState::NO_TRACK_CHOSEN) {
        ru::rutil_print("\t 'p' to pause or play\n");
    }
    ru::rutil_print("\t 'c' to choose a song to switch to\n"
                    "\t 'q' to quit\n");
}

void Fonograf::redraw() {
    ru::cls();
    print_ui_header();
}

/*** PUBLIC ***/

int Fonograf::render_ui() {
    ru::saveDefaultColor();

    redraw();

    while (true) {
        if (player_state != PlayerState::NO_TRACK_CHOSEN) {
            ma_uint64 cursor;
            if (ma_decoder_get_cursor_in_pcm_frames(&decoder, &cursor) !=
                MA_SUCCESS) {
                throw std::runtime_error(
                    "Failed to retrieve current cursor position");
            }

            int remaining_frames = duration_as_pcm_frames - cursor;
            remaining_duration = remaining_frames / decoder.outputSampleRate;

            /* If track ended, play another that hasn't yet been played. */
            if (remaining_frames <= 0) {
                cleanup();

                int played_num = 0;
                for (auto& track : tracks_in_directory) {
                    if (!track.played) {
                        play_track(track);
                        break;
                    }
                    played_num++;
                }
            }
        }

        if (kbhit()) {
            int key = getch();
            switch (key) {
            case 'q':
                return 0;
            case 'c': {
                int last_row = ru::trows();
                gotoxy(0, last_row);

            song_picker:
                std::string ans;
                ru::rutil_print("Enter the number of the song to switch to, or "
                                "'b' to go back: ");
                std::cin >> ans;

                try {
                    int num = std::stoi(ans);

                    // Switch to the new song
                    if (device_inited)
                        ma_device_stop(&device);
                    cleanup();

                    play_track(tracks_in_directory[num - 1]);
                    break;
                } catch (const std::invalid_argument& e) {
                    if (ans == "b") {
                        break; // Break out of the switch
                    }

                    ru::rutil_print(
                        "Invalid option! Press any key to continue.");
                    getch();

                    redraw();
                    goto song_picker;
                }
            }
            case 'p': {
                if (player_state == PlayerState::PLAYING) {
                    ma_device_stop(&device);
                    player_state = PlayerState::PAUSED;
                } else if (player_state == PlayerState::PAUSED) {
                    ma_device_start(&device);
                    player_state = PlayerState::PLAYING;
                }
            }
            }

            continue;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        redraw();
    }
}
