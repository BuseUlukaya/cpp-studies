#include <iostream>
using namespace std;
class Animals{
    protected:
        string m_kind;
        string m_colour;
        int m_age;
    public:
        void setInfo(string kind, string colour, int age){
            m_kind = kind;
            m_colour = colour;
            m_age = age;
        }
        void printInfos(){
            cout << m_kind << " " << m_colour << " " << m_age <<  " " << endl;
        }
        virtual void sound() =  0; 
};

class Cat : public Animals{
    private:
        bool m_vaccinate;
    public:
        Cat(){
            cout << "Object was created" << endl;
        }
        Cat(string kind, string colour, int age, bool vaccinate = false){
            m_kind = kind;
            m_colour = colour;
            m_age = age;
            m_vaccinate = vaccinate;
        }
        void sound(){
            cout << "miyav" << endl;
        }
        void printInfos(){
            cout << m_kind << " " << m_colour << " " << m_age <<  " " << m_vaccinate << endl;
        }
};

class Dog :public Animals{
    private:
        bool m_cut;
    public:
        Dog(){
            cout << "Object was created" << endl;
        }
        Dog(string kind, string colour, int age, bool cut = false){
            m_kind = kind;
            m_colour = colour;
            m_age = age;
            m_cut = cut;
        }
        void sound(){
            cout << "havhav" << endl;
        }
         void printInfos(){
            cout << m_kind << " " << m_colour << " " << m_age << " " << m_cut << endl;
        }
};
void playSound(Cat *pcat){
    pcat->sound();
}
void playSound(Dog *pdog){
    pdog->sound();
}
void playSound(Animals *panimal){
    panimal->sound();
}
int main(){
    Cat cat;
    cat.setInfo("british", "gray", 12);
    playSound(&cat);
    cat.printInfos();

    Dog dog;
    dog.setInfo("kangal", "black", 8);
    playSound(&dog);
    
    Cat boncuk("British", "gray", 7);
    boncuk.printInfos();
    
    Dog fino("Kangal", "black", 5, true);
    fino.printInfos();

    return 0;
}

