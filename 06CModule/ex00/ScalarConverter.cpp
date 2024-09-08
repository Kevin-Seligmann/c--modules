#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const & rhs){(void) rhs;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){(void) rhs; return *this;}

void ScalarConverter::convert(std::string & literal)
{
	ScalarConverter converter = ScalarConverter();

	if (converter._isPseudoLiteral(literal))
	{
		converter._printPseudoLiteral(literal);
	}
	else if (converter._isChar(literal))
	{
		converter._printChar(literal);
	}
	else if (converter._isInt(literal))
	{
		converter._printInt(literal);
	}
	else if (converter._isFloat(literal))
	{
		converter._printFloat(literal);
	}
	else if (converter._isDouble(literal))
	{
		converter._printDouble(literal);
	}
	else
	{
		std::cerr << "Invalid literal" << std::endl;
	}
}

bool ScalarConverter::_isPseudoLiteral(std::string & literal) const
{
	return (literal == "+inf" \
	|| literal == "-inf" \
	|| literal == "nan" \
	|| literal == "+inff" \
	|| literal == "-inff" \
	|| literal == "nanf");
}

bool ScalarConverter::_isChar(std::string & literal) const
{
	return (literal.length() == 3 && literal.at(0) == '\'' && literal.at(2) == '\'');
}

bool ScalarConverter::_isInt(std::string & literal) const
{
	std::string::iterator a = literal.begin();

	if (*a == '+' || *a == '-')
	{
		a++;
	}
	while (a != literal.end())
	{
		if (!isdigit(*a))
		{
			return false;
		}
		a ++;
	}
	return true;
}

bool ScalarConverter::_isFloat(std::string & literal) const
{
	std::string::iterator a = literal.begin();
	bool point = false;

	if (literal.length() < 3 || *(literal.end() - 1) != 'f' || *literal.begin() == '.')
	{
		return false;
	}
	if (*a == '+' || *a == '-')
	{
		a++;
	}
	while (a != literal.end())
	{
		if (*a == '.')
		{
			if (point == true)
			{
				return false;
			}
			else
			{
				point = true;
			}
		}
		else if (!isdigit(*a) && a != literal.end() - 1)
		{
			return false;
		}
		a++ ;
	}
	return point;
}

bool ScalarConverter::_isDouble(std::string & literal) const
{
	bool point = false;
	std::string::iterator a = literal.begin();

	if (literal.length() < 2)
	{
		return false;
	}
	if (*a == '+' || *a == '-')
	{
		a++;
	}
	while (a != literal.end())
	{
		if (*a == '.')
		{
			if (point == true)
			{
				return false;
			}
			else
			{
				point = true;
			}
		}
		else if (!isdigit(*a))
		{
			return false;
		}
		a++;
	}
	return point;
}

void ScalarConverter::_printPseudoLiteral(std::string & literal) const
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
	{
		literal.erase(literal.end() - 1);
	}
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void ScalarConverter::_printChar(std::string & literal) const
{
	char c = literal.at(1);

	if (isprint(c))
	{
		std::cout << literal.substr(1, 1) << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << static_cast<float>(c) << std::endl;
	std::cout << static_cast<double>(c) << std::endl;
}

void ScalarConverter::_printInt(std::string & literal) const
{
	std::stringstream stream(literal);
	int i = 0;
	stream >> i;
	
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(i);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::_printFloat(std::string & literal) const
{
	std::stringstream stream(literal);
	float f = 0;
	stream >> f;

	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(f);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
	{
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "float " << f << std::endl;
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::_printDouble(std::string & literal) const
{
	std::stringstream stream(literal);
	double d = 0;
	stream >> d;

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
	{
		std::cout << "char: Impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(d);
		std::string s;
		s.push_back(c);
		if (isprint(c))
		{
			std::cout << "char: " << s << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
	{
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float: Impossible" << std::endl;
	}
	else
	{
		std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "float: " << static_cast<float>(d) << std::endl;
	}
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << "double: " << d << std::endl;
}
