#include <iostream>
#include <string>
#include <vector>
#include "ex2.h"

using namespace std;

static int count = 0;                    //Number of people who opened a bank account
static int bankruptcy = 0;


void Menu ()
{
    puts(" ");
    cout
    << "To open an account [create] \n"
    << "To renew the account [renewal] \n"
    << "To deposit [deposit] \n"
    << "To transfer [transfer] \n"
    << "To withdraw [withdraw] \n"
    << "To display account information [show_customer] \n"
    << "To apply for a loan [get_loan] \n"
    << "To repay the loan [pay_loan] \n"
    << "To display bank information [bank] \n"
    << "To exit [exit] \n";
    cout << "Enter a command : ";
}

vector <Customer> create (vector <Customer> & cus)              //Function to open an account
{
    int temp = 1;

    if (bankruptcy == 1)
    {
        cout << "The bank has gone bankrupt" << endl;
    }

    Customer c;
    puts(" ");
    cout << "Enter username and ip as follows (Hanie:12.38.124.3)" << endl;
    cout << "Your username should not start with a number" << endl;
    cout << "===> ";
    string n;
    cin >> n;
    c.set_name(n);
    c.set_username(n);
    c.set_ip(n);
    c.set_account_opening_data();
    c.set_account_expiration_data();
    c.set_account_number();
    c.set_balance();
    c.set_debt();
    c.set_loann();

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].account_number == c.get_account_number())
        {
            c.set_account_number();
        }  
    }

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == c.get_username())
        {
            temp = 0;
        }  
    }
    
    if (c.set_ip(n) == true && temp == 1)       
    {
        cus.push_back(c);
        count++;                      //Add one person to the number of people who have opened an account in the bank
    }
    else
    {
        puts(" ");
        cout << "Try again!!!" << endl;
    }
    
    return cus;
}

vector <Customer> renewal (vector <Customer> & cus)              //Function for account renewal
{
    int temp = 0;
    string str;
    string username1;
    string ip1;
    puts(" ");
    cout << "Enter the username and IP as follows (Hanie:12.38.124.3)" << endl;
    cout << "===> ";
    cin >> str;

    username1 = str.substr(0, str.find(':'));           //Separate username and IP
    str = str.substr(str.find(':') + 1);
    ip1 = str.substr(0, str.find(':'));

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == username1)
        {
            if (cus[i].balance < 1)     //The cost of renewing the account is one dollar. 
            {                           //If the user does not have enough money to pay, he will be warned
                temp = 1;
                puts(" ");
                cout << "There is not enough money in the account!!!" << endl;
                puts(" ");
                break;
            }
            temp = 1;
            cus[i].year_expiration = cus[i].year_expiration + 1;   //If the balance is enough, one dollar will be deducted from the user account
            cus[i].balance = cus[i].balance - 1;                   //and the user account will be renewed for one year
        }
    }

    if (temp == 0)
    {
        puts(" ");
        cout << "There is no account with this username!!!" << endl;   
        puts(" ");
    }
    return cus;
}                                                         

void show (vector <Customer> cus)                               //A function to display customer information
{
    puts(" ");

    for (size_t i = 0; i < cus.size(); i++)
    {
        cout << "Username : " << cus[i].get_username() << endl;
        cout << "IP : " << cus[i].get_ip() << endl;
        cout << "Account opening data : " << cus[i].get_account_opening_data() << endl;
        cout << "Account expiration data : " << cus[i].get_account_expiration_data() << endl;
        cout << "Account number : " << cus[i].get_account_number() << endl;
        cout << "Balance : " << cus[i].get_balance() << " $" << endl;
    } 
    cout << "-----------------------------------------------------" << endl;
    cout << "Number of people who opened a bank account : " << count << endl;
    cout << "-----------------------------------------------------" << endl;
    puts(" "); 
}

vector <Customer> deposit (vector <Customer> & cus)         //Function to deposit to the account
{
    int temp = 0;
    string str;
    string ip1;
    string username1;
    string deposit;
    long double deposit1;
    puts(" ");
    cout << "Enter the username and IP and the deposit amount as follows (Hanie:12.38.124.3:20000)" << endl;
    cout << "===> ";
    cin >> str;
    
    username1 = str.substr(0, str.find(':'));       //Separate username and IP and money
    str = str.substr(str.find(':') + 1);
    ip1 = str.substr(0, str.find(':'));
    deposit = str.substr(str.find(':') + 1);
    
    deposit1 = stoi(deposit);                     //Convert string to number

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == username1)
        {
            temp = 1;
            cus[i].balance =  cus[i].balance + deposit1;       //If a username is found, money will be added to the user's account
        }
    }

    if (temp == 0)
    {
        puts(" ");
        cout << "There is no account with this username!!!" << endl;
        puts(" ");
    }
    
    return cus;
}

