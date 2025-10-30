#include <iostream>

using namespace std;

class Customer{
	private:
		string m_name;
		double m_price;
		int purchase_type;
	public:
		void setInfos(string name, double price, int type);
		void calculatePrice();
};
void Customer::setInfos(string name, double price, int type){
	m_name = name;
	m_price = price;
	purchase_type = type;
}
void Customer::calculatePrice(){
	double temp = m_price;
	switch(purchase_type){
		case 1:
			temp = temp * 0.7;
			cout << "Amount to be paid : " << temp;
			break;
		case 2:
			temp = temp * 0.8;
			cout << "Amount to be paid : " << temp;
			break;
		case 3:
			cout << "Amount to be paid : " << temp;
			break;
		default:
			cout << "Invalid choice!" << endl << endl;
	}
}

int main(){
	string name;
	double price;
	int type;
	int choice;
	Customer customer;
	
	cout << "Please enter your name : ";
	getline(cin,name);
	cout << endl;

	cout << "=======PRODUCT LIST=======" << endl;
	cout << "1. Laptop = 18.000 TL" << endl;
	cout << "2. Smartphone = 12.000 TL" << endl;
	cout << "3. Tablet = 8.000 TL " << endl;
	cout << "4. Headphones = 2.000 TL" << endl;
	cout << "5. Smartwatch = 3.500 TL" << endl << endl;
	
	cout << "Do choice : ";
	cin >> choice;
	cout << endl;
	
	switch(choice){
		case 1:
			price = 18000;
			break;
		case 2:
			price = 12000;
			break;
		case 3:
			price = 8000;
			break;
		case 4:
			price = 2000;
			break;
		case 5:
			price = 3500;
			break;
		default:
			cout << "Invalid choice!" << endl;
	}
	
	cout << "===========Types of Payment============" << endl;
	cout << "1. Paying in cash = 30% discount" << endl;
	cout << "2. Paying by credit card = 20% discount" << endl;
	cout << "3. Instalment payment = original price" << endl << endl;
	
	cout << "Do choice : ";
	cin >> type;
	cout << endl;
	
	customer.setInfos(name, price, type);
	customer.calculatePrice();
	
	return 0;

}
