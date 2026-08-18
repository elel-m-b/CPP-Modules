#include "PmergeMe.hpp"

/*
** ---------------------------------------------------------------------------
**                          CONSTRUCTOR / DESTRUCTOR
** ---------------------------------------------------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

/*
** ---------------------------------------------------------------------------
**                              PARSING
** ---------------------------------------------------------------------------
*/

/*
** Convert a string to a positive integer.
**
** Rules:
** - Only digits are accepted.
** - Empty string is invalid.
** - Negative numbers are invalid.
** - 0 is accepted.
** - INT_MAX is the maximum allowed value.
*/
int PmergeMe::parseNumber(const std::string& str)
{
    if (str.empty())
        throw std::invalid_argument("Error");

    size_t i = 0;

    /*
    ** Optional '+' is accepted.
    ** '-' is rejected.
    */
    if (str[0] == '+')
    {
        i = 1;

        if (i == str.length())
            throw std::invalid_argument("Error");
    }
    else if (str[0] == '-')
    {
        throw std::invalid_argument("Error");
    }

    long value = 0;

    for (; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            throw std::invalid_argument("Error");

        value = value * 10 + (str[i] - '0');

        if (value > INT_MAX)
            throw std::out_of_range("Error");
    }

    return static_cast<int>(value);
}


/*
** Add the number to both containers.
*/
void PmergeMe::addNumber(int number)
{
    _vector.push_back(number);
    _deque.push_back(number);
}


/*
** ---------------------------------------------------------------------------
**                              GETTERS
** ---------------------------------------------------------------------------
*/

const std::vector<int>& PmergeMe::getVector() const
{
    return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
    return _deque;
}


/*
** ---------------------------------------------------------------------------
**                         JACOBSTHAL NUMBERS
** ---------------------------------------------------------------------------
*/

/*
** Generate the order in which the "loser" elements are inserted.
**
** Jacobsthal sequence:
**
** J(0) = 0
** J(1) = 1
**
** J(n) = J(n - 1) + 2 * J(n - 2)
**
** => 0, 1, 1, 3, 5, 11, 21, 43, ...
**
** For Ford-Johnson we don't simply insert:
**
** 1, 2, 3, 4, 5, ...
**
** Instead we use groups based on Jacobsthal numbers:
**
** 1
** 3, 2
** 5, 4
** 11, 10, 9, 8, 7, 6
** ...
**
** This minimizes the number of comparisons used by binary search.
*/
std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t size)
{
    std::vector<size_t> order;

    if (size == 0)
        return order;

    /*
    ** We work with indices:
    **
    ** loser[0], loser[1], loser[2], ...
    **
    ** First loser is inserted directly.
    */
    order.push_back(0);

    if (size == 1)
        return order;

    /*
    ** Jacobsthal numbers.
    */
    size_t jPrev = 1;
    size_t jCurr = 3;

    /*
    ** Number of elements already inserted.
    */
    size_t inserted = 1;

    while (inserted < size)
    {
        /*
        ** Current Jacobsthal number tells us the end
        ** of the next insertion group.
        */
        size_t upper = jCurr;

        if (upper > size)
            upper = size;

        /*
        ** Insert backwards:
        **
        ** J(n), J(n)-1, ..., previous boundary + 1
        */
        size_t lower = jPrev;

        if (lower >= upper)
        {
            jPrev = jCurr;
            jCurr = jCurr + 2 * jPrev;
            continue;
        }

        size_t index = upper;

        while (index > lower && index > 0)
        {
            --index;

            /*
            ** Avoid inserting the same index twice.
            */
            bool alreadyPresent = false;

            for (size_t i = 0; i < order.size(); ++i)
            {
                if (order[i] == index)
                {
                    alreadyPresent = true;
                    break;
                }
            }

            if (!alreadyPresent && index < size)
                order.push_back(index);
        }

        inserted = order.size();

        /*
        ** Generate next Jacobsthal number safely enough
        ** for the container sizes used by this project.
        */
        if (jCurr > size * 2 + 2)
            break;

        size_t next = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = next;
    }

    /*
    ** Safety:
    ** If some indices were not generated because of the size,
    ** append them in normal order.
    */
    for (size_t i = 0; i < size; ++i)
    {
        bool alreadyPresent = false;

        for (size_t j = 0; j < order.size(); ++j)
        {
            if (order[j] == i)
            {
                alreadyPresent = true;
                break;
            }
        }

        if (!alreadyPresent)
            order.push_back(i);
    }

    return order;
}


