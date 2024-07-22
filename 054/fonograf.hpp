#ifndef fonograf_fonograf_hpp
#define fonograf_fonograf_hpp

#include "vendor/miniaudio.h"
#include <string>
#include <vector>

/* Whether the player is currently playing a track, paused, hasn't loaded any
 * file or is loading a file. */
enum class PlayerState {
    NO_TRACK_CHOSEN,
    TRACK_LOADING,
    PLAYING,
    PAUSED,
};

/* Class representing a single audio file. */
struct Track {
    /* The path to the file. */
    std::string filepath;

    /* Whether this file has already been played. Used to prevent playing the
     * same track multiple times. */
    bool played;

    Track(std::string p) : filepath(p), played(false) {}
};

class Fonograf {
    /* The audio decoder and device, provided by miniaudio. */
    ma_decoder decoder;
    ma_device device;

    /* Whether the ma_decoder and ma_device are initialized respectively.
     * Necessary for the `cleanup()` method to determine if it needs to
     * uninitialize them. Must be set to true if decoder and device are
     * initialized respectively and false otherwise. */
    bool decoder_inited;
    bool device_inited;

    /* The track currently loaded into miniaudio's device. */
    Track* current_track;

    /* Track length in seconds for current_track. */
    int duration;

    /* Track length as PCM frames for current_track. */
    ma_uint64 duration_as_pcm_frames;

    /* The remaining duration before the track ends for current_track. */
    int remaining_duration;

    /* The current state of the music player. See `enum class PlayerState`. */
    PlayerState player_state;

    /* A list of the tracks present in the current directory. */
    std::vector<Track> tracks_in_directory;

    /* Uninitialize the miniaudio device and decoder if they're currently
     * initialized. */
    void cleanup();

    /* Find all the `.mp3`, `.wav` and `.flac` audio files in the directory and
     * pass in Track objects for them to `tracks_in_directory`. */
    void fetch_tracks_in_directory();

    /* Setup the miniaudio device and decoder, grab the duration of and play the
     * passed in track. */
    void play_track_boilerplate(Track& track);

    /* Print out a line of text centered in the terminal. */
    void print_centered_line_of_text(std::string text);

    /* Draw the UI with information about the playing tracks, tracks in the
     * current directory and controls. */
    void print_ui_header();

    /* Redraw the UI. */
    void redraw();

  public:
    Fonograf();
    ~Fonograf();

    /* Render the user interface and handle input. */
    int render_ui();

    /* Play the current track. */
    void play_track();

    /* Play the passed in track. */
    void play_track(Track& track);
};

#endif
