#include <iostream>

using namespace std;

class HotDogStand{
    private:
        int stand_id;
        int sold;
        static int total_sold;
    public:
        HotDogStand(){
        }
        HotDogStand(int i, int s) {
            if(s < 0){
                sold = 0;
            }
            else{
                sold = s;
            }
            stand_id = i;
            total_sold +=sold;
        }
        int getId()const {
            return stand_id;
        }
        int getSold()const {
            return sold;
        }
        void  getTotalSold(){
            cout << "All stands total: " << total_sold << " hot dogs." << endl;
        }
        void justSold() {
            ++total_sold;
        }
};

int HotDogStand::total_sold = 0;

int main(){
    HotDogStand h1(101, 5);
    HotDogStand h2(102, 3);
    HotDogStand h3(103, 7);

    cout << "Stand " << h1.getId() << " sold " << h1.getSold() << " hot dogs." << endl;
    cout << "Stand " << h2.getId() << " sold " << h2.getSold() << " hot dogs." << endl;
    cout << "Stand " << h3.getId() << " sold " << h3.getSold() << " hot dogs." << endl;
    
    h1.justSold();
    h2.justSold();
    h3.justSold();
    h3.getTotalSold();

    return 0;
}