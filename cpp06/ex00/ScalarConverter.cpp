#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

// Private constructors (prevent instantiation)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

static void handlePseudo(const std::string& str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str[str.length() - 1] == 'f')
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

static bool isCharLiteral(const std::string& str)
{
    return (str.length() == 1 && !isdigit(str[0]));
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudo(literal);
        return;
    }

    double value;
    char* end;

    value = std::strtod(literal.c_str(), &end);

    // Special case: single char like 'a'
    if (isCharLiteral(literal))
        value = static_cast<double>(literal[0]);

    // If invalid input
    if (*end != '\0' && !(literal.length() == 1))
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // FLOAT
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    // DOUBLE
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}