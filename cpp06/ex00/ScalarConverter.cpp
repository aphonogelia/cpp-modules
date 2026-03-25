/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:57:15 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/16 18:18:26 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*******************************************************************************

Type conversion in C++ can be implicit or explicit. The subject wants you to si-
mulate what happens in C++: once you know the real type, you convert it to the
other types using C++'s type conversion mechanisms, not by parsing the string
multiple times


Type	Size		Range (approx.)			Precision	Sig./Unsig.	Usage
--------------------------------------------------------------------------------
int		4 bytes		−2,147,483,648 +...47	Int only	Both		Whole nb
char	1 byte		−128 to 127 / 0 to 255	N/A			Both		Chars, bytes
float	4 bytes		~±3.4E38				~7 digits	Sig. only
Decimals double	8 bytes		~±1.7E308				~15 digits
Sig. only	Dec ++precis


To Type		C++98 Method				Example
--------------------------------------------------------------------------------
int			std::stringstream			ss >> i;
                        atoi						atoi(str.c_str())
                        sscanf						sscanf(str.c_str(), "%d",
&i) float		std::stringstream			ss >> f; atof + cast
static_cast<float>(atof(str.c_str()))
                        sscanf						sscanf(str.c_str(), "%f",
&f) double		std::stringstream			ss >> d; atof
atof(str.c_str()) sscanf						sscanf(str.c_str(), "%lf",
&d)

>> In C++98, prefer std::stringstream for type safety and flexibility.
>> Use atoi, atof, or sscanf for simpler or legacy code.
>> No std::stoi, std::stof, or std::stod exist in C++98.

*******************************************************************************/

#include "ScalarConverter.hpp"

/////////////////////////
// 	Coplien Form 	//
/////////////////////////
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

/////////////////////////
// 	  Exception		//
/////////////////////////
const char* ScalarConverter::invalidInputException::what() const throw() {
    return ("char: NA\nint: NA\nfloat: NA\ndouble: NA");
}

/////////////////////////
// 	convert 		//
/////////////////////////
void ScalarConverter::convert(const std::string& input) {
    bool handled = false;

    validInput(input);
    handleChar(input, &handled);
    pseudoliterals(input, &handled);
    handleInt(input, &handled);
    handleFloat(input, &handled);
    handleDouble(input, &handled);

    if (!handled) throw(ScalarConverter::invalidInputException());
}

/////////////////////////
// 	HELPERS 		//
/////////////////////////

// check for empty string and empty spaces inside the string and failed conversion
void ScalarConverter::validInput(const std::string& input) {
    if (input.length() == 0) throw(ScalarConverter::invalidInputException());

    std::string a;
    std::string b;
    std::stringstream ss(input);
    ss >> a;
    ss >> b;
    if (!ss.fail()) throw(ScalarConverter::invalidInputException());
    return;
}

// character - length is 1 and not a digit
void ScalarConverter::handleChar(const std::string& input, bool* handled) {
    int n;
    std::stringstream ss(input);
    ss >> n;
    if (input.length() == 1 && ss.fail()) {
        char c = input[0];
        std::cout << GREEN << "char: '" << c << "'\n";
        std::cout << BLUE << "int: "
                  << "NA\n";
        std::cout << "float: "
                  << "NA\n";
        std::cout << "double: "
                  << "NA\n"
                  << RESET;
        *handled = true;
    }
}

