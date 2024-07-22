#include <iostream>
#include <string>
#include<cstdlib>
#include<windows.h>
using namespace std;

class Destination {
protected:
    string name;
    int price;
    int days;
    int nights;
   

public:
int choice1;
    Destination()
    {
        name="";
        price=0;
        days=0;
        nights=0;
    }
    Destination(const string& destinationName, int Price) 
        {
            name=destinationName;
            price=Price;
            days=0;
            nights=0;
        }

    virtual void displayInfo() = 0;

    void inputDetails() {
        cout << "\t 1 day expenditure: " << price << endl;
        cout << "\t How many days you want to spend in " << name << ": ";
        cin >> days;
        
        cout << "\t How many nights you want to spend in " << name << ": ";
        cin >> nights;
        
    }

    void calculateExpenditure() const {
        int total = (days + nights) * price;
        cout << "\t Total expenditure will be: " << total << endl;
    }
    
    void message()
        {
            cout<<" \t \t  You have succesfully booked your desired rooms."<<endl<<" \t \t For furthur enquiry, Please contact us : 98696332"<<endl<<" \t \t PLEASE ENJOY YOUR STAY";
        }
    

    virtual ~Destination() {}
};

class Kathmandu : public Destination {
public:
    Kathmandu() : Destination("Kathmandu", 5450) {}

    void displayInfo() override {
        cout << endl << endl;
        cout << "\t\t\t\t\t\t   |-- Kathmandu --|" << endl << endl;
        cout << "  >>> Great decision !!! No doubt, that Kathmandu is famous for its enchanting beauty and beautiful mountains. " << endl << endl;
        cout << "      Total Hotels that we have in Kathmandu are: 4" << endl << endl;
        cout << "\t\t\t\t ~ At Jhamsikhel" << endl;
        cout << "\t\t\t\t ~ At Thamel" << endl;
        cout << "\t\t\t\t ~ At Sundhara" << endl;
        cout << "\t\t\t\t ~ At Boudha" << endl << endl;
        cout << " -- These are the points, on which we have hotels in Kathmandu." << endl << endl;
    }
    void ktmchoice(){
        cout << "Choose a hotel location:" << endl;
        cout << "1. Jhamsikhel" << endl;
        cout << "2. Thamel" << endl;
        cout << "3. Sundhara" << endl;
        cout << "4. Boudha" << endl;
        cout << "Enter your choice: ";
        cin>>choice1;
    }
};

class Pokhara : public Destination {
public:
    Pokhara() : Destination("Pokhara", 4950) {}

    void displayInfo() override {
        cout << endl << endl;
        cout << "\t\t\t\t\t\t   |-- Pokhara --|" << endl << endl;
        cout << "  >>> Great decision !!! No doubt, that Pokhara is famous for its beautiful mountains and green meadows. " << endl << endl;
        cout << "      Total Hotels that we have in Pokhara are: 3" << endl << endl;
        cout << "\t\t\t\t ~ At Lakeside " << endl;
        cout << "\t\t\t\t ~ At Sarangkot" << endl;
        cout << "\t\t\t\t ~ At Pame" << endl << endl;
        cout << " These are the points, on which we have hotels in Pokhara." << endl << endl;
    }
    void pkrchoice(){
        cout << "Choose a hotel location:" << endl;
        cout << "1. Lakeside" << endl;
        cout << "2. Sarangkot" << endl;
        cout << "3. Pame" << endl;
        cout << "Enter your choice: ";
        cin>>choice1;
    }
};

