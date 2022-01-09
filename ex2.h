#include <iostream>
#include <string>
#include <vector>

#ifndef ex2_h
#define ex2_h

using namespace std;

struct IP
{
    string username;
    vector <vector<string>> ip;
};

class Customer
{
    friend vector <Customer> deposit (vector <Customer> & cus);
    friend vector <Customer> transfer (vector <Customer> & cus);
    friend vector <Customer> withdraw (vector <Customer> & cus);
    friend void showCustomer (vector <Customer> cus);
    friend void bank (vector <Customer> cus);
    friend vector <Customer> renewal (vector <Customer> & cus);
    friend vector <Customer> getLoan (vector <Customer> & cus);
    friend long double Inventory (vector <Customer> cus);
    friend vector <Customer> payLoan (vector <Customer> & cus);
    friend vector <Customer> create (vector <Customer> & cus);

    public :
        bool set_name(string n);
        bool set_username(string n);
        bool set_ip(string n);
        bool set_account_opening_data();
        bool set_account_expiration_data();
        bool set_account_number();
        bool set_balance();
        bool set_debt();
        bool set_loann();
        int get_account_number();
        string get_ip();
        string get_username();
        int get_account_opening_data();
        int get_account_expiration_data();
        int get_balance();
        long double get_debt();
        long double get_loann();

    private :
        string name;
        string username;
        int account_number;
        long double balance;
        string ip;
        int year_opening;
        int month_opening;
        int day_opening;
        int year_expiration;
        long double debt;
        long double loann;
};


#endif
