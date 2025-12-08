#include <iostream>
#include <fstream>
#include <string>

// step 1 : validate argument
// step 2 : open a file
// step 3 : read a file
// step 4 : replace s1 -> s2
// step 5 : create output file : filename.replace
// step 6 : write modified content
// step 7 : done

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

    std::ifstream infile(filename);

    if (!infile.is_open())
    {
        std::cerr << "Error: could not open file " << filename << "\n";
        return 1;
    }
    // File is now open — ready to read!

    std::ofstream outfile(filename + ".replace");
    if (!outfile.is_open()) 
    {
        std::cerr << "Error: could not create output file\n";
        return 1;
    }
    std::string     line;
    
    while (std::getline(infile, line))
    {
        int     index = 0; // start searching from begin of the line
        int     pos; // starting pos of s1
        std::string     newline; // modofied line

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