/*
** ---------------------------------------------------------------------------
**                         VECTOR BINARY SEARCH
** ---------------------------------------------------------------------------
*/

/*
** Search for "value" in the first "end" elements of chain.
**
** Returns the position where value must be inserted.
**
** Example:
**
** chain = [2, 5, 8, 12]
** value = 7
**
** binary search returns 2
**
** because:
**
** [2, 5] | [8, 12]
**          ^
**          position 2
*/
size_t PmergeMe::binarySearchVector(
    const std::vector<int>& chain,
    int value,
    size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t middle = left + (right - left) / 2;

        if (chain[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}


/*
** ---------------------------------------------------------------------------
**                         DEQUE BINARY SEARCH
** ---------------------------------------------------------------------------
*/

size_t PmergeMe::binarySearchDeque(
    const std::deque<int>& chain,
    int value,
    size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t middle = left + (right - left) / 2;

        if (chain[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}


/*
** ---------------------------------------------------------------------------
**                       FORD-JOHNSON : VECTOR
** ---------------------------------------------------------------------------
*/

/*
** Ford-Johnson / Merge-Insertion sort.
**
** Main idea:
**
** 1. Split numbers into pairs.
**
**       8 3
**       7 2
**       6 9
**       5 1
**
** 2. Sort every pair:
**
**       3 8
**       2 7
**       6 9
**       1 5
**
** 3. Separate each pair into:
**
**       small -> "loser"
**       large -> "winner"
**
**       small: 3 2 6 1
**       large: 8 7 9 5
**
** 4. Recursively sort the winners.
**
** 5. Start the main chain with:
**
**       smallest loser + sorted winners
**
** 6. Insert the remaining losers according to
**    Jacobsthal order using binary search.
*/
void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    /*
    ** Base case.
    */
    if (v.size() <= 1)
        return;

    /*
    ** Odd element.
    **
    ** If the number of elements is odd, keep the last
    ** element separately and insert it at the end.
    */
    bool hasOdd = (v.size() % 2 != 0);
    int oddValue = 0;

    if (hasOdd)
        oddValue = v[v.size() - 1];

    /*
    ** -----------------------------------------------------------------------
    ** STEP 1: CREATE PAIRS
    ** -----------------------------------------------------------------------
    */

    std::vector< std::pair<int, int> > pairs;

    size_t pairCount = v.size() / 2;

    for (size_t i = 0; i < pairCount; ++i)
    {
        int first = v[i * 2];
        int second = v[i * 2 + 1];

        /*
        ** Always store:
        **
        ** first  = smaller
        ** second = larger
        */
        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 2: EXTRACT WINNERS
    ** -----------------------------------------------------------------------
    **
    ** Example:
    **
    ** pairs:
    **
    ** (3,8)
    ** (2,7)
    ** (6,9)
    ** (1,5)
    **
    ** winners:
    **
    ** 8 7 9 5
    */
    std::vector<int> winners;

    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 3: RECURSIVELY SORT WINNERS
    ** -----------------------------------------------------------------------
    */
    fordJohnsonVector(winners);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 4: CREATE MAIN CHAIN
    ** -----------------------------------------------------------------------
    **
    ** The smallest element of every pair belongs to a loser.
    **
    ** The first loser can be inserted immediately because it is smaller
    ** than its corresponding winner.
    */
    std::vector<int> mainChain;

    if (!pairs.empty())
    {
        /*
        ** Find the loser associated with the smallest winner.
        **
        ** Because winners have been sorted, find which original pair
        ** contains winners[0].
        */
        int smallestWinner = winners[0];
        int firstLoser = 0;

        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == smallestWinner)
            {
                firstLoser = pairs[i].first;
                break;
            }
        }

        mainChain.push_back(firstLoser);
    }

    /*
    ** Add all sorted winners.
    */
    for (size_t i = 0; i < winners.size(); ++i)
        mainChain.push_back(winners[i]);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 5: COLLECT REMAINING LOSERS
    ** -----------------------------------------------------------------------
    */
    std::vector<int> losers;

    /*
    ** We need the loser corresponding to each winner.
    */
    for (size_t i = 0; i < winners.size(); ++i)
    {
        int winner = winners[i];

        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == winner)
            {
                /*
                ** The loser of the smallest winner was already inserted.
                */
                if (winner != winners[0])
                    losers.push_back(pairs[j].first);

                break;
            }
        }
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 6: JACOBSTHAL INSERTION
    ** -----------------------------------------------------------------------
    */
    std::vector<size_t> order =
        generateJacobsthalOrder(losers.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t loserIndex = order[i];

        if (loserIndex >= losers.size())
            continue;

        int value = losers[loserIndex];

        /*
        ** Binary search over the whole currently sorted chain.
        */
        size_t position =
            binarySearchVector(mainChain, value, mainChain.size());

        mainChain.insert(
            mainChain.begin() + position,
            value);
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 7: INSERT ODD ELEMENT
    ** -----------------------------------------------------------------------
    */
    if (hasOdd)
    {
        size_t position =
            binarySearchVector(mainChain, oddValue, mainChain.size());

        mainChain.insert(
            mainChain.begin() + position,
            oddValue);
    }

    /*
    ** Replace original vector.
    */
    v = mainChain;
}


/*
** ---------------------------------------------------------------------------
**                       FORD-JOHNSON : DEQUE
** ---------------------------------------------------------------------------
*/

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    /*
    ** Base case.
    */
    if (d.size() <= 1)
        return;

    /*
    ** Odd element.
    */
    bool hasOdd = (d.size() % 2 != 0);
    int oddValue = 0;

    if (hasOdd)
        oddValue = d[d.size() - 1];

    /*
    ** -----------------------------------------------------------------------
    ** STEP 1: CREATE PAIRS
    ** -----------------------------------------------------------------------
    */

    std::deque< std::pair<int, int> > pairs;

    size_t pairCount = d.size() / 2;

    for (size_t i = 0; i < pairCount; ++i)
    {
        int first = d[i * 2];
        int second = d[i * 2 + 1];

        if (first > second)
            std::swap(first, second);

        pairs.push_back(std::make_pair(first, second));
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 2: EXTRACT WINNERS
    ** -----------------------------------------------------------------------
    */

    std::deque<int> winners;

    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 3: RECURSIVELY SORT WINNERS
    ** -----------------------------------------------------------------------
    */

    fordJohnsonDeque(winners);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 4: CREATE MAIN CHAIN
    ** -----------------------------------------------------------------------
    */

    std::deque<int> mainChain;

    if (!pairs.empty())
    {
        int smallestWinner = winners[0];
        int firstLoser = 0;

        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs[i].second == smallestWinner)
            {
                firstLoser = pairs[i].first;
                break;
            }
        }

        mainChain.push_back(firstLoser);
    }

    /*
    ** Add sorted winners.
    */
    for (size_t i = 0; i < winners.size(); ++i)
        mainChain.push_back(winners[i]);

    /*
    ** -----------------------------------------------------------------------
    ** STEP 5: COLLECT LOSERS
    ** -----------------------------------------------------------------------
    */

    std::deque<int> losers;

    for (size_t i = 0; i < winners.size(); ++i)
    {
        int winner = winners[i];

        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].second == winner)
            {
                if (winner != winners[0])
                    losers.push_back(pairs[j].first);

                break;
            }
        }
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 6: GENERATE JACOBSTHAL ORDER
    ** -----------------------------------------------------------------------
    **
    ** We use the same helper as the vector implementation.
    */
    std::vector<size_t> order =
        generateJacobsthalOrder(losers.size());

    /*
    ** -----------------------------------------------------------------------
    ** STEP 7: INSERT LOSERS
    ** -----------------------------------------------------------------------
    */

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t loserIndex = order[i];

        if (loserIndex >= losers.size())
            continue;

        int value = losers[loserIndex];

        size_t position =
            binarySearchDeque(mainChain, value, mainChain.size());

        mainChain.insert(
            mainChain.begin() + position,
            value);
    }

    /*
    ** -----------------------------------------------------------------------
    ** STEP 8: INSERT ODD ELEMENT
    ** -----------------------------------------------------------------------
    */

    if (hasOdd)
    {
        size_t position =
            binarySearchDeque(mainChain, oddValue, mainChain.size());

        mainChain.insert(
            mainChain.begin() + position,
            oddValue);
    }

    /*
    ** Replace original deque.
    */
    d = mainChain;
}


/*
** ---------------------------------------------------------------------------
**                              PUBLIC SORT
** ---------------------------------------------------------------------------
*/

void PmergeMe::sortVector(std::vector<int>& v)
{
    fordJohnsonVector(v);
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
    fordJohnsonDeque(d);
}