// pseudoliterals
void ScalarConverter::pseudoliterals(const std::string& input, bool* handled) {
    if (*handled) return;

    std::string a;
    std::stringstream ss(input);
    ss >> a;
    if (!(a == "+inf" || a == "+inff" || a == "-inf" || a == "-inff" || a == "nan" || a == "nanf"))
        return;

    if (a == "+inf" || a == "-inf" || a == "nan") {
        double d = 0;
        if (a == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (a == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else if (a == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        std::cout << BLUE << "char: NA\n";
        std::cout << "int: NA\n";
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << GREEN << "double: " << d << RESET << "\n";
    }

    else if (a == "+inff" || a == "-inff" || a == "nanf") {
        float f = 0;
        if (a == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (a == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else if (a == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        std::cout << BLUE << "char: NA\n";
        std::cout << "int: NA\n";
        std::cout << GREEN << "float: " << f << "f\n";
        std::cout << BLUE << "double: " << static_cast<double>(f) << RESET << "\n";
    }

    *handled = true;
}

// integers - using stringstream to handle the white spaces
void ScalarConverter::handleInt(const std::string& input, bool* handled) {
    if (*handled) return;

    int n;
    std::stringstream ss(input);
    ss >> n;
    if (!ss.fail() && ss.eof()) {
        // char
        if ((n < 32 && n >= 0) || (n == 127))
            std::cout << BLUE << "char: Not printable\n";
        else if (n < 0 || n > 126)
            std::cout << BLUE << "char: NA\n";
        else
            std::cout << BLUE << "char: '" << static_cast<char>(n) << "'\n";
        // int
        std::cout << GREEN << "int: " << n << "\n";
        // float and double
        std::cout << std::fixed << std::setprecision(1);
        std::cout << BLUE << "float: " << static_cast<float>(n) << "f\n";
        std::cout << BLUE << "double: " << static_cast<double>(n) << "\n" << RESET;
        *handled = true;
    }
}

// FLOAT
void ScalarConverter::handleFloat(const std::string& input, bool* handled) {
    if (*handled) return;

    size_t posF = input.find('f');
    size_t posE = input.find('e');
    size_t posPt = input.find('.');
    if (!(posF != std::string::npos && (posE != std::string::npos || posPt != std::string::npos)))
        return;

    float f;
    char c;
    char temp;
    std::stringstream ss(input);
    ss >> f;
    if (!ss.fail() && !ss.eof()) {
        ss >> c;
        ss >> temp;

        if (ss.fail() && ss.eof() && c == 'f') {
            // char
            if ((f < 32 && f >= 0) || (f == 127))
                std::cout << BLUE << "char: Not printable\n";
            else if (f < 0 || f > 126)
                std::cout << BLUE << "char: NA\n";
            else
                std::cout << BLUE << "char: '" << static_cast<char>(f) << "'\n";
            // int
            if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
                std::cout << "int: NA\n";
            else {
                std::cout << "int: " << static_cast<int>(f) << "\n";
                if (std::fabs(f - static_cast<int>(f)) < 1e-6) {
                    std::cout << std::fixed << std::setprecision(1);
                }
            }
            // float
            std::cout << GREEN << "float: " << f << "f\n";
            // double
            std::cout << BLUE << "double: " << static_cast<double>(f) << "\n" << RESET;
            *handled = true;
        }
    }
}

// DOUBLE
void ScalarConverter::handleDouble(const std::string& input, bool* handled) {
    if (*handled) return;

    size_t posE = input.find('e');
    size_t posPt = input.find('.');
    if (posE == std::string::npos && posPt == std::string::npos) return;

    double d;
    std::stringstream ss(input);
    ss >> d;
    if (!ss.fail() && ss.eof()) {
        // char
        if ((d < 32 && d >= 0) || (d == 127))
            std::cout << BLUE << "char: Not printable\n";
        else if (d < 0 || d > 126)
            std::cout << BLUE << "char: NA\n";
        else
            std::cout << BLUE << "char: '" << static_cast<char>(d) << "'\n";
        // int
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: NA\n";
        else {
            std::cout << "int: " << static_cast<int>(d) << "\n";
            if (std::fabs(d - static_cast<int>(d)) < 1e-6) {
                std::cout << std::fixed << std::setprecision(1);
            }
        }
        // float
        if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
            std::cout << "float: NA\n";
        else
            std::cout << "float: " << static_cast<float>(d) << "f\n";
        // double
        std::cout << GREEN << "double: " << d << "\n" << RESET;

        *handled = true;
    }
}
