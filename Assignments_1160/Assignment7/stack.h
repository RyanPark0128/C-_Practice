#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
class stack{
    public:
        stack();
        T peek();
        void push(T);
        T pop();
        bool isEmpty();

        ~stack();
        stack(const stack<T> & rhs);
        const stack<T>& operator=(const stack<T>&);
    private:
        struct node{
            T data;
            node* next;
        };
        node* top;
};

template <typename T>
stack<T>::stack(){
    top = nullptr;
}

template <typename T>
T stack<T>::peek(){
    if(isEmpty()){
        std::cerr << "It is empty" << std::endl;
        exit(1);
    }
    return top->data;
}

template <typename T>
void stack<T>::push(T x){
    top = new node{x,top};
}

template <typename T>
T stack<T>::pop(){
    T temp = peek();
    node* todel = top;
    top = top->next;
    delete todel;
    return temp;
}

template <typename T>
bool stack<T>::isEmpty(){
    return top == nullptr;
}

template <typename T>
stack<T>::~stack(){
    delete[] top;
}

template <typename T>
stack<T>::stack(const stack<T> & rhs){
    top = nullptr;
    if(rhs.top){
        top = new node{rhs.top->data,top};
        node* tail = top;
        node* p = rhs.top->next;
        while(p){
            tail->next = new node{p->data,nullptr};
            tail = tail->next;
            p = p->next;
        }
    }
} 

template <typename T>
const stack<T>& stack<T>::operator=(const stack<T>& rhs){
    if(this == &rhs){
        return *this;
    }
    while(top){
        node* temp = top;
        top = top->next;
        delete temp;
    }
    if(rhs.top){
        top = new node{rhs.top->data,top};
        node* tail = top;
        node* p = rhs.top->next;
        while(p){
            tail->next = new node{p->data,nullptr};
            tail = tail->next;
            p = p->next;
        }
    }
}
#endif