vector <Customer> transfer (vector <Customer> & cus)         //A function for transferring money
{
    int sender_temp = 0;
    int receiver_temp = 0;
    string str;
    string sender_ip1;
    string sender_username1;
    string receiver_username1;
    string money1;
    long double money;
    puts(" ");
    cout << "Enter the sender username, sender IP, receiver username and money (Hanie:12.38.124.3:Ali:20000)" << endl;
    cout << "===> ";
    cin >> str;
    
    sender_username1 = str.substr(0, str.find(':'));   //Separate username and sender's username and recipient username and money
    str = str.substr(str.find(':') + 1);
    sender_ip1 = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);
    receiver_username1 = str.substr(0, str.find(':'));
    money1 = str.substr(str.find(':') + 1);
    
    money = stoi(money1);                                  //Convert string to number

    for (size_t i = 0; i < cus.size(); i++)            
    {
        if (cus[i].username == sender_username1)           //First, the sender and recipient both have opened an account in the bank
        {
            sender_temp = 1;                            
        }
        if (cus[i].username == receiver_username1)
        {
            receiver_temp = 1;
        } 
    }

    if (sender_temp == 0)
    {
        puts(" ");
        cout << "There is no account with this sender_username!!!" << endl;
        puts(" ");
    }
    else if (receiver_temp == 0)
    {
        puts(" ");
        cout << "There is no account with this receiver_username!!!" << endl;
        puts(" ");
    }

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == sender_username1)
        {
            if (cus[i].balance < money)
            {
                puts(" ");
                cout << "There is not enough money in the account!!!" << endl;
                puts(" ");
                break;
            }
            
            cus[i].balance = cus[i].balance - money;           //Money is deducted from the sender's account
        }
    }

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == receiver_username1)
        {
            cus[i].balance = cus[i].balance + money;         //Money is added to the recipient's account
        }
    }

    return cus;
}

vector <Customer> withdraw (vector <Customer> & cus)         //Function for withdrawal from the account
{
    int temp = 0;
    string str;
    string ip1;
    string username1;
    string money;
    long double money1;
    long double total;
    puts(" ");
    cout << "Enter the username and IP and money as follows (Hanie:12.38.124.3:20000)" << endl;
    cout << "===> ";
    cin >> str;
    
    username1 = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);
    ip1 = str.substr(0, str.find(':'));
    money = str.substr(str.find(':') + 1);
    
    money1 = stoi(money);
    
    total = Inventory(cus);                 //Total bank balance    

    if (money1 > total)                      
    {
        puts(" ");
        cout << "The bank has gone bankrupt :( " << endl;
        bankruptcy = 1;
    }
    
    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == username1)
        {
            temp = 1;

            if (cus[i].debt != 0)        //If the user has debts, she/he is not allowed to withdraw
            {
                puts(" ");
                cout << "You will not be able to withdraw from your account due to debt!!!" << endl;   
                break;     
            }
            
            if (cus[i].balance < money1)
            {
                cout << "There is not enough money in the account!!!" << endl;   
                break;             
            }
            cus[i].balance = cus[i].balance - money1;                  //Money is deducted from the user's account
        }
    }

    if (temp == 0)
    {
        puts(" ");
        cout << "There is no account with this username!!!" << endl;
        puts(" ");
    }
    
    return cus;
}

long double Inventory (vector <Customer> cus)   //A function for calculating the total bank balance
{
    long double money = 0;
    long double loan = 0;
    for (size_t i = 0; i < cus.size(); i++)
    {
        money = money + cus[i].balance;
        loan = loan + cus[i].loann;
    }
    money = money - loan;
    return money;
}

vector <Customer> getLoan (vector <Customer> & cus)
{
    int temp = 0;
    string str;
    string ip1;
    string username1;
    string money;
    long double money1;
    long double inventory = 0;
    puts(" ");
    cout << "Enter the username and IP and money as follows (Hanie:12.38.124.3:20000)" << endl;
    cout << "===> ";
    cin >> str;
    
    username1 = str.substr(0, str.find(':'));
    str = str.substr(str.find(':') + 1);
    ip1 = str.substr(0, str.find(':'));
    money = str.substr(str.find(':') + 1);
    
    money1 = stoi(money);

    inventory = Inventory(cus);          //Total bank balance

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == username1)
        {
            temp = 1;
            if (cus[i].balance < 3 / 4 * money1 && inventory < money1)
            {
                puts(" ");
                cout << "To receive a loan, you must have at least 3/4 of the loan amount in your account and the bank does not have enough balance to repay the loan!!!" << endl;   
                break;             
            }
            if (cus[i].balance < 3 / 4 * money1)
            {
                puts(" ");
                cout << "To receive a loan, you must have at least 3/4 of the loan amount in your account!!!" << endl;   
                break;             
            }
            if (inventory < money1)
            {
                puts(" ");
                cout << "The bank does not have enough balance to repay the loan!!!" << endl;   
                break;  
            }
            
            cus[i].loann = cus[i].loann + money1;
            cus[i].debt = money1 / 10 + money1;       //The loan amount plus ten percent interest is added to the user's debt
        }
    }

    if (temp == 0)
    {
        puts(" ");
        cout << "There is no account with this username!!!" << endl;
        puts(" ");
    }

    return cus;
}

vector <Customer> payLoan (vector <Customer> & cus)
{
    int temp = 0;
    string str;
    string username1;
    string money1;
    long double money;
    long double n;
    puts(" ");
    cout << "Enter the username and IP as follows (Hanie:200)" << endl;
    cout << "===> ";
    cin >> str;
    
    username1 = str.substr(0, str.find(':'));           //Separate username and IP
    str = str.substr(str.find(':') + 1);
    money1 = str.substr(0, str.find(':'));

    money = stoi(money1);

    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].username == username1)
        {
            temp = 1;
            if (money > cus[i].debt)
            {
                n = money - cus[i].debt;
                cus[i].balance = cus[i].balance + n;
                cus[i].debt = 0;
                cus[i].loann = 0;
                break;
            }
            else
            {
                cus[i]. debt = cus[i].debt - money;
                if (money > cus[i].loann)
                {
                    cus[i].loann = 0;
                }
                else
                {
                    cus[i].loann = cus[i].loann - money;
                }
            }
        }
    }

    if (temp == 0)
    {
        puts(" ");
        cout << "There is no account with this username!!!" << endl;
        puts(" ");
    }

    return cus;
}

void showCustomer (vector <Customer> cus)                               
{
    puts(" ");

    string str;
    cout << "Enter a IP or username ===> ";
    cin >> str;


    for (size_t i = 0; i < cus.size(); i++)
    {
        if (cus[i].ip == str || cus[i].username == str)
        {    
            puts(" ");   
            cout << "-----------------------------------------------------" << endl;
            cout << "Username : " << cus[i].get_username() << endl;
            cout << "IP : " << cus[i].get_ip() << endl;
            cout << "Account opening data : " << cus[i].get_account_opening_data() << endl;
            cout << "Account expiration data : " << cus[i].get_account_expiration_data() << endl;
            cout << "Account number : " << cus[i].get_account_number() << endl;
            cout << "Balance : " << cus[i].get_balance() << " $" << endl;
            cout << "Debt : " << cus[i].get_debt() << " $" << endl;
            cout << "Loan : " << cus[i].get_loann() << " $" << endl;
            cout << "-----------------------------------------------------" << endl;
            break;
        }
    } 
    puts(" "); 
}

void bank (vector <Customer> cus)                   //Display bank information
{
    long double money = 0;
    long double loan = 0;
    for (size_t i = 0; i < cus.size(); i++)
    {
        money = money + cus[i].balance;
        loan = loan + cus[i].loann;
    }
    money = money - loan;
    cout << "-----------------------------------------------------" << endl;
    cout << "Total bank balance : " << money << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Number of people who opened a bank account : " << count << endl;
    cout << "-----------------------------------------------------" << endl;
}

int main()
{
    vector <Customer> cus;
    Customer c;
    string command;
    string n;
    Menu();
    while (true)
    {
        cin >> command;

        if (command == "create")
        {
            system ("clear");
            create(cus);
        }
        if (command == "show")
        {
            system ("clear");
            show(cus);
        }
        if (command == "deposit")
        {
            system ("clear");
            deposit(cus);
        } 
        if (command == "renewal")
        {
            system ("clear");
            renewal(cus);
        } 
        if (command == "transfer")
        {
            system ("clear");
            transfer(cus);
        }
        if (command == "withdraw")
        {
            system ("clear");
            withdraw(cus);
        }
        if (command == "show_customer")
        {
            system ("clear");
            showCustomer(cus);
        }
        if (command == "bank")
        {
            system ("clear");
            bank(cus);
        }
        if (command == "get_loan")
        {
            system ("clear");
            getLoan(cus);
        }
        if (command == "pay_loan")
        {
            system ("clear");
            payLoan(cus);
        }
        if (command == "exit")
        {
            exit(0);
        }
        Menu();
    }    
}