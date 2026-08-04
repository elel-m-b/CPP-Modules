#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class NotFound : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Value not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFound();

    return it;
}

int main()
{
    std::vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);

    try
    {
        std::vector<int>::iterator it = easyfind(nums, 5);

        std::cout << "Found: " << *it << std::endl;
    }
    catch (const NotFound& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(nums, 563);

        std::cout << "Found: " << *it << std::endl;
    }
    catch (const NotFound& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}