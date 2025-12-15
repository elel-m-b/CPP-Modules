#include <iostream>
#include <fstream>
#include <string>

void replace_in_file(const std::string &filename, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 is empty\n";
        return;
    }

    std::ifstream input(filename.c_str()); // <-- c_str() for C++98
    if (!input.is_open())
    {
        std::cerr << "Error: cannot open " << filename << "\n";
        return;
    }

    std::string outfile = filename + ".replace";
    std::ofstream output(outfile.c_str()); // <-- c_str() for C++98
    if (!output.is_open())
    {
        std::cerr << "Error: cannot create " << outfile << "\n";
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        for (size_t i = 0; i < line.length();)
        {
            if (line.substr(i, s1.length()) == s1)
            {
                output << s2;
                i += s1.length();
            }
            else
            {
                output << line[i];
                i++;
            }
        }
        output << '\n';
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "./ex04 file_name <S1> <S2>\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    replace_in_file(filename, s1, s2);

    return 0;
}