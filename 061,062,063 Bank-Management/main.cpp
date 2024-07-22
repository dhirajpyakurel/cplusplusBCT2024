#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<map>
#include<cstdlib>
#include<ctime>
#include<sstream>
using namespace std;


#ifdef _WIN32
#define CLEAR_SCREEN() system("cls") // For Windows
#else
#define CLEAR_SCREEN() system("clear") // For Linux/Unix
#endif


void pressAnyKeyToContinue()
{
    cout << "\n";
    cout << "Press Enter to continue..." << endl;
    cin.ignore(); // Ignore any previous input in the buffer
    cin.get();    // Wait for a key press
    CLEAR_SCREEN();
}


class Bank
{

    public:

        /* Gets current Time*/
        string get_current_time()
        {
            time_t now = time(0);
            char* dt = ctime(&now);
            string current_time(dt);
            current_time.pop_back(); // Remove the newline character
            return current_time;
        }


        /* Authenticate the user account and pin code for login */
        bool user_authentication(int account_number, int pin_code)
        {
            int existing_account_number, existing_pin_code;

            ifstream authentication_file_read("authentication.txt");

            while (authentication_file_read >> existing_account_number >> existing_pin_code)
            {
                if (account_number == existing_account_number && existing_pin_code == pin_code)
                {
                    authentication_file_read.close();
                    return true;
                }
            }

            authentication_file_read.close();
            return false;

            
        }


        /* To find name of bank user after successful login*/
        string display_name_afterLogin(int account_number)
        {
            int temp_account_number;
            string temp_name;
            double temp_account_balance;
            string name_of_user;

            // To find out name of the user.
            ifstream accounts_file_read("accounts.txt");
            while (accounts_file_read >> temp_account_number >> temp_name >> temp_account_balance)
            {
                if (account_number == temp_account_number)
                {
                    name_of_user = temp_name;   
                    break;
                }
                
            }
            accounts_file_read.close();
            return name_of_user;

        }


        /* To login the user */
        bool login(int account_number)
        {
            int pin_code;

            if(!account_exits(account_number, "accounts.txt"))
            {
                cout << "\n";
                cout << "There is no account with this account number in the bank! " << endl << endl;
                return false;
            }

            else
            {

                cout << "Enter your secret code: ";
                cin >> pin_code;

                if(!user_authentication(account_number, pin_code))
                {

                    cout << "\n";
                    cout << "Incorrect pin code!!" << endl;
                    cout << '\n';
                    return false;
                }

                else
                {
                    string name_of_user = display_name_afterLogin(account_number);  // Find name of bank user
                    cout << '\n';
                    cout << name_of_user <<  "! Welcome to the Bank!!" << endl;
                    return true;    // If user is logged in, return true

                }
                
            }

        return false;
        }


        /* Check if account exists or not */
        bool account_exits(int account_number, const string& check_which_file)
        {
            int existing_account_number;
            string existing_name;

            if (check_which_file == "accounts.txt")
            {
                double amount;
                ifstream file("accounts.txt");       // Reading mode

                while (file >> existing_account_number >> existing_name >> amount)
                {
                    if(existing_account_number == account_number)
                    {
                        file.close();
                        return true;
                    }

                }
            }

            return false;            
        }


        /* Logs the transaction details (deposits and withdraws) */
        void log_transaction(const string& type, int account_number, double transaction_amount)
        {
            ofstream log_file("transaction_log.txt", ios::app);

            if(log_file.is_open())
            {
                log_file << account_number << " " << type << " " << transaction_amount << " on " << get_current_time() << endl;
            }
        }


        /*Generates account number from 1000 to 9999*/
        int generate_account_number()
        {
            int next_available = 1000;
            ifstream file("accounts.txt");
            int existing_account_number;
            int existing_balance;
            char name[25];

            while (file >> existing_account_number >> name >> existing_balance)
            {
                if (existing_account_number == next_available)
                {
                    next_available++;
                }

                if (next_available > 9999)      // Our account making limit is 999
                {
                    cout << "Account limit reached!!" << endl;
                    exit(0);
                }
            }

            file.close();
            return next_available;
             
        }


