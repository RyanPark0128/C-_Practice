#include <iostream>
#include "stack3.h"

void bin(int k, string bin_str= ""){
    if(k==0){
        std::cout<<bin_str<<std::endl;
        return;
    }

    bin(k-1, bin_str+'0');
    bin(k-1, bin_str+'1');

    void bin_stack(int k){
        //To get this code to work you have to template the stack3.h file which I didn't do.
        stack<std::string> s;
        s.push("");

        while(!s.is_empty()){
            std::string curr = s.pop();
            if(curr.size() == k){
                std::cout<< curr <<std::endl;
            }else{
                s.push(curr + '0'); // To reverse how they go into the stack we just replace the '0' with '1'
                s.push(curr + '1'); // To reverse how they go into the stack we just replace the '1' with '0'
            }
        }
    }

    int main(){
        bin_stack(3);
    }
}


//how stack is useful is like when we did the assignment with the binary tree.