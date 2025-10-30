#include <iostream>

using namespace std;

class Product{
	private:
		string m_name;
		double m_price;
		double m_discountRate;
		double m_taxRate;
	public:
	Product(){
		cout << "Object was created!" << endl;
	}
	Product(string name, double price, double taxRate);
	Product(double m_price);
	double calculateTotal();
	void printInfos(){
		cout << "Name of product : " << m_name << endl;
		cout << "Price of product : " << m_price << endl;
		cout << "Discount rate of product : " << m_discountRate << endl;
		cout << "Tax rate of product : " << m_taxRate << endl;
		cout << "Total price of product : " << calculateTotal() << endl;
	}
	~Product();
};
Product::Product(string name, double price, double taxRate){
	m_discountRate = 0.05;
	m_name = name;
	m_price = price;
	m_taxRate = taxRate;
}
Product::Product(double price){
	m_name = "Unknown";
	m_price = price;
	m_taxRate = 0.0;
	m_discountRate = 0.0;
}
double Product::calculateTotal(){
	double total = (m_price - m_discountRate) * (1 + m_taxRate);
	return total;
}
Product::~Product(){
	cout << "Object was destroyed!" << endl;
}
int main(){
	Product laptop("laptop", 2000, 0.18);
	Product bread(20);
	
	laptop.printInfos();
	bread.printInfos();
	
	return 0;
	
}
