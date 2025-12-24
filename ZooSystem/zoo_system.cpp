#include <iostream>
#include <string>

using namespace std;

class Animal {
    private:
        string name;
        int age;
    public:
        Animal(string n, int a) : name(n), age(a) {}
        virtual void makeSound() = 0;
        virtual void printInfo() {
            cout << "Name: " << name << ", " << "Age: " << age << endl;
        }
        virtual ~Animal() {}
};
class Lion : public Animal {
    public:
        Lion(string n, int a) : Animal(n, a) {}
        void makeSound()override {
            cout << "Rooooar!" << endl;
        }
        void printInfo() {
            Animal::printInfo();
            makeSound();
        }

};
class Elephant : public Animal {
    public:
        Elephant(string n, int a) : Animal(n, a) {}
        void makeSound()override {
            cout << "Prrrraaaa!" << endl;
        }
        void printInfo() {
            Animal::printInfo();
            makeSound();
        }
};
class Monkey : public Animal {
    public:
        Monkey(string n, int a) : Animal(n, a) {}
        void makeSound()override {
            cout << "Ooh ooh aah aah!" << endl;
        }
        void printInfo() {
            Animal::printInfo();
            makeSound();
        }
    };

int main() {
    Animal* animals[4];
    animals[0] = new Lion("Alex",5);
    animals[1] = new Elephant("Dumbo", 100);
    animals[2] = new Monkey("George", 3);
    animals[3] = new Elephant("Elly", 75);

    for(int i=0; i<4; i++){
        animals[i] -> printInfo();
    }

    for(int i=0; i<4; i++){
        delete animals[i];
    }

    return 0;
}