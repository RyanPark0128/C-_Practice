#ifndef STACK1_H
#define STACK1_H
#include<vector>

//Should always be templated but for today lecture. Mr.Ryan isn't going to template it
 class stack{
    public:
        int peek();
        void push(int);
        int pop();
        bool is_empty();
    private:
    std::vector<int> top;

 }


stack::stack(){

}
int stack::peek(){
    return top.back();
}

void stack::push(int x){
    top.push_back(x);
};

int stack::pop(){
    int tmp = top.back();
    top.pop_back();
    return tmp;
}
bool stack::is_empty(){
    return top.empty();
}

 

 #endif