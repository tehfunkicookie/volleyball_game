#include <iostream>
#include <vector>
#include <string>
#include <array>

void fun(int num)
{
    static int a = num;
    a++;
    std::cout << a << std::endl;
}

int main()
{
    std::cout << "oh shit!" << std::endl;
    fun(1);
    fun(1);
    fun(55555);
    fun(4);
    return 0;
}