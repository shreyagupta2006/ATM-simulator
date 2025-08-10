#include<iostream>
#include<vector>
#include<string>
using namespace std;
class ATM {
    private:
    string userPIN ;
    double balance = 10000.0;
    vector<string> history;

    bool validatePIN(){
        string enteredPIN ;
        cout<<"Enter PIN :";
        cin>> enteredPIN;


    
    if (enteredPIN == userPIN){
        return true;
    }
    else{
        cout<<"Invalid PIN\n";
        return false;
    }


    }
    public:
     void setpin(){
        cout<<"Set your 4-digit ATM PIN :";
        cin>>userPIN;
        cout<<"PIN set successfully\n";

     }
     void showMenu(){
        if(!validatePIN()) return;
        int choice;
        do{
            cout<<"\n-----ATM menu---\n";
            cout<<"1.Check Balance\n";
            cout<<"2. Withdraw\n";
            cout<<"3.Deposit\n";
            cout<<"4.Transfer Funds\n";
            cout<<"5. Transaction History\n";
            cout<<"6. Exit\n";
            cout<<"Enter your choice";
            cin>>choice;
            switch(choice){
            case 1: checkBalance();
            break;
            case 2: withdraw();
            break;
            case 3: deposit();
            break;
            case 4: transfer();
            break;
            case 5: showHistory();
            break;
            case 6: cout<<"Thank you for using the ATM.\n";
            break;
            default:
            cout<<"Invalid choice!\n";
        }
    }
    
        while(choice !=6);
    }

    
    void checkBalance(){
        cout<<"Current Balance : Rs."<<balance<<endl;
        history.push_back("Checked balance");
    }
    void withdraw(){
        double amount;
        cout<<"Enter amount to withdraw Rs.";
        cin>>amount;
        if (amount <= balance && amount >0){
            balance -= amount;
            cout<<"Withdrawl successful.Remaining balance : Rs"<<balance<<endl;
            history.push_back("withdrew Rs." + to_string(amount));
         }
         else{
            cout<<"Insufficient funds or invalid number\n";
         }
        }
        void deposit(){
            double amount;
            cout<<"Enter amount to deposit : Rs.";
            cin>>amount;
        
        if(amount>0){
            balance += amount;
            cout<<"Deposit successful.New balance : Rs."<<balance<<endl;
            history.push_back("Deposited Rs." + to_string(amount));
        }
        else{
            cout<<"Invalid deposit amount!\n";
        }
    }
    void transfer(){
        double amount;
        string accountNumber;
        cout<<"Enter account number to transfer : Rs.";
        cin>>amount;
        if(amount <= balance && amount>0){
            balance -= amount;
            cout<<"Transferred Rs."<<amount<<"to account" + accountNumber;
        }
        else{
            cout<<"Transfer failed : insufficient funds or invalid amount!\n";


        }
    }
    void showHistory(){

        cout<<"\n ===== Transaction History =====\n";
        if (history.empty()){
            cout<<"No Transaction yet,\n";
        }
        else{
            for( const string& h : history){
                cout<<"- "<<h<<endl;
            }
        }
        }
    };
    
    
    
    int main(){
        ATM atm;
        atm.setpin();
        atm.showMenu();
        return 0;
    }




    

        
