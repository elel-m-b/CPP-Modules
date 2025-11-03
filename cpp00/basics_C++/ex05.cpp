#include <iostream> // For console I/O
#include <fstream>  // For file I/O

int main() 
{
    // Console Output
    std::cout << "Hello, World!" << std::endl;

    // Console Input
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You are " << age << " years old." << std::endl;

    // File Output
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) 
    {
        outFile << "This is a line written to a file." << std::endl;
        outFile.close();
    } 
    else 
        std::cerr << "Error opening file for writing." << std::endl;
    
        std::ifstream inFile("example.txt");
    if (inFile.is_open()) 
    {
        std::string line;
        while (std::getline(inFile, line)) 
            std::cout << "Read from file: " << line << std::endl;
        inFile.close();
    } 
    else 
        std::cerr << "Error opening file for reading." << std::endl;
    return 0;
}