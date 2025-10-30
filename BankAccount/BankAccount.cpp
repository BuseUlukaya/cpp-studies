#include <iostream>

using namespace std;

class BankAccount{
	private:
		string m_owner;
		double m_balance;
	public:
		void setOwner(string owner);
		void setBalance(double balance);
		void withDraw();
		void deposit();
		void printInfos();
	};
	void BankAccount::setOwner(string owner){
		m_owner = owner;
	}
	void BankAccount::setBalance(double balance){
		if(balance < 0){
			cout << "Invalid balance!" << endl;
		}
		m_balance = balance;
	}
	void BankAccount::withDraw(){
		float balance;
		cout << "Enter the balance you want to withdraw : ";
		cin >> balance;
		if(balance > m_balance || balance <= 0){
			cout << "Invalid balance!" << endl;
			return;
		}
		m_balance -= balance;
		cout << "New balance : " << m_balance << endl;
	}
	void BankAccount::deposit(){
		float balance;
		cout << "Enter the balance you want to deposit : ";
		cin >> balance;
		if(balance <= 0){
			cout << "Invalid balance!" << endl;
			return;
		}
		m_balance += balance;
		cout << "New balance : " << m_balance << endl;
	}
	void BankAccount::printInfos(){
		cout << "Owner of account : " << m_owner << endl;
		cout << "Balance : " << m_balance << endl;
	}
	
int main(){
	BankAccount account;
	int choice;
	string name;
	double balance;
	do{
		cout << endl;
		cout << "==============BANK==============" << endl;
		cout << "1. Create account " << endl;
		cout << "2. Withdraw money " << endl;
		cout << "3. Deposit money " << endl;
		cout << "4. Show information of account" << endl;
		cout << "--------------------------------" << endl;
		cout << "0. Exit" << endl << endl;
		
		cout << "Do choice : ";
		cin >> choice;
		cout << endl;
		
		switch(choice){
			case 1:
				cin.ignore();
				cout << "Enter your name : ";
				getline(cin, name);
				cout << "Enter your balance : ";
				cin >> balance;
				account.setOwner(name);
				account.setBalance(balance);
				break;
			case 2:
				account.withDraw();
				break;
			case 3:
				account.deposit();
				break;
			case 4:
				account.printInfos();
				break;
			case 0:
				cout << "Program was finished..." << endl;
				break;
			default:
				cout << "Invalid value!" << endl;
		}
	}while(choice != 0);
	
	return 0;
}
