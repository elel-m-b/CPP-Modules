#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>

// Private constructors (prevent instantiation)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& str)
{
    return (str == "nan"   ||str == "-nan"  ||str == "nanf"  ||str == "-nanf" ||str == "+inf"  ||str == "+inff" ||str == "-inf"  ||str == "-inff");
}

static void handlePseudo(const std::string& str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    // Already a float pseudo literal
    if (str == "nanf" || str == "-nanf" ||str == "+inff" || str == "-inff")
    {
        std::cout << "float: " << str << std::endl;

        // Remove only the float suffix
        if (str == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (str == "-nanf")
            std::cout << "double: -nan" << std::endl;
        else if (str == "+inff")
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    // Double pseudo literal
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

// Formats a value without truncating its precision like setprecision(1) did.
// Appends ".0" if the result has no decimal point, and "f" if it's a float.
static std::string formatScalar(double v, bool isFloat)
{
    std::ostringstream oss;
    if (isFloat)
        oss << static_cast<float>(v);
    else
        oss << v;
    std::string s = oss.str();
    if (s.find('.') == std::string::npos && s.find('e') == std::string::npos)
        s += ".0";
    if (isFloat)
        s += "f";
    return s;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudo(literal);
        return;
    }

    // Detect and strip a trailing float suffix ('f'/'F') BEFORE parsing,
    // e.g. "42.0f" -> "42.0" with isFloatLiteral = true.
    std::string numStr = literal;
    if (numStr.length() > 1 && (numStr[numStr.length() - 1] == 'f' || numStr[numStr.length() - 1] == 'F') && !isCharLiteral(literal))
    {
        numStr.erase(numStr.length() - 1);
    }

    double value;
    char* end;

    value = std::strtod(numStr.c_str(), &end);

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
    if (!std::isnan(value) && !std::isinf(value) &&(value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << formatScalar(value, true) << std::endl;

    // DOUBLE
    std::cout << "double: ";
    std::cout << formatScalar(value, false) << std::endl;
}