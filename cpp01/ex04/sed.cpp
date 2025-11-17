#include "sed.hpp"



Sed::Sed(const  std::string &f, const std::string &s1_val, const std::string &s2_val)
{
    filename = f;
    s1 = s1_val;
    s2 = s2_val;
}
Sed::~Sed(){}


void Sed::replaceInFile() const
{
    if (s1.empty())
    {
        std::cerr << "Error : s1 connot be empty. " << std::endl;
        return ;
    }
    std::ifstream infile(filename.c_str());
    if (!infile) 
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }
    std::ostringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    std::cout << "buffer" << buffer << std::endl;
    infile.close();

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) 
    {
        std::cerr << "Error: cannot create file " << filename << ".replace" << std::endl;
        return;
    }

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) 
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    outfile << content;
    outfile.close();
}