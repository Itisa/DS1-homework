#include <iostream>
#include "SeqStack.h"

int main() {
    SeqStack<int> s(4);
    s.push1(1);
    s.push2(10);
    s.push1(2);
    s.push2(9);
    s.Traverse(Write<int>);
    std::cout<<std::endl;
    int i, m;
    s.pop1(i);
    std::cout << i << std::endl;
    s.pop2(m);
    std::cout << m << std::endl;
    s.Traverse(Write<int>);
}
