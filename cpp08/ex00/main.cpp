#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(){
    // Test with vector
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(20);
    numbers.push_back(40);
    try{
        std::vector<int>::const_iterator it = easyfind(numbers, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test value that doesn't exist
    try{
        std::vector<int>::const_iterator it = easyfind(numbers, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test with list
    std::list<int> values;
    values.push_back(5);
    values.push_back(15);
    values.push_back(25);
    try{
        std::list<int>::const_iterator it = easyfind(values, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}