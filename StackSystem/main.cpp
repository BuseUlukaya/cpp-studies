#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack stack;
    stack.push(5);
    cout << endl;
    cout << stack.peek();
    stack.push(3);
    cout << endl;
    cout << stack.pop();
    cout << endl;
    cout << stack.isEmpty();
    cout << endl;
    cout << stack.getSize();
    cout << stack.pop();
    cout << stack.peek();
    cout << stack.pop();

    return 0;
}