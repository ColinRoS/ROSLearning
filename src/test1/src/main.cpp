#include <ros/ros.h>


int add(int a,int b);
int mul(int a,int b);

int main()
{
    int a,b,c;
    int i,j,m,n;
    std::cin>>i>>j>>m>>n;
    a = add(i,j);
    b = mul(m,n);
    c = 8;
    std::cout<<"add = "<<a<<std::endl;
    std::cout<<"mul = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    return 0;
}

int add(int a,int b)
{
    return a+b;
}

int mul(int a,int b)
{
    return a*b;
}