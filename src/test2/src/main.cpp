#include <ros/ros.h>
#include "add.h"
#include "mul.h"

int main()
{
    int a,b,c;
    a = add(2,3);
    b = mul(4,5);
    c = 8;
    std::cout<<"add = "<<a<<std::endl;
    std::cout<<"mul = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    return 0;
}