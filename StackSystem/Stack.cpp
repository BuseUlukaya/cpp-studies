#include <iostream>
#include "Stack.h"
Stack::Node::Node(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr), size(0) {}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}
int Stack::pop() {
    if(isEmpty()) {
        std::cout <<"Empty stack!" << std::endl;
        return -1;
    }
    Node* temp = top;
    int retval = temp->data;
    top = top->next;
    delete temp;
    size--;
    return retval;

}
bool Stack::isEmpty() const{
    if(top == nullptr) {
        return true;
    }
    return false;
}
/*Stack::~Stack() {
    Node* temp;
    while(top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}*/
int Stack::peek() const{
    if(!isEmpty()) {
        return top->data;
    }
    else {
        std::cout << "Empty stack" << std::endl;
        return -1;
    }
}
Stack::~Stack() {
    while(!isEmpty()) {
        std::cout << "Deleted data: " << top->data << std::endl;
        pop();
    }
}
int Stack::getSize() const{
    return size;
}
