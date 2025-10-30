#include <iostream>

using namespace std;

class Student{
	private:
		string m_name;
		int m_id;
		double midterm_grade;
		double final_grade;
	public:
		Student(){
			cout << "Object was created!" << endl;
		}
		Student(string name, int ind, double midterm, double final);
		~Student(){
			cout << "Object was destroyed!" << endl;
		}
		double findAverage();
		void printInfos();
};
Student::Student(string name, int id, double midterm, double final){
	m_name = name;
	m_id = id;
	midterm_grade = midterm;
	final_grade = final;
}
double Student::findAverage(){
	double average = midterm_grade * 0.4 + final_grade * 0.6;
	return average;
}
void Student::printInfos(){
	cout << "Student's name : " << m_name << endl;
	cout << "Student's id : " << m_id << endl;
	cout << "Student's midterm grade : " << midterm_grade << endl;
	cout << "Student's final grade : " << final_grade << endl;
	cout << "Student's average : " << findAverage() << endl;
	
	if(findAverage() >= 60){
		cout << "Passed" << endl;
	}
	else{
		cout << "Failed" << endl;
	}
}
int main(){
	string name;
	int id;
	double midterm, final;
	
	cout << "Enter student's name : ";
	getline(cin, name);
	cout << "Enter student's id : ";
	cin >> id;
	cout << "Enter student's midterm grade : ";
	cin >> midterm;
	cout << "Enter student's final grade : ";
	cin >> final;
	
	Student student(name, id, midterm, final);
	student.printInfos();
	
	return 0;
}
