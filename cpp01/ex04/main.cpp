#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream infile(filename.c_str());

    if (!infile.is_open())
    {
        std::cerr << "Error: could not open file " << filename << "\n";
        return 1;
    }
    // File is now open — ready to read!

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) 
    {
        std::cerr << "Error: could not create output file\n";
        return 1;
    }
    std::string     line;
    
    while (std::getline(infile, line))
    {
        int     index = 0; 
        int     pos; 
        std::string     newline; 

        while ((pos = line.find(s1, index)) != -1)
        {
            newline += line.substr(index, pos - index);
            newline += s2;
            index = pos + s1.length();
        }
        newline += line.substr(index);

        outfile << newline << "\n";
        std::cout << newline << std::endl;
    }
}