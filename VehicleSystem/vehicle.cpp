#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected:
        string manufacturer;
        int engine_number;
    public:
        Vehicle() : manufacturer("Unknown"), engine_number(0){}
        Vehicle(string name, int number) : manufacturer(name), engine_number(number){}
        Vehicle(Vehicle &v){
            manufacturer = v.manufacturer;
            engine_number = v.engine_number;
        }
        string getManufacturer()const{
            return manufacturer;
        }
        int getEnginenumber()const{
            return engine_number;
        }
        void setManufacturer(string name){
            manufacturer = name;
        }
        void setEnginenumber(int number){
            engine_number = number;
        }
        bool operator==(const Vehicle& v){
            return (this->manufacturer == v.manufacturer && this->engine_number == v.engine_number);
        }
        Vehicle& operator=(const Vehicle& other){
            if(this != &other){
                manufacturer = other.manufacturer;
                engine_number = other.engine_number;
            }
            return *this;
        }
        friend ostream& operator<<(ostream& out, const Vehicle& v);
        friend istream& operator>>(istream& in, Vehicle& v);

};
ostream& operator<<(ostream& out, const Vehicle& v){
    out << "Manufacturer: " << v.manufacturer << endl;
    out << "Number of engine cylinders: " << v.engine_number << endl;
    return out;
}
istream& operator>>(istream& in, Vehicle& v){
    in >> v.manufacturer >> v.engine_number;
    return in;
}

class Truck : public Vehicle{
    double load_capacity;
    int towing_capacity;
    public:
        Truck() : Vehicle("Unknown",0), load_capacity(0), towing_capacity(0){}
        Truck(string name, int number, double c1, int c2) : Vehicle(name,number), load_capacity(c1), towing_capacity(c2){}
        Truck(Truck& t) : Vehicle(t), load_capacity(t.load_capacity), towing_capacity(t.towing_capacity){}
        ~Truck(){}
        double getLoadcapacity()const{
            return load_capacity;
        }
        int getTowingcapacity()const{
            return towing_capacity;
        }
        void setLoadcapacity(double capacity){
            load_capacity = capacity;
        }
        void setTowingcapacity(int capacity){
            towing_capacity = capacity;
        }
        Truck &operator=(const Truck& other){
            if(this != &other){
                manufacturer = other.manufacturer;
                engine_number = other.engine_number;
                load_capacity = other.load_capacity;
                towing_capacity = other.towing_capacity;
            }
            return *this;
        }
        bool operator==(const Truck& other){
            return this->manufacturer == other.manufacturer &&
                   this->engine_number == other.engine_number &&
                   this->load_capacity == other.load_capacity &&
                   this->towing_capacity == other.towing_capacity ;
        }

        bool operator<(const Truck& other){
            return this->towing_capacity  < other.towing_capacity;
        }
        friend ostream& operator<<(ostream& out, const Truck& t);
        friend istream& operator>>(istream& in, Truck& t);

        Truck operator+(Truck& other){
            Truck result(*this);
            result.load_capacity += other.load_capacity;
            result.towing_capacity += other.towing_capacity;
            return result;
        }
};

ostream& operator<<(ostream& out, const Truck& t){
    out << "Manufacturer :" << t.manufacturer << endl;
    out << "Number of engine cylinders: " << t.engine_number << endl;
    out << "Load capacity: " << t.load_capacity << endl;
    out << "Towing capacity: " << t.towing_capacity << endl;
    return out;
}

istream& operator>>(istream& in, Truck& t){
    in >> t.manufacturer >> t.engine_number >> t.load_capacity >> t.towing_capacity;
    return in;
}

int main(){
    Truck t1("Ores", 12 , 234.5, 300);
    Truck t2("Pilsan", 14, 345.8, 400);
    Truck t3;

    t1 < t2;

    if(t1 == t2){
        cout << "They are equal." << endl;
    }
    else{
        cout << "They are not equal." << endl;
    }

    t3 = t1 + t2;
    cout << t1;
    cout << t2;
    cout << t3;

    return 0;
}


