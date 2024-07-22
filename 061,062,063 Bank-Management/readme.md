# Banking Management System

This project implements a simple banking management system in C++ using Object-Oriented Programming (OOP) concepts. It allows users to create accounts, log in, deposit money, withdraw money, check their balance, and view transaction details.

## Contributors

-Shishir Pandeya (062) [@Shishir120](https://www.github.com/Shishir120) \
-Shekhar Gyawali (061) [@SuperShekhar](https://www.github.com/SuperShekhar) \
-Shraya Ranjit (063) 

## Features

- **Create Account**: Allows a user to create a new account with a unique account number and a 4-digit PIN.
- **Login**: Authenticate users based on their account number and PIN.
- **Deposit Money**: Users can deposit money into their account.
- **Withdraw Money**: Users can withdraw money from their account, provided they have sufficient balance.
- **Check Balance**: Users can check the current balance of their account.
- **View Transaction Details**: Users can view the details of all transactions (deposits and withdrawals) made from their account.

## Files Used

- **accounts.txt**: Stores account details in the format `account_number name balance`.
- **authentication.txt**: Stores account numbers and corresponding PIN codes.
- **transaction_log.txt**: Stores transaction logs in the format `account_number type amount on datetime`.

## Class and Methods

### Class `Bank`

#### Methods:

1. **string get_current_time()**
   - Returns the current date and time as a string.

2. **bool user_authentication(int account_number, int pin_code)**
   - Authenticates the user by checking the account number and PIN from `authentication.txt`.

3. **string display_name_afterLogin(int account_number)**
   - Returns the name of the user based on the account number from `accounts.txt`.

4. **bool login(int account_number)**
   - Handles the login process for the user. Prompts for PIN and authenticates the user.

5. **bool account_exits(int account_number, const string& check_which_file)**
   - Checks if an account with the given account number exists in the specified file (`accounts.txt` or `authentication.txt`).

6. **void log_transaction(const string& type, int account_number, double transaction_amount)**
   - Logs transaction details (type, amount, date, and time) into `transaction_log.txt`.

7. **int generate_account_number()**
   - Generates a unique account number for a new account.

8. **int create_pin()**
   - Prompts the user to create a 4-digit PIN for the new account.

9. **int create_account()**
   - Creates a new account and writes the details to `accounts.txt` and `authentication.txt`.

10. **void deposit(int account_number)**
    - Deposits money into the user's account and updates the balance.

11. **void withdraw(int account_number)**
    - Withdraws money from the user's account if the balance is sufficient.

12. **void checkBalance(int account_number)**
    - Displays the current balance of the user's account.

13. **void view_transactionDetails(int account_number)**
    - Displays the transaction details (deposits and withdrawals) for the user's account.

### Helper Functions:

- **void pressAnyKeyToContinue()**
  - Prompts the user to press Enter to continue.

## How to Use

1. Clone the repository to your local machine.

2. Compile the program using a C++ compiler.

3. Run the executable:
   ./banking_management_system

4. Follow the on-screen prompts to create an account, log in, deposit money, withdraw money, check your       balance, or view transaction details.

## Notes:
- Ensure that the necessary files (accounts.txt, authentication.txt, and transaction_log.txt) are in the same directory as the executable.
- The program will create these files if they do not exist.
- Make sure to handle file operations and error checking appropriately in a real-world application.
