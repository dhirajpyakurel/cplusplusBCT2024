#include <iostream>
#include<string> 
#include<cstdlib>
using namespace std;
int main(){
    string player;
    int amount;
    int let;
    int Dice;
    char option;
    int Amount_bid;
    srand(time(0));
    cout<<"\t\t DOUBLE YOUR MONEY";
    cout<<"\n Enter the name of the player:";
    getline(cin,player);
    cout<<"\n enter the initial amount to deposite::$";
    cin>>amount;
         do{
            system("cls");
         
         do{
            cout<<"\n welcome"<<endl<<player<<"-->Ready to play"<<endl<<endl;
            cout<<"Enter Bid Amount::$";
            cin>>Amount_bid;
            if(Amount_bid>amount){
                cout<<"you cannot bid amount higher than::"<<amount<<endl<<endl;
                cout<<"Re-enter your bid amount";
            }
            }while(Amount_bid>amount);
            

         
         do{
            cout<<" guess a number from 1 to 10"<<endl<<endl;
            cin>>let;
        
            if (let<=0 || let>10){
                cout<<"you cannot choose the number greater than 10!"<<endl<<"try again"<<endl<<endl;
            }
            }while(let<=0 || let>10);
             
             Dice=rand()%10+2;

             if(Dice==let){
                cout<<"CONGRALUTION YOU WON::"<<let*5<<endl<<endl;
                amount=amount+Amount_bid*5;
                cout<<endl;
                cout<<"your total amount::"<<amount<<endl<<endl;

            }
            else{
                cout<<"you loose::"<<Amount_bid<<"$\n";
                
            
                 cout<<"the winning number was::"<<Dice<<endl<<endl;
                 amount=amount-Amount_bid;
                  cout<<"Your balance::"<<amount<<endl;
            }
           
              if (amount==0){
                cout<<"  Insufficient Amount!!"<<endl<<endl;
                break;
            }
            

            cout<<endl<<endl<<"Do you want to bid again(y/n)?"<<endl;
            cin>>option;
          
          }while (option=='Y'|| option =='y');
         
          cout<<"Thank you for playing this again \n\n   Your current amount is::"<<amount<<endl;
         
           return (0);
}



            




      

         

