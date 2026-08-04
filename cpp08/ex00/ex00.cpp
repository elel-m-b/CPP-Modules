#include <iostream>
#include <vector>
template <typename T>

class NoutFound : public std::exception
{
    public:
    const char* what() const throw()
    {
        return "value not found";
    }
};

typename   T::iterator easyfind(T& container,  int value)
{
    typename T::iterator it;


    it = std::find (container.begin(), value);
    if (it == container.end())
        throw NotFound();
    return it;
}


int main(void)
{
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    try
    {
        std::vector<int>::iterator it = easyfind(nums, 5);
        std::cout << "Found " << *it << std::endl;
    }
    catch(const NoutFound& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        
    }
}