         /* Asks user to create 4-digit pin code when creating account */
        int create_pin()
        {
            int pin_code = 0;     
            cout << "Create 4 digit pin code for security: ";
            cin >> pin_code;

            string pin_code_in_string = to_string(pin_code);    // Convert int to string to determine length
            if (pin_code_in_string.length() != 4)
            {
                cout << '\n';
                cout << "The pin must be of 4-digit* " << endl;
                return create_pin();
            }

            else
            {
                return pin_code;
            }
        }


        /*Creates account with account number and user name*/
        int create_account()
        {
            int initial_bal = 0;
            char name[25];
            int account_number;

            ofstream account_file("accounts.txt", ios::app);
            ofstream authenticate_file("authentication.txt", ios::app);

            if(account_file.is_open())
            {
                cout << "Enter only first name: ";
                cin >> name;

                int pin_code = create_pin();
                account_number = generate_account_number();

                account_file << account_number << " " << name << " " << initial_bal << endl;
                authenticate_file << account_number << " " << pin_code << endl;
            }

            else
            {
                cout << "System Error!";
            }

            account_file.close();
            authenticate_file.close();

            return account_number;
        }


        /* Deposits Money */
        void deposit(int account_number)
        {
            double deposit_amount;
            int existing_account_number;
            double existing_balance;
            string existing_name;

            cout << "Add amount to deposit: ";
            cin >> deposit_amount;

            ifstream accounts_file("accounts.txt");       // Read
            ofstream temp_file("temp.txt", ios::app);   // Write in a file

            if(!accounts_file.is_open() && !temp_file.is_open())        
            {
                cout << "Error opening file";
                exit(0);
            }

            while (accounts_file >> existing_account_number >> existing_name >> existing_balance) 
            {
                if(existing_account_number == account_number)   // If account number found
                {
                    existing_balance += deposit_amount;

                    temp_file << existing_account_number << " " << existing_name << " " << existing_balance << endl; 
                    log_transaction("Deposit", existing_account_number, deposit_amount);
                }
                else
                {
                    temp_file << existing_account_number << " " << existing_name << " " << existing_balance << endl;
                }
                
            }

            accounts_file.close();
            temp_file.close();
            remove("accounts.txt");
            rename("temp.txt", "accounts.txt");

            cout << "Rs. " << deposit_amount << " deposited successfully!" << endl;  
        }


        /* Withdraws Money */
        void withdraw(int account_number)
        {
            double withdraw_amount;

            ifstream accounts_file_read("accounts.txt");
            ofstream temp_file("temp.txt", ios::app);

            int existing_account_number;
            int existing_balance;
            string existing_name;

            while(accounts_file_read >> existing_account_number >> existing_name >> existing_balance) // Read until EOF
            {
                if(existing_account_number == account_number)   
                {
                    cout << "Enter amount you want to withdraw: ";
                    cin >> withdraw_amount;

                    if (existing_balance >= withdraw_amount)    
                    {
                        existing_balance -= withdraw_amount;
                        temp_file << existing_account_number << " " << existing_name << " " << existing_balance << endl;

                        log_transaction("Withdraw", existing_account_number, withdraw_amount);
                        
                        cout << "Rs. " << withdraw_amount << " debited successfully!" << endl;
                    }

                    else{
                        cout << "Insufficient balance" << endl << endl;
                        temp_file << existing_account_number << " " << existing_name << " " << existing_balance << endl;
                    }
                    
                }

                else
                {
                    temp_file << existing_account_number << " " << existing_name << " " << existing_balance << endl;
                }
            
            }
            accounts_file_read.close();
            temp_file.close();

            remove("accounts.txt");
            rename("temp.txt", "accounts.txt");
        }


        /* Checks Balance in the account */
        void checkBalance(int account_number)
        {
            int existing_account_number;
            int existing_amount;
            string existing_name;

            ifstream accounts_file_read("accounts.txt");
            while (accounts_file_read >> existing_account_number >> existing_name >> existing_amount)
            {
                if (existing_account_number == account_number)
                {
                    cout << "Rs. " << existing_amount;
                    break;
                }
            }
        }


