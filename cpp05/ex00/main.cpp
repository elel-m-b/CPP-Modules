#include "Bureaucrat.hpp"
int main(void){
    try{
        Bureaucrat b("Ahmed", -1);   
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat test("hassan", 200);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}