#include <iostream>

using namespace std;

class PersonType { 
    private:
        string firstName;
        string lastName;
    public:
        virtual void printInfo() {
            cout << firstName << " " <<  lastName << endl;
        }
        void setName(string f, string l) {
            firstName = f;
            lastName = l;
        }
        string getFirstName(){
            return firstName;
        }
        string getLastName() {
            return lastName;
        }
        PersonType(string f = "", string l = "") {
            firstName = f;
            lastName = l;
        }
        virtual ~PersonType() {

        }
};
class DateType {
    private:
        int dDay;
        int dMonth;
        int dYear;
    public:
        void setDate(int day, int month, int year) {
            dDay = day;
            dMonth = month;
            dYear = year;
        }
        int getDay()const {
            return dDay;
        }
        int getMonth()const {
            return dMonth;
        }
        int getYear()const {
            return dYear;
        }
        void printDate() {
            if(dDay < 10) {
                cout << "0";
            }
            cout << dDay << "/";
            if(dMonth < 10) {
                cout << "0";
            }
            cout << dMonth << "/";
            cout << dYear << endl;
        }
        DateType(int day = 1, int month = 1, int year = 1900) {
            dDay = day;
            dMonth = month;
            dYear = year;
        }
};
class  ExtPersonType : public PersonType {
    private:
        DateType birthDate;
        string relation;
        string phoneNumber;
    public:
        ExtPersonType(string f, string l, int d, int m, int y, string r, string p) : PersonType(f, l), birthDate(d, m, y),
         relation (r), phoneNumber(p) {

        }
        void printInfo()override {
            cout << relation << endl;
            PersonType :: printInfo();
            birthDate.printDate();
            cout << phoneNumber << endl;
        }

};
int main() {
    string name, surname, relation;
    int day, month, year;
    string phoneNumber;
    char choice;
    PersonType* p = nullptr;

    cout << "Enter name and surname: ";
    cin >> name >> surname;
    cout << "Choice P or E (representing PersonType and ExtPersonType): ";
    cin >> choice;

    if(choice == 'P') {
        p = new PersonType(name, surname);

        p->printInfo();
    }
    else if(choice == 'E') {
        cout << "Enter birth date(Day- Month - Year): ";
        cin >> day >> month >> year;
        cout << "Enter relation: ";
        cin >> relation;
        cout << "Enter phone number: ";
        cin >> phoneNumber;

        p = new ExtPersonType(name, surname, day, month, year, relation, phoneNumber);

        p->printInfo();
    }

    delete p;
    
    return 0;
}