void room_status(bool s[], int size) {
    cout << "\t\t\t\t\t Room No \t\t Status" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "\t\t\t~" << 100 + i << "~\t\t" << (s[i] ? "Booked" : "Unbooked") << endl;
    }
}
class Location{
    public:
    int n;
    int j;
    int var;
    int hotel() {
    cout << "\t\t\t\t\t ROOM.NO  \t\t STATUS" << endl;
    cout << "\t\t\t\t ---------------------------------------------" << endl;
    for (int i = 100; i <= 110; i++) {
        cout << "\t\t\t\t\t ~" << i << "~    \t\t UNBOOKED" << endl;
    }
    cout << endl;
    return 0;
}

void hotelafter() {
   
    cout << endl << endl;
    cout<<"How many Rooms do you want to book?";
    cin>>n; 
    int room[n];
    cout << "\t Enter any ROOM.NO you want to book: ";
    for (int j=0;j<n;j++)
    {
    cin >> room[j];
    }

   for (int j=0;j<n;j++)
   {
    if (room[j] >= 100 && room[j] <= 110) {
        cout << "\t ROOM | " << room[j] << " | has been booked." << endl << endl;
    } else {
        cout << "\t\t ROOM | " << room[j] << " | does not exist" << endl << endl;
        cout << "\t\t INVALID ROOM.NO !" << endl << endl;
    }
   }
    cout << "\t\t\t\t\t ROOM.NO  \t\t STATUS" << endl;
    cout << "\t\t\t\t ------------------------------------------------" << endl;
   
      
  
    
     for (int i = 100; i <= 110; i++) {
        var=0;
        cout << "\t\t\t\t\t ~" << i << "~  \t\t ";
        for (int j=0;j<n;j++)
        {
        if (i == room[j]) {
            cout << "BOOKED" << endl;
            var=1;
        }
        }
        if(var==1){
            continue;
        }
        for (int j=0;j<n;j++)
        {
        if (i != room[j]) {
            cout << "UNBOOKED" << endl;
            break;
        }
        
        }
     }
    
}
};

class loading
    {
       public:
        void loading_screen()
        {
        
        char x=219;
        for(int i=0; i<25; i++)
        {
        cout<<x;
        if(i<10)
        {
            Sleep(500);
        }
        else if(i<=15)
        {
            Sleep(200);
        }
        else if(i>=20)
        {
            Sleep(100);
        }
        }
        }
};
int main() {
    Location l1,l2,l3,l4;
    loading load;
    Kathmandu k1;
    Pokhara p1;
    Destination* destination = nullptr;
    int choice;

        cout<<endl<<endl;

    cout<<"\t\t\t\t\t Project Topic = [ ~ HOTEL BOOKING SYSTEM ~ ]"<<endl<<endl;
    cout<<"\t\t\t\t\t Group Members: "<<endl;
    cout<<"\t\t\t\t\t              1) Sugam Sen Sinjali(ACE079BCT080)\n";
    cout<<"\t\t\t\t\t              2) Sushant Bijukchhe (ACE079BCT074)\n";
    cout<<"\t\t\t\t\t              3) Sulav Karki (ACE079BCT070)\n";
    cout<<endl;
    cout<<"\t\t\t\t\t Sumbitted to: \n";
    cout<<"\t\t\t\t\t              < Dhiraj Pyakurel Sir >"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t   Loading ";
    
    load.loading_screen();

        system("cls");

        cout<<endl<<endl;       
        cout<<"\t\t\t\t\t ====================================== "<<endl;
        cout<<"\t\t\t\t\t       WELCOME TO ACEM PARADISE RESORT"<<endl;
        cout<<"\t\t\t\t\t ====================================== "<<endl;
        
        //Booking Starts here

    while (true) {
        cout << "Choose a destination:" << endl;
        cout << "1. Kathmandu" << endl;
        cout << "2. Pokhara" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
            case 1:
                destination = new Kathmandu();
                destination->displayInfo();
                destination->inputDetails();
                destination->calculateExpenditure();
                k1.ktmchoice();
                break;
            case 2:
                destination = new Pokhara();
                destination->displayInfo();
                destination->inputDetails();
                destination->calculateExpenditure();
                p1.pkrchoice();
                break;
            case 3:
                cout<<"\t \t You have chosen to exit from this program."<<endl<<" \t \t Please Come Back Again"<<endl;
                termination:
                cout<<endl<<"\t\t\t\t\t   Exiting ";
                load.loading_screen();
                
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
        delete destination;

        switch (choice) {
            case 1:
                l1.hotel();
                l1.hotelafter();
                destination-> message();

                goto termination;
                break;
            case 2:
                l2.hotel();
                l2.hotelafter();
                destination-> message();

                 goto termination;
                break;
            case 3:
                l3.hotel();
                l3.hotelafter();
                destination-> message();
                goto termination;
                break;
            case 4:
                l4.hotel();
                l4.hotelafter();
                destination-> message();
                goto termination;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
    }
    return 0;
}
