#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <math.h>
#include <sstream>
#include <iomanip>

class ScalarConverter 
{
	public:
		static void convert(std::string & literal);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const & rhs);
		void _printPseudoLiteral(std::string & literal) const;
		void _printChar(std::string & literal) const;
		void _printInt(std::string & literal) const;
		void _printFloat(std::string & literal) const;
		void _printDouble(std::string & literal) const;
		bool _isPseudoLiteral(std::string & literal) const;
		bool _isChar(std::string & literal) const;
		bool _isInt(std::string & literal) const;
		bool _isFloat(std::string & literal) const;
		bool _isDouble(std::string & literal) const;
};

#endif
