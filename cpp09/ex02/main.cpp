#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>
static double getTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<double>(tv.tv_sec) * 1000000.0+ static_cast<double>(tv.tv_usec);
}

static void printVector(const std::vector<int>& v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end();++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    try
    {   
        if (argc < 2)
            throw std::invalid_argument("Error");
        PmergeMe pmerge;
        for (int i = 1; i < argc; ++i)
        {
            int number = pmerge.parseNumber(argv[i]);
            pmerge.addNumber(number);
        }
        std::vector<int> vectorData = pmerge.getVector();
        std::deque<int> dequeData = pmerge.getDeque();
        std::cout << "Before: ";
        printVector(vectorData);
        double startVector = getTimeInMicroseconds();
        pmerge.sortVector(vectorData);
        double endVector = getTimeInMicroseconds();
        double vectorTime = endVector - startVector;
        double startDeque = getTimeInMicroseconds();
        pmerge.sortDeque(dequeData);
        double endDeque = getTimeInMicroseconds();
        double dequeTime = endDeque - startDeque;
        std::cout << "After:  ";
        printVector(vectorData);
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << vectorData.size() << " elements with std::vector : " << vectorTime << " us"<< std::endl;
        std::cout << "Time to process a range of " << dequeData.size() << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
