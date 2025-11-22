#include <iostream>

using namespace std;

class Teacher{
        protected:
                string teacher_name;
                int course_id;
        public:
                Teacher() : teacher_name("Unknown"), course_id(0){}
                Teacher(string name, int id) : teacher_name(name), course_id(id){}

                virtual void display(){
                        cout << teacher_name << " " << course_id << endl;
                }
};

class Course : public Teacher{
                int m_size;
                int *scores;
        public:
        Course(){
                teacher_name = "Unknown";
                course_id = 0;
                m_size = 0;
                scores = NULL;
        }
        Course(string name, int id,int size){
                teacher_name = name;
                course_id = id;
                m_size = size;
                scores = new int [m_size] {0};

        }
        friend istream& operator>>(istream& in,const Course &c);
        void display() override{
                int i;
                cout << teacher_name << " " << course_id << " " << m_size << endl;
                cout << "scores:";
                for(i=0; i<m_size; i++){
                        cout << " " << scores[i] << endl;
                }

        }
        friend void operator==(Course& c1, Course& c2);
        ~Course(){
                delete[]scores;
        }

};
istream& operator>>(istream& in,const Course &c){
        int i;
        cout << "Enter scores for " << c.course_id << endl;
        for(i=0; i<c.m_size;i++){
                cin >> c.scores[i];
        }
        return in;
}
void operator==(Course& c1, Course& c2){
        int i;
        int max;
        int score_sum1 = 0, score_sum2 = 0;
        int avg1, avg2;

        for(i=0; i< c1.m_size; i++){
                score_sum1 += c1.scores[i];
        }
        avg1 = score_sum1 / c1.m_size;
        for(i=0; i< c2.m_size; i++){
                score_sum2 += c2.scores[i];
        }
        avg2 = score_sum2 / c2.m_size;

        cout << "Average for " << c1.course_id << " is " << avg1 << endl;
        cout << "Average for " << c2.course_id << " is " << avg2 << endl;

        if(avg1 > avg2){
                max = c1.course_id;
        }
        else{
                max = c2.course_id;
        }
        cout << "Couse " << max << " has highest average" << endl;

}

int main(){
        string first_name, second_name;
        int first_id, second_id, first_size, second_size;


        cout << "Enter teacher name, course id and class size: ";
        cin >> first_name >> first_id >> first_size;
        cout << "Enter teacher name, course id and class size: ";
        cin >> second_name >> second_id >> second_size;

        Course c1(first_name, first_id, first_size);
        Course c2(second_name, second_id, second_size);

        cin >> c1;
        cin >> c2;
        c1 == c2;

        return 0;













}

