#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        class Node {
            public:
                int data;
                Node* next;
                Node(int value);
           
        };
        Node *top;
        int size;
    public: 
        Stack();
        void push(int value);
        int pop();
        int peek() const;
        bool isEmpty() const;
        int getSize() const;
        ~Stack();
};


#endif