#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "No exception tests"<< std::endl;
	try
	{
		Bureaucrat a("Angela", 50);
		std::cout << "Angela " << a << std::endl;
		a.decrementGrade();
		std::cout << "Angela " << a << std::endl;
		a.incrementGrade();
		std::cout << "Angela " << a << std::endl;

		Bureaucrat b("Boris", 2);
		std::cout << "Boris " << b << std::endl;
		b.incrementGrade();
		std::cout << "Boris " << b << std::endl;
		Bureaucrat c("Cornelio", 149);
		std::cout << "Cornelio " << c << std::endl;
		c.decrementGrade();
		std::cout << "Cornelio " << c << std::endl;

		a = c;
		Bureaucrat j (b);
		std::cout << "Who? " << c << std::endl;
		std::cout << "Who? " << j << std::endl;
		std::cout << "Expected! - No exception was thrown" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Should never happen! - High threw erroneously: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - Low threw erroneously: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Too low exception tests"<< std::endl;
	try
	{
		Bureaucrat a("Angela", 151);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Should never happen! - High threw erroneously: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Expected! - Low threw correctly: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat a("Angela", 150);
		a.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Should never happen! - High threw erroneously: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Expected! - Low threw correctly: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Too high exception tests" << std::endl;
	try
	{
		Bureaucrat a("Angela", 0);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Expected! - High threw correctly: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - Low threw erroneously: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat a("Angela", 1);
		a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << "Expected! - High threw correctly: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - Low threw erroneously: " << e.what() << std::endl;
	}
}
