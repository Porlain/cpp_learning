/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-05 11:06:59
 */
#include <iostream>
#include <map>
#include <string>
#include <functional>

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j)
{ return i % j; };
struct Div
{
    int operator()(int i, int j) const { return i / j; }
};

auto binops = std::map<std::string, std::function<int(int, int)>>{
    {"+", add},               // function pointer
    {"-", std::minus<int>()}, // library functor
    {"/", Div()},             // user-defined functor
    {"%", mod},               // named lambda object
    {"*", [](int i, int j) { return i * j; }}// unnamed lambda
}; 

int main()
{   
    while ( std::cout << "Pls enter as: num operator num :\n", true )
    {
        int lhs, rhs; std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }
    return 0;
}
