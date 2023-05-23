#include <iostream>
#include <thread>
#include <string>
#include "singleton.h"

Singleton* my_singleton = Singleton::GetInstance("GLOBAL");

void FuncThread1(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    const std::string thread1_str = "HELLO";
    Singleton* my_singleton = Singleton::GetInstance(thread1_str);
    std::cout << my_singleton->value() << " Thread1" << std::endl;
}

void FuncThread2(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//    const std::string thread2_str = "WORLD";
//    Singleton* my_singleton = Singleton::GetInstance(thread2_str);
//    std::cout << my_singleton->value() << " Thread2" << std::endl;
}


int main()
{
    /* Following threads should print the same string "GLOBAL".
       This happens since Singleton pattern does not permit a second instance.

       If the commented code inside FuncThread2 is re-activated and line 6 and 39 are commented,
       then it is possible to notice the following behavior:

       The automatic instance of a Singleton inside a function is not blocking the creation of
       another singleton on the global scope.
    */
    std::thread t1(FuncThread1);
    std::thread t2(FuncThread2);
    t1.join();
    t2.join();
    std::cout << my_singleton->value() << " main" << std::endl;
    return 0;
}
