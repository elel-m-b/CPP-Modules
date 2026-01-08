#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define MAX_IDEAS 100

class Brain
{
    private:
    std::string ideas[MAX_IDEAS];
    
    public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();
};

#endif