#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int increment = 0;

class Account
{
public:
    int numberAccount = 1;
    string firstName;
    string lastName;
    string age;
    string typeAccount;
    int firstDeposit;

    Account()
    {
        numberAccount = numberAccount + increment;
    }
};

vector<Account> vectorAccount;

struct Bank
{
    void showMenu()
    {
        cout << "            Options              " << endl;
        cout << "   (1) Open New Account " << endl;
        cout << "   (2) Deposit Money    " << endl;
        cout << "   (3) WithDraw Money   " << endl;
        cout << "   (4) Display Account  " << endl;
        cout << "   (5) Exit             " << endl;
    }

    void openAccount()
    {
        cout << "    Creating Account   " << endl; //<< endl;

        int accountInt;
        Account account;

        cout << "  * Enter Your First Name : "; //<< endl;
        cin >> account.firstName;
        cin.clear();
        cout << endl;

        cout << "  * Enter Your Last Name : "; //<< endl;
        cin >> account.lastName;
        cin.clear();
        cout << endl;

        cout << "  * Enter Your Age : "; //<< endl;
        cin >> account.age;
        cin.clear();
        cout << endl;

        int accountType;
        do
        {
            cout << "  * Enter Account type (1) Checking Account, (2) Saving Account : "; //<< endl;
            cin >> accountType;
            cin.clear();
            cout << endl;
        } while (accountType != 1 && accountType != 2);

        if (accountType == 1)
        {
            account.typeAccount = "Checking Account";
        }

        else
        {
            account.typeAccount = "Saving Account";
        }

        cout << "  * Enter Amount Of First Deposit : "; //<< endl;
        cin >> account.firstDeposit;
        cin.clear();
        cout << endl;

        cout << endl
             << "  Account Created!" << endl
             << endl;

        increment++;

        vectorAccount.push_back(account);
    }

    void depositMoney()
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl
                 << endl;
            return;
        }

        cout << "      Deposit Portal    " << endl;

        int numberAccount;
        int depo;

        cout << "Account Number To Deposit : ";
        cin >> numberAccount;
        cin.clear();

        cout << "Amount To Deposit : ";
        cin >> depo;
        cin.clear();

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            if (vectorAccount[i].numberAccount == numberAccount)
            {
                vectorAccount[i].firstDeposit = vectorAccount[i].firstDeposit + depo;
            }
        }

        cout << "Succesfully Deposit!";
        cout << endl
             << endl;
    }

    void displayAccount()
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl
                 << endl;
            return;
        }

        cout << "     Display Account    " << endl;

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            cout << "Account : " << i + 1 << endl;
            cout << "Account Number : " << vectorAccount[i].numberAccount << endl;
            cout << "First Name : " << vectorAccount[i].firstName << endl;
            cout << "Last Name : " << vectorAccount[i].lastName << endl;
            cout << "Age : " << vectorAccount[i].age << endl;
            cout << "Type Account : " << vectorAccount[i].typeAccount << endl;
            cout << "Account Balance : " << vectorAccount[i].firstDeposit << endl
                 << endl;
        }
    }
    void WithdrawMoney()
    {
        if (vectorAccount.size() == 0)
        {
            cout << "No Account Created." << endl
                 << endl;
            return;
        }

        int numberAccount;
        int amount;

        cout << "Account Number To Withdraw : ";
        cin >> numberAccount;
        cin.clear();

        cout << "Amount To Withdraw : ";
        cin >> amount;
        cin.clear();

        for (int i = 0; i < vectorAccount.size(); i++)
        {
            if (vectorAccount[i].numberAccount == numberAccount)
            {
                vectorAccount[i].firstDeposit = vectorAccount[i].firstDeposit - amount;
            }
            cout << endl
                 << endl;
        }

        cout << "Withdrawal Resquest Succesful!";
        cout << endl
             << endl;
    }
};

int main()
{

    int optionChoice = 0;
    Bank system;

    system.showMenu();
    cout << endl
         << endl
         << "  Please Choose An Option : "; //<< endl;

    do
    {
        cin >> optionChoice;

        switch (optionChoice)
        {
        case 1:
            system.openAccount();
            break;
        case 2:
            system.depositMoney();
            break;
        case 3:
            system.WithdrawMoney();
            break;
        case 4:
            system.displayAccount();
            break;
        }
        system.showMenu();
        cout << endl
             << endl
             << "  Please Choose An Option : "; //<< endl
                                                //<< endl
                                                //<< endl;
    } while (optionChoice != 5);
}