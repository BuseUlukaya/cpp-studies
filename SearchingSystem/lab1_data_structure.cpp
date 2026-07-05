#include <iostream>
#include <fstream>
#include <string>
#define MAX_SIZE 100

using namespace std;

string myArray[MAX_SIZE];
string foundBooks[MAX_SIZE];
int found_book_number = 0;
int book_number;

bool fileReaderFunction() {
    ifstream MyFile("Textbooks.txt");
    if(MyFile.is_open()) {
        int i=0;
        while(i <= MAX_SIZE && getline(MyFile, myArray[i])) {
            i++;
        }

        MyFile.close();
        book_number = i;
        return true;
    }
    else{
        cerr << "There is no such file";
        return false;
    }
}
string* searcherFunction(string word) {
    int j = 0;
    for(int i=0; i<book_number; i++) {
        size_t index = myArray[i].find(word);
        if (index != string::npos) {
            foundBooks[j++] = myArray[i];
        }
    }
    found_book_number = j;

    return foundBooks;
}

int main(){
    string word;
    string choice;
    string* books;
    fileReaderFunction();
    do {
        cout << "Enter a portion of title or author that you are looking for: ";
        cin >> word;
        books = searcherFunction(word);
        cout << "\nThere are " << found_book_number << " results for " << word << ":\n";
        for(int i=0; i<found_book_number; i++) {
            cout << books[i] << endl;
        }
        cout << "\nWould you like to run again again (yes-no) ? ";
        cin >> choice;

        if(choice == "no") {
            cout << "Bye....." << endl;
        }

    } while(choice == "yes");

        return 0;
}
