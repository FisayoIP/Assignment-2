#ifndef VECTOR_BASED_STACK_H
#define VECTOR_BASED_STACK_H

#include <vector>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

///// Declarations for all necessary functions and class members
class v_stack {
private:
    std::vector<int> container;

public:
    void push(const int& item);
    int& top();
    const int& top() const;
    void pop();
    bool empty() const;
    size_t size() const;
};

int getChoice(int min, int max);
int findAverage(v_stack stack);
void vsMenu(v_stack stack);
bool isDigits(const std::string& str1);

#endif 
