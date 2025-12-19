#include <iostream>
#include <string>

using namespace std;

class Employee{
    private:
        int id;
        string name;
        string department;
        int work_hours;
        float salary;
    public:
        void setId(int i) {
            id = i;
        }
        void setName(string n) {
            name = n;
        }
        void setDepartment(string d) {
            department = d;
        }
        void setWorkhours(int h) {
            work_hours = h;
        }
        int getId()const {
            return id;
        }
        string getName()const {
            return name;
        }
        string getDepartment()const {
            return department;
        }
        int getWorkhours()const {
            return work_hours;
        }
        float getSalary()const {
            return salary;
        }
        float applyRaise(float percentage) {
            salary = salary + (salary * percentage);
            return salary;
        }
        void calculateSalary() {
            salary = work_hours * 50;
        }
};
int main(){
    Employee employees[5];
    int id, hour;
    float percantage;
    string name, department;

    cout << "Enter rate of increase: ";
    cin >> percantage;

    for(int i=0; i<5; i++){
        cout << "Enter id of " << i + 1 << ". employee: ";
        cin >> id;

        employees[i].setId(id);

        cout << "Enter name of " << i + 1 << ". employee: ";
        cin.ignore();
        getline(cin, name);
        

        employees[i].setName(name);

        cout << "Enter department of " << i + 1 << ". employee: ";
        getline(cin, department);

        employees[i].setDepartment(department);

        cout << "Enter work hour of " << i + 1 << ". employee: ";
        cin >> hour;

        employees[i].setWorkhours(hour);
      

    }

    for(int i=0; i<5; i++){
        cout << "Id of " << i + 1 << ". employee: " << employees[i].getId() << endl;
        cout << "Name of " << i + 1 << ". employee: " << employees[i].getName() << endl;
        cout << "Department of " << i + 1 << ". employee: " << employees[i].getDepartment() << endl;
        cout << "Work hour of " << i + 1 << ". employee: " << employees[i].getWorkhours() << endl;

        employees[i].calculateSalary();

        cout << "Old salary of " << i + 1 << ". employee: " << employees[i].getSalary() << endl;

        employees[i].applyRaise(percantage);

        cout << "New salary of " << i + 1 << ". employee: " << employees[i].getSalary() << endl;
    }
    return 0;
}