#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "ex2.h"
using namespace std;

bool Customer :: set_name(string n)
{
    name = n;
    return true;
}

bool Customer :: set_username(string n)
{
    set_name(n);                               //Finds the find function of the sign :
    username = name.substr(0, name.find(':')); //and separates the substar function from the beginning of the string to before the sign : 
    return true;                               //and drops it in the username variable
}

bool Customer :: set_ip(string n)
{
    int num;
    string ip1;
    string ip2;
    string ip3;
    string ip4;
    string ip5;
    string ip6;
    string ip7;
    set_name(n);                          

                                            //Finds the find function of the sign :
    ip3 = name.substr(name.find(':') + 1);  //and the substar function finds one after the sign : separates it to the end of the string
    //cout << "ip3 : " << ip3 << endl;        //and drops it into the ip variabl

    ip1 = ip3.substr(0, ip3.find('.'));
    //cout << "ip1 : " << ip1 << endl;
    num = stoi(ip1);
    if (num > 255)
    {
        puts(" ");
        cout << "Not valid IP!!!" << endl;
        return false;
    }

    ip2 = ip3.substr(ip3.find('.') + 1);
    //cout << "ip2 : " << ip2 << endl;
    ip4 = ip2.substr(0, ip2.find('.'));
    //cout << "ip4 : " << ip4 << endl;
    num = stoi(ip4);
    if (num > 255)
    {
        puts(" ");
        cout << "Not valid IP!!!" << endl;
        return false;
    }

    ip5 = ip2.substr(ip2.find('.') + 1);
    //cout << "ip5 : " << ip5 << endl;
    ip6 = ip5.substr(0, ip5.find('.'));
    //cout << "ip6 : " << ip6 << endl;
    num = stoi(ip6);
    if (num > 255)
    {
        puts(" ");
        cout << "Not valid IP!!!" << endl;
        return false;
    }

    ip7 = ip5.substr(ip5.find('.') + 1);
    //cout << "ip7 : " << ip7 << endl;
    num = stoi(ip7);
    if (num > 255)
    {
        puts(" ");
        cout << "Not valid IP!!!" << endl;
        return false;
    }
    ip = name.substr(name.find(':') + 1);                      
    return true;                                             
}

bool Customer :: set_account_opening_data()
{
    time_t t = time(0);                   // get time now
    tm* now = localtime(&t);
    year_opening = now->tm_year + 1900;
    month_opening = now->tm_mon + 1;
    day_opening = now->tm_mday;
    return true;
}

bool Customer :: set_account_expiration_data()
{
    set_account_opening_data();
    year_expiration = year_opening + 2;   //The expiration date of the account is two years after the opening of the account
    return true;
}

bool Customer :: set_account_number()
{
    srand(static_cast <unsigned int> (time(0)));
    account_number = rand() % 999 + 1000;             //Build a 4-digit Randome number      
    return true;
}

bool Customer :: set_balance()
{
    balance = 0;
    return true;
}

bool Customer :: set_debt()
{
    debt = 0;
    return true;
}

bool Customer :: set_loann()
{
    loann = 0;
    return true;
}

int Customer :: get_balance()
{
    return balance;
}


int Customer :: get_account_number() 
{
    return account_number;
}

int Customer :: get_account_expiration_data() 
{
    return year_expiration;
}

int Customer :: get_account_opening_data()
{
    return year_opening;
}

string Customer :: get_ip() 
{
    return ip;
}


string Customer :: get_username() 
{
    return username;
}

long double Customer :: get_debt()
{
    return debt;
}

long double Customer :: get_loann()
{
    return loann;
}