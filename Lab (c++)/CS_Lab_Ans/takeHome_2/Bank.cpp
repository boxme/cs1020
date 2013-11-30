#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class bankaccount
{
private:
    string username;
    double bal;
    
public:
    void create(string name, double interest, double mth, double amt)
    {
        username = name;
        bal = amt + (amt * (interest/100.00) * (mth/12.00));
    }
    
    void withdraw(string name, double amt)
    {
        bal -= amt;
    }
    
    void deposit(string name, double amt)
    {
        bal += amt;
    }
    
    string getname () {return username;}
    double getbal () {return bal;}
};

int main ()
{
    double interest = 0.00;
    double mth = 0.00;
    string action = "";
    string name = "";
    double amt = 0.00;
    
    int i = 0;
    int j = 0;
    
    bankaccount acct[100];
    
    cin >> interest >> mth;
    while (cin >> action) {
        
        if (action == "0") {
            break;
        }
        
        cin >> name >> amt;
        
        if (action == "Create") {
            acct[i].create(name, interest, mth, amt);
            i++;
        }
        
        if (action == "Withdraw") {
            for (j = 0; j < i; j++) {
                if (acct[j].getname() == name) {
                    acct[j].withdraw(name, amt);
                    break;
                }
            }
        }
        
        if (action == "Deposit") {
            for (j = 0; j < i; j++) {
                if (acct[j].getname() == name) {
                    acct[j].deposit(name, amt);
                    break;
                }
            }
        }
    }
    
    cout << i << endl;
    j = 0;
    while (j < i) {
        printf("%s %.2f", acct[j].getname().c_str(), acct[j].getbal());
        cout << endl;
        j++;
    }
    
}