        /* Display Transaction Details*/
        void view_transactionDetails(int account_number)
        {
            ifstream log_file_read("transaction_log.txt");
                 
            if (!log_file_read.is_open())
            {
                cout << "Error while opening the file!!" << endl;
                return;
            }

            bool account_details_found = false;
            string line;
            while(getline(log_file_read, line))
                {
                    istringstream iss(line);
                    int log_account_number;
                    string type;                // withdraw or deposit
                    double log_amount;
                    string garbage_on_word;     // 'On' word in transaction_log.txt file.

                    string day, month, date, time, year;
                    iss >> log_account_number >> type >> log_amount >> garbage_on_word >> day >> month >> date >> time>> year;     // this garbage holds "on" string

                    if (account_number == log_account_number)
                    {
                        cout << "\n";
                        cout << "Account Number: " << log_account_number << endl;
                        cout << "Type: " << type << endl;
                        cout << "Amount: Rs. " << log_amount << endl;
                        cout << "Date: " << day << " " << month << " " << date << " " << year << endl;
                        cout << "Time: " << time << endl ;

                        account_details_found = true;
                    }
                }

                if (!account_details_found)
                {
                    cout << "No Transaction details of this account found" << endl;
                }
        
                log_file_read.close();
            
            }

};      // End of class



int main()
{
    Bank b1;
    int user_input;

    cout << "--------------------------------Welcome to Banking Management System------------------------------------" << "\n\n";
    while (true)
    {   CLEAR_SCREEN();
        cout << "1. Create your account. " << endl;
        cout << "2. Login to your account. " << endl;
        cout << "0. To exit." << endl;

        cout << '\n';
        cout << "Choose your Desired Operation: ";
        cin >> user_input;

        int account_number;
        bool logged_in = true;

        switch (user_input)
        {

            case 0:
                 CLEAR_SCREEN();
                cout << '\n';
                cout << "Thank you for choosing us!!" << endl;
                exit(0);
                break;

            case 1:
                CLEAR_SCREEN();
                account_number = b1.create_account();
                cout << "\n";
                cout << "Your account number is: " << account_number << endl;
                cout << "Keep it safe for accessing banking features!" << endl << endl;
                cout << "Login to deposit money." << endl;
                pressAnyKeyToContinue();
                break;
            
            case 2:
                CLEAR_SCREEN();
                cout << "Enter account number: ";
                cin >> account_number;
                if(b1.login(account_number))
                {
                    while (logged_in)
                    {
                    int user_input_afterLogin;
                    cout << "\n";
                    cout << "1. Deposit to your account. " << endl;
                    cout << "2. To withdraw from your account. " << endl;
                    cout << "3. To check your balance. " << endl;
                    cout << "4. View your transaction details. " << endl;
                    cout << "0. To logout." << endl;

                    cout << "\n";
                    cout << "Enter your desired operation: ";
                    cin >> user_input_afterLogin;

                    switch (user_input_afterLogin)
                    {

                        case 0:
                            CLEAR_SCREEN();
                            cout << "Successfully Logged out!" << endl << endl;
                            logged_in = false;
                            pressAnyKeyToContinue();
                            break;
                        
                        case 1:
                            CLEAR_SCREEN();
                            b1.deposit(account_number);
                            pressAnyKeyToContinue();
                            break;

                        case 2:
                             CLEAR_SCREEN();
                            b1.withdraw(account_number);
                            pressAnyKeyToContinue();
                            break;

                        case 3:
                             CLEAR_SCREEN();
                            b1.checkBalance(account_number);
                            pressAnyKeyToContinue();
                            break;

                        case 4:
                             CLEAR_SCREEN();
                            b1.view_transactionDetails(account_number);
                            pressAnyKeyToContinue();
                            break;

                        default:
                            
                            cout << "Invalid Input! " << endl;
                            break;
                        }

                    }
                    
                }
                break;

            default:
                cout << "Invalid Input! " << endl;
                break;

        }

    }

}
