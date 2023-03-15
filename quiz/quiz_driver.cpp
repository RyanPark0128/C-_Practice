#include <iostream>
#include <ctime>
#include "quiz_obj.h"

int main(){
    srand(time(0));
    quiz_obj qo1(2,2);
    quiz_obj qo2(5,3);
    quiz_obj qo3(3,4);
    quiz_obj qo4(1,1);
    std::cout << "------OBJECT 1--------" << std::endl;
    std::cout << qo1 << std::endl;
    qo1.resize(4,4);
    std::cout << qo1 << std::endl;
    std::cout << "------OBJECT 2--------" << std::endl;
    std::cout << qo2 << std::endl;
    qo2.resize(5,1);
    std::cout << qo2 << std::endl;
    std::cout << "------OBJECT 3--------" << std::endl;
    std::cout << qo3 << std::endl;
    qo3.resize(1,1);
    std::cout << qo3 << std::endl;
    std::cout << "------OBJECT 4--------" << std::endl;
    std::cout << qo4 << std::endl;
    qo4.resize(1,4);
    std::cout << qo4 << std::endl;    
}