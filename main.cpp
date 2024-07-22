#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    int hours,minu,sec,a ,counts;
    counts=a=0;
    while(counts==0)
    {

        cout<<"enter hours:"<<endl;
        cin>>hours;
        cout<<"enter mminutes:"<<endl;
        cin>>minu;
        cout<<"enter seconds:"<<endl;
        cin>>sec;
        if(hours<24&&minu<<60&&sec<<60)

            counts++;
            else
                system("cls");

    }
    while(a==0)
    {

        system("cls");
        cout<<hours<<":"<<minu<<":"<<sec<<endl;
       float sleep(10000);
        sec++;
        if(sec>59)
        {
            sec=0;
            minu++;
        }
        if(minu>59)
        {

            minu=0;
            hours++;
        }
        if(hours>24)
        {

            hours=0;
        }
    }
    return 0;
}
