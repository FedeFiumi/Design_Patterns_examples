#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <string>

class Singleton{

protected:
    Singleton(const std::string value): value_(value) {}

    static Singleton* singleton_;
    std::string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton* GetInstance(const std::string& value);

    void userFunction(void){ std::cout << "Hello world!" << std::endl; }

    std::string value(void) const{
        return value_;
    }
};

#endif // SINGLETON_H
