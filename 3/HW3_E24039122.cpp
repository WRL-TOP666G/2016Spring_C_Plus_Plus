#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include <iostream>

using namespace std;

class Account {

        double balance;    //���䥭��
    public:
        Account(){}
        Account(double); //�Nbalance�]���Ƕi�h����
        double  credit(double cash){return (balance-cash);}	   //�N�Ƕi�h���Ȧs�J�æ^��balance
        double	debit(double cash) {return (balance+cash);}      //������B�æ^��balance
        double	getBalance(){cout<<balance<<endl;}      //�^��balance
};



Account::Account(double money){
    balance=money;
}





class SavingsAccount: public Account{

    public:

        SavingsAccount(){}
        SavingsAccount(double Money,double Rate):Account(){
            interestRate=Rate;
            Total=Money*calculateinterest();
            }
        double	calculateinterest(){return (1+interestRate);}
        double  getTotal(){return Total;}
    private:
        double interestRate;               //�Q�v
        double Total;
};




class CheckingAccount: public Account{

    public:
        CheckingAccount(double Money,double fee):Account(){
            balance=Money;
            chargeFee=fee;

            }
        double	credit(double cash){return (-chargeFee-cash);}	//�N���s�J�æ^��balance
        double	debit(double cash) {return (-chargeFee+cash);}	//������B�æҼ{����O�A��^��balance
    private:
        double chargeFee;         		//����O
        double balance;


};




int main(){
    double money;
    double cash;
    double a,b;
    double rate;
    double fee;

    cout<<"Input your money:";
    cin>>money;
    cout<<"Input your cash to deposit your money:";
    cin>>cash;
    Account acc1(money);
    cout<<"credit:"<<acc1.credit(cash)<<endl;
    cout<<"debit:"<<acc1.debit(cash)<<endl;
    cout<<"Your balance:";
    acc1.getBalance();

    cout<<"Input your interest rate:";
    cin>>rate;
    SavingsAccount acc2(money,rate);
    cout<<"Show the SavingMoney:";
    cout<<acc2.getTotal()<<endl;

    cout<<"Input fee:";
    cin>>fee;
    CheckingAccount acc3(money,fee);
    cout<<"After the charge fee be used"<<endl;
    cout<<"credit:"<<acc3.credit(cash)+money*(1+rate)<<endl;
    cout<<"debit:"<<acc3.debit(cash)+money*(1+rate)<<endl;
}

