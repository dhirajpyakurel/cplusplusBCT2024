#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int max_item = 10;
const string filename = "todolist.txt";

class todo {
    private:
        int itemcount;
        string todolist[max_item];

    public:
        todo() : itemcount(0) {
            loadFromFile();
        }

        ~todo() {
            saveToFile();
        }

        void displayMenu() {
            cout << "\n===== TODO LIST MENU =====\n";
            cout << "1. Add item\n";
            cout << "2. Mark item as done\n";
            cout << "3. Display all items\n";
            cout << "4. Exit\n";
            cout << "==========================\n";
            cout << "Enter your choice: ";
        }

        void addItem() {
            if (itemcount < max_item) {
                string item;
                cout << "Enter item to add: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, item);
                todolist[itemcount] = item;
                itemcount++;
                cout << "Item added to the list.\n";
            } else {
                cout << "Sorry, the to-do list is full!\n";
            }
        }

        void markItemDone() {
            int index;
            cout << "Enter index of item to mark as done (1-" << itemcount << "): ";
            cin >> index;
            if (index >= 1 && index <= itemcount) {
                for (int i = index - 1; i < itemcount - 1; ++i) {
                    todolist[i] = todolist[i + 1];
                }
                itemcount--;
                cout << "Item marked as done.\n";
            } else {
                cout << "Invalid index!\n";
            }
        }

        void displayItems() {
            cout << "\n===== TODO LIST =====\n";
            if (itemcount == 0) {
                cout << "The list is empty.\n";
            } else {
                for (int i = 0; i < itemcount; ++i) {
                    cout << i + 1 << ". " << todolist[i] << endl;
                }
            }
            cout << "=====================\n";
        }

        void saveToFile() {
            ofstream outFile(filename.c_str());
            if (outFile.is_open()) {
                outFile << itemcount << endl;  
                for (int i = 0; i < itemcount; ++i) {
                    outFile << todolist[i] << endl;
                }
                outFile.close();
            } else {
                cout << "Unable to open file for saving.\n";
            }
        }

        void loadFromFile() {
            ifstream inFile(filename.c_str());
            if (inFile.is_open()) {
                inFile >> itemcount;
                inFile.ignore();
                for (int i = 0; i < itemcount; ++i) {
                    getline(inFile, todolist[i]);
                }
                inFile.close();
            } else {
                itemcount = 0; // No file found, start with an empty list
                cout << "No saved to-do list found. Starting with an empty list.\n";
            }
        }
};

int main() {
    todo t1;
    int choice;
    do {
        t1.displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer after taking integer input
        switch (choice) {
            case 1:
                t1.addItem();
                break;
            case 2:
                t1.markItemDone();
                break;
            case 3:
                t1.displayItems();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

