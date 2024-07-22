#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;


int slot_machine(long &credits)
{
    short random_num1=9,random_num2=3,random_num3=5;
    short users_num1=0,users_num2=0,users_num3=0;
    int bet_amount;

    char ch;
    do{

        do{
        cout<<"BALANCE= "<<credits<<" credits"<<endl;
        cout<<"Enter bet amount"<<endl;
        cin>>bet_amount;
        if(bet_amount>credits)
        {
            cout<<"============================================"<<endl;
            cout<<"Insufficient balance"<<endl;
        }
        }while(bet_amount>credits);

        cout<<"============================================"<<endl;
        cout<<"Enter the slot numbers"<<endl;
        cin>>users_num1>>users_num2>>users_num3;
        cout<<"|| "<<users_num1<<" | "<<users_num2<<" | "<<users_num3<<" ||"<<endl;

        //random number generation
        srand(time(0));
        random_num1= rand()%10;
        random_num2= rand()%10;
        random_num3= rand()%10;
        cout<<"ROLLING............."<<endl;
        cout<<"NUMBERS ARE:"<<endl;
        cout<<"|| "<<random_num1<<" | "<<random_num2<<" | "<<random_num3<<" || "<<endl;
        cout<<"============================================"<<endl;


        if (users_num1==random_num1 && users_num2==random_num2 && users_num3==random_num3)
        {
            cout<<"CONGRATS! ALL NUMBERS MATCH! YOU WON "<<bet_amount*100<<" CREDITS!!"<<endl;
            credits=credits+bet_amount*100;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }

        else if(users_num1==random_num1 && users_num2==random_num2 || users_num2==random_num2 && users_num3==random_num3 || users_num1==random_num1 && users_num3==random_num3)
        {
            cout<<"TWO OF THE NUMBERS MATCH! YOU WON "<<bet_amount*10<<" CREDITS!!"<<endl;;
            credits=credits+bet_amount*10;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }

        else if (users_num1==random_num1 ||users_num2==random_num2 || users_num3==random_num3)
        {
            cout<<"ONE NUMBER MATCHES! YOU WON "<<bet_amount*2<<" CREDITS!!"<<endl;;
            credits=credits+bet_amount*5;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }

        else
        {   
            if ((credits-bet_amount<=0))
            {
                credits=0;
                cout<<"YOU ARE OUT OF CREDITS "<<endl<<"YOU LOSE!"<<endl;
                exit(0);
            }
            
            cout<<"YOU LOST "<<bet_amount<<" CREDITS!!"<<endl;
            credits=credits-bet_amount;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }
        
        cout<<"============================================"<<endl;
        cout<<"PLAY AGAIN?(y/n)"<<endl;
        cin>>ch;
        cout<<"============================================"<<endl;
    }while(ch=='y'||ch=='Y');
    return 0;
}


int random_number_guesser(long &credits)
{
    short users_number=0;
    short random_number;
    int bet_amount=0;

    char ch;
    do{
        do{
        cout<<"BALANCE= "<<credits<<" credits"<<endl;
        cout<<"Enter bet amount"<<endl;
        cin>>bet_amount;
        if(bet_amount>credits)
        {
            cout<<"============================================"<<endl;
            cout<<"Insufficient balance"<<endl;
        }
        }while(bet_amount>credits);

        cout<<"============================================"<<endl;
        cout<<"Enter a number between 0-9"<<endl;
        cin>>users_number;
        cout<<"============================================"<<endl;
        srand(time(0));
        random_number= rand()%10; //generates random number
        cout<<"RANDOM NUMBER IS: "<<random_number<<endl;
        cout<<"============================================"<<endl;

        if (users_number==random_number)
        {
            cout<<"CONGRATS! YOU WON "<<bet_amount*2<<" CREDITS!!"<<endl;
            credits=credits+bet_amount*2;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }

        else
        {   
            if ((credits-bet_amount)<=0)
            {
                credits=0;
                cout<<"YOU ARE OUT OF CREDITS "<<endl<<"YOU LOSE!"<<endl;
                exit(0);
            }
            
            cout<<"YOU LOST "<<bet_amount<<" CREDITS!!"<<endl;
            credits=credits-bet_amount;
            cout<<"NEW BALANCE = "<<credits<<" CREDITS"<<endl;
        }

        cout<<"============================================"<<endl;
        cout<<"PLAY AGAIN?(y/n)"<<endl;
        cin>>ch;
        cout<<"============================================"<<endl;

    }while(ch=='y'||ch=='Y');
    return 0;
}


int main()
{
    string user_name;
    long credits=1000;
    int option=0;
    cout<<"Welcome!"<<endl;

    while(option!=3)
    {
        cout<<"Select the game you want to play:"<<endl;
        cout<<"1. Slot Machine"<<endl<<"2. Random number guesser"<<endl<<"3. Exit"<<endl; 
        cin>>option;
        if(option==3)
        {break;}

        switch (option)
        {
        case 1:
            slot_machine(credits);
            break;

        case 2:
            random_number_guesser(credits);
            break;

        default:
            cout<<"INVALID CHOICE!"<<endl;
            break;
        }
    }

    cout<<"============================================"<<endl;
    cout<<"FINAL CREDITS= "<<credits<<endl<<"BYE BYE!"<<endl;
    cout<<"Made by Trishal Srivastava & Sulav Neupane";
    return 0;
};
