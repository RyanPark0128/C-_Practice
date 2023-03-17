#ifndef STACK1_H
#define STACK1_H
#include <iostream>

//Should always be templated but for today lecture. Mr.Ryan isn't going to template it
 class stack{
    public:
        stack(int);
        int peek();
        void push(int);
        int pop();
        bool is_empty();

        ~stack();

        stack(const stack &);

        const stack&operator=(const stack&);

    private:
    int * top;
    int size; //size of the array.
    int n; // number of items in array.
 }

 
stack::stack(int x){
    size = x;
    top = new int [size];
    n = 0;
}

int stack::peek(){
    if(is_empty()){
        std::cerr <<"IT IS FULL" << std::endl;
        exit(1);
    }
    return top[n-1];
}

void stack::push(int x){
    if(n!= size){
    top [n++] = x;
    }else{
        std::cerr <<"IT IS FULL" << std::endl;
        exit(1);
    }
};

int stack::pop(){
    int tmp == peek();
    n--;
    return tmp;
}

bool stack::is_empty(){
        return n == 0;
}

stack::~stack(){
    delete [] top;
}

stack::stack(const stack & rhs){
    size = rhs.size;
    n = rhs.n;

    top = new int[size];

    for(int i = 0; i<size; i++){
        top[i] = rhs.top[i];
    }
}

const stack& stack::operator=(const stack&rhs){
    if(this = &rhs){
        return *this;
    }

    delete [] top;

    size = rhs.size;
    n = rhs.n;

    top = new int[size];

    for(int i = 0; i<size; i++){
        top[i] = rhs.top[i];
    }

    return this;
}
 

 #endif