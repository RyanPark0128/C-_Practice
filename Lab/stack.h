#ifndef STACK_H
#define STACK_H
#include <iostream>

class stack{
    public:
        stack();
        double peek();
        void push(double);
        double pop();
        bool is_empty();

        ~stack();

        stack(const stack &);

        const stack&operator=(const stack&);

    private:
    struct node{
        double data;
        node* next;
    };
    node * top;
};


stack::stack(){
    top = nullptr;  
}

double stack::peek(){
    if(is_empty()){
        std::cout <<"Invalid Value" <<std::endl;  //crr is print an error message.
        exit(1);
    }
    return top->data;
}

void stack::push(double x){
    top = new node{x, top};
}

double stack::pop(){
    double tmp = peek();
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
            tail->next= new node{p->data, nullptr};
            tail = tail->next;
            p = p->next;
        }
    }
}

// // const Stack& Stack::operator=(const Stack&rhs){
//     if(this == &rhs){
//         return *this;
//     }

//     while(top){
//         node*tmp = top;
//         top = top->next;
//         delete tmp;
//     }
//     top = nullptr;
//     if(rhs.top){
//         top = new Stack::node{rhs.top->data,top};
//         Stack::node * tail = top;
//         Stack::node* p = rhs.top->next;
//         while(p){
//             tail->next= new node(p->data, nullptr);
//             tail = tail->next;
//             p = p->next;
//         }
//     }
// }


#endif