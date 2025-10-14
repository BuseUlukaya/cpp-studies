#include <iostream>
#include <string>

using namespace std;

class Account{
	int balance;
	string ownerName;
	public:
		void initialize(int n, string s);
		int check(){
			return balance;
		}
		void witdraw(int);
		void deposit(int);
};

void Account::initialize(int n, string s){
	balance = n;
	ownerName = s;
}

void Account::witdraw(int n){
	if(balance > n){
		balance -= n;
	}
	else{
		cout << "Not enough money" << endl;
	}
}

void Account::deposit(int n){
	if(n > 0){
		balance += n;
	}
	else{
		cout << "Please enter valid money" << endl;
	}
}

int main(){
	int amount;
	char choice;
	string name;
	Account obje;
	
	do{
		cout << "MENU" << endl;
		cout << "I. Initialize" << endl;
		cout << "W. Witdraw" << endl;
		cout << "D. Deposit" << endl;
		cout << "C. Check" << endl;
		cout << "E. Exit" << endl << endl;
		
		cout << "Do choice : ";
		cin >> choice;
		
		switch(choice){
			case 'I':
				cout << "Enter amount : ";
				cin >> amount;
				cout << "Enter name : ";
				cin >> name;
				cout << endl;
				obje.initialize(amount, name);
				break;
			case 'W':
				cout << "Enter amaunt: ";
				cin >> amount;
				obje.witdraw(amount);
				cout << endl;
				break;
			case 'D':
				cout << "Enter amaunt: ";
				cin >> amount;
				obje.deposit(amount);
				cout << endl;
				break;
			case 'C':
				cout << obje.check() << endl;
				cout << endl;
				break;
			case 'E':
				cout << "Program finished" << endl;
				break;
			default:
				cout << "Please do valid choice" << endl;
				cout << endl;
		}
	}while(choice != 'E');
	
	return 0;
	
}
