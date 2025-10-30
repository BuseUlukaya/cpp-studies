#include <iostream>

using namespace std;

class Rectangle{
	private:
		double m_width;
		double m_height;
	public:
		void setWidth(double width);
		void setHeight(double height);
		double area();
		double perimeter();
};
void Rectangle::setWidth(double width){
	if(width <= 0.0){
		m_width = 1.0;
	}
	else{
		m_width = width;
	}
}
void Rectangle::setHeight(double height){
	if(height <= 0.0){
		m_height = 1.0;
	}
	else{
		m_height = height;
	}
}
double Rectangle::area(){
	double area = m_width * m_height;
	return area;
}
double Rectangle::perimeter(){
	double perimeter = (m_width + m_height) * 2;
	return perimeter;
}
int main(){
	Rectangle r1, r2;
	double height_one, width_one, height_two, width_two;
	
	cout << "Enter height of r1 : ";
	cin >> height_one;
	cout << "Enter width of r1 : ";
	cin >> width_one;
	cout << endl;
	
	r1.setWidth(width_one);
	r1.setHeight(height_one);
	
	cout << "Area of r1 : " << r1.area() << endl;
	cout << "Perimeter of r1 : " << r1.perimeter() << endl << endl;
	
	cout << "Enter height of r2 : ";
	cin >> height_two;
	cout << "Enter width of r2 : ";
	cin >> width_two;
	cout << endl;
	
	r2.setWidth(width_two);
	r2.setHeight(height_two);
	
	cout << "Area of r2 : " << r2.area() << endl;
	cout << "Perimeter of r2 : " << r2.perimeter() << endl << endl;
	
	return 0;
}
