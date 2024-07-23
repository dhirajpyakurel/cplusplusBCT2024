#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<thread>
using namespace std;
 class pomodoro_timer
 {
    private:
    int work_duration;
    int break_duration;
    int count=0;
    public:
    pomodoro_timer()
    {
        work_duration=25;
        break_duration=5;
    }
    void start()
    {
        char choice='y';
        while(choice=='y'|| choice=='Y')
        {
            count++;
            cout << "Pomodoro " << count << " started. Work for " << work_duration << " minutes." << endl;
            
            
            sleep(work_duration * 60);  
            cout << "Time's up! Take a break for 5 minutes." << endl;

            sleep(break_duration * 60); 
            cout << "Break is over." << endl;

            cout << "Start another Pomodoro? (y/n): ";
            cin >> choice;
        }
    }
        };

int main() {
    pomodoro_timer timer;
    timer.start();

    return 0;
}
