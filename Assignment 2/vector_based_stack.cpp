#include "vector_based_stack.h"

///// adds a new item to the top of the stack
void v_stack::push(const int& item) {
    container.push_back(item);
}

///// gets a reference to the top element (throws error if empty)
int& v_stack::top() {
    if (empty()) throw std::out_of_range("Stack is empty");
    return container.back();
}

///// same as top() but for const stacks
const int& v_stack::top() const {
    if (empty()) throw std::out_of_range("Stack is empty");
    return container.back();
}

///// removes the top item from the stack
void v_stack::pop() {
    if (empty()) throw std::out_of_range("Stack is empty");
    container.pop_back();
}

///// checks if the stack has anything in it or not
bool v_stack::empty() const {
    return container.empty();
}

///// returns how many elements are currently in the stack
size_t v_stack::size() const {
    return container.size();
}



// Menu Functions

///// helper function to check if a string only has digits
bool isDigits(const std::string& str1) {
    return str1.find_first_not_of("0123456789") == std::string::npos;
}

///// keeps asking until user enters a number within range (kinda like input validation)
int getChoice(int min, int max) {
    int choice;
    while (true) {
        std::cin >> choice;

        if (!std::cin.fail() && choice >= min && choice <= max) return choice;

        std::cin.clear();               // reset bad input
        std::cin.ignore(1000, '\n');    // flush input buffer
        std::cout << "Invalid. Enter a number between " << min << " and " << max << ": ";
    }
}

///// calculates the average value of all numbers in the stack (without changing the original one)
int findAverage(v_stack stack) {
    int size = stack.size(); 

    if (stack.empty()) {
        std::cout << "Stack is empty. No average to calculate.\n";
        return 0;
    }

    int sum = 0;

    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }

    int avg = sum / size;
    std::cout << "The average of your stack is " << avg << std::endl;
    return avg;
}

///// main menu that lets the user play around with the stack
void vsMenu(v_stack stack) {
    int choice;
    do {
        std::cout << "\n>>> What would you like to do with it? <<<\n";
        std::cout << "1. Check if the stack is empty\n";
        std::cout << "2. Insert an integer\n";
        std::cout << "3. Remove an integer\n";
        std::cout << "4. Find the top\n";
        std::cout << "5. Find average value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        choice = getChoice(1, 6);

        switch (choice) {
            case 1: {
                if (stack.empty())
                    std::cout << "Your stack is empty.\n";
                else
                    std::cout << "There are numbers in your stack.\n";
                break;
            }

            case 2: {
                std::string input;
                std::cout << "Enter a whole number to add: ";
                std::cin >> input;
            
                if (isDigits(input)) {
                    int value = std::stoi(input);
                    stack.push(value);
                    std::cout << value << " was added to your stack.\n";
                } else {
                    std::cout << "You need to type a positive number.\n";
                }
                break;
            }
            
            case 3: {
                if (stack.empty())
                    std::cout << "Your stack is empty.\n";
                else {
                    int topVal = stack.top();
                    stack.pop();
                    std::cout << topVal << " was deleted from your stack.\n";
                }
                break;
            }

            case 4: {
                if (stack.empty())
                    std::cout << "Your stack is empty.\n";
                else
                    std::cout << stack.top() << " is on the top of your stack.\n";
                break;
            }

            case 5: {
                findAverage(stack);
                break;
            }

            case 6: {
                std::cout << "See ya!\n";
                break;
            }

            default:
                std::cout << "Try another number.\n";
                break;
        }
    } while (choice != 6);
}
