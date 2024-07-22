#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Library{
    private:
        string title;
        string author;
    public:
        void addBook(){
            ofstream fout;
            fout.open("libraryRecords.txt", ios::app);
            if (!fout) {
                cout << "Unable to open file for writing." << endl;
            }
            cout<<"Enter a book: "<<endl;
            cin.ignore();
            getline(cin,title);
            cout<<"Enter author: "<<endl;
            getline(cin,author); 
            fout << title <<endl;
            fout << author <<endl;
            fout.close();
        }
        void displayBooks () {
            ifstream fin;
            fin.open("libraryRecords.txt");
            if (!fin) {
                cout << "Unable to open file for reading." << endl;
            }
            while(getline(fin,title) && getline(fin,author)) {
                cout << "Title: "<< title << endl << "Author: "<< author << endl;
            }
            fin.close(); 
        }
        void searchByTitle(){
            string bookName;
            bool found = false;
            ifstream fin;
            fin.open("libraryRecords.txt");
            if (!fin) {
                cout << "Unable to open file for reading." << endl;
            }
            cout<<"Enter name of book"<<endl;
            cin.ignore();
            getline(cin,bookName);
            while(getline(fin,title) && getline(fin,author)){
                getline(fin,title);
                if (bookName == title){
                    cout<<"Name of book: " << title<< endl;
                    cout<<"Author: "<< author<< endl;
                    found = true;
                    break;
                }
            }
            if (found == false) {
                cout<<"No such book is found!"<<endl;
            }
            fin.close();  
        }

};
int main () {
    Library lib;
    int choice;
    do {
        cout << "Welcome to Library Management System"<< endl;
        cout << "MENU : "<<endl;
        cout<<"1. Add Book"<< endl;
        cout<<"2. Display Book"<< endl;
        cout<<"3. Search Book"<< endl;
        cout<<"4. Exit"<< endl;
        cout<<"Enter choice"<< endl;
        cin>>choice;
        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                cout << "Displaying all books: " << endl;
                lib.displayBooks();
                break;
            case 3:
                cout << "Searching for a book by title: " << endl;
                lib.searchByTitle();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }while (choice !=4);
    return 0;
}