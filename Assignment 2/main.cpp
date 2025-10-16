#include "vector_based_stack.h"

#include <iostream>
#include <fstream>
#include <string>
#include <random>

//Compile: 
/*
g++ -std=c++17 main.cpp vector_based_stack.cpp -o main
*/

int main() {
    // Create a stack of integers
    v_stack stack;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 99);

    std::cout << "...\n";
    //Initializing a stack for the user
    for (int i = 0; i < 15; ++i) {
        stack.push(dist(gen));
    }
    std::cout << "Hi, I just made you a stack with 15 numbers";

    //Runs the menu
    vsMenu(stack);


  
    return 0;
}
