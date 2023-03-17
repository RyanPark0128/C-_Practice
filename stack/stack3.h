#ifndef STACK1_H
#define STACK1_H
#include <iostream>

//TO GET THIS FILE WORKING WITH THE ex.cpp YOU NEED TO TEMPLATE.
// template<typename T>;
 class stack{
    public:
        stack();
        int peek();
        void push(int);
        int pop();
        bool is_empty();

        ~stack();

        stack(const stack &);

        const stack&operator=(const stack&);

    private:
    struct node{
        int data;
        node* next;
    };
    node * top;
 }

 
stack::stack(){
    top = nullptr;    
}

int stack::peek(){
    if(is_empty()){
        std::cerr <<"IT IS EMPTY" <<std::endl;  //crr is print an error message.
        exit(1);
    }
    return top->data;
}

void stack::push(int x){
    top = new node{x, top};
}

int stack::pop(){
    int tmp = peek();
    node * todel = top; //todel is to delete.
    top = top->next;
    delete todel;
    return tmp;
}

bool stack::is_empty(){
    return top == nullptr;
}

stack::~stack(){
    while(top){
        node* tmp = top;
        top = top -> next;
        delete tmp;
    }
}

stack::stack(const stack & rhs){
    top = nullptr;
    if(rhs.top){
        top = new node{rhs.top->data,top};
        node * tail = top;
        node* p = rhs.top->next;
        while(p){
            tail->next= new node(p->data, nullptr);
            tail = tail->next;
            p = p->next
        }
    }
}

const stack& stack::operator=(const stack&rhs){
    if(this = &rhs){
        return *this;
    }

    while(top){
        node*tmp = top;
        top = top->next;
        delete tmp;
    }
    if(rhs.top){
        top = new node{

        }
    }
}
 

 #endif