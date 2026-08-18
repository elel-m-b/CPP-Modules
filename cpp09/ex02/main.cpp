#include "PmergeMe.hpp"

template <typename Container>
void printContainer(const Container& container)
{
    typename Container::const_iterator it;

    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmergeMe;

        /*
        ** ---------------------------------------------------------------
        ** 1. PARSE ARGUMENTS
        ** ---------------------------------------------------------------
        **
        ** Example:
        **
        ** ./PmergeMe 3 5 9 7 4
        **
        ** argv:
        ** argv[1] = "3"
        ** argv[2] = "5"
        ** argv[3] = "9"
        ** argv[4] = "7"
        ** argv[5] = "4"
        **
        ** Each string is converted to an int and added to both:
        **
        ** vector
        ** deque
        */
        for (int i = 1; i < argc; ++i)
        {
            int number = pmergeMe.parseNumber(argv[i]);
            pmergeMe.addNumber(number);
        }

        /*
        ** ---------------------------------------------------------------
        ** 2. PRINT BEFORE
        ** ---------------------------------------------------------------
        */

        std::cout << "Before: ";

        printContainer(pmergeMe.getVector());

        /*
        ** ---------------------------------------------------------------
        ** 3. COPY THE CONTAINERS
        ** ---------------------------------------------------------------
        **
        ** getVector() and getDeque() return const references.
        **
        ** We make copies because sortVector() and sortDeque()
        ** modify the containers.
        */
        std::vector<int> vector = pmergeMe.getVector();
        std::deque<int> deque = pmergeMe.getDeque();

        /*
        ** ---------------------------------------------------------------
        ** 4. SORT VECTOR + MEASURE TIME
        ** ---------------------------------------------------------------
        */

        std::clock_t startVector = std::clock();

        pmergeMe.sortVector(vector);

        std::clock_t endVector = std::clock();

        /*
        ** ---------------------------------------------------------------
        ** 5. SORT DEQUE + MEASURE TIME
        ** ---------------------------------------------------------------
        */

        std::clock_t startDeque = std::clock();

        pmergeMe.sortDeque(deque);

        std::clock_t endDeque = std::clock();

        /*
        ** ---------------------------------------------------------------
        ** 6. PRINT AFTER
        ** ---------------------------------------------------------------
        */

        std::cout << "After:  ";

        printContainer(vector);

        /*
        ** ---------------------------------------------------------------
        ** 7. CALCULATE TIME
        ** ---------------------------------------------------------------
        **
        ** std::clock() returns processor clock ticks.
        **
        ** CLOCKS_PER_SEC tells us how many ticks correspond to
        ** one second.
        **
        ** Multiplying by 1,000,000 converts seconds to microseconds.
        */
        double vectorTime =
            static_cast<double>(endVector - startVector)
            / CLOCKS_PER_SEC
            * 1000000.0;

        double dequeTime =
            static_cast<double>(endDeque - startDeque)
            / CLOCKS_PER_SEC
            * 1000000.0;

        /*
        ** ---------------------------------------------------------------
        ** 8. PRINT TIMINGS
        ** ---------------------------------------------------------------
        */

        std::cout
            << "Time to process a range of "
            << vector.size()
            << " elements with std::vector : "
            << vectorTime
            << " us"
            << std::endl;

        std::cout
            << "Time to process a range of "
            << deque.size()
            << " elements with std::deque  : "
            << dequeTime
            << " us"
            << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}