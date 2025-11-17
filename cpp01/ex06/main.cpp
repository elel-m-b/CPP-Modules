#include "Harl.hpp"
#include <iostream>
#include <string>

int getLevelCode(std::string level) 
{
    if (level == "DEBUG") return 0;
    if (level == "INFO") return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR") return 3;
    return 4; // unknown
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    std::string inputLevel = argv[1];
    int levelCode = getLevelCode(inputLevel);

    Harl harl;
    harl.complainFromLevel(levelCode);

    return 0;
}
