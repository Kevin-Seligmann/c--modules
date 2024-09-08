#include <iostream>
#include <cstdlib>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf  << std::endl;;
	delete rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf << std::endl;;
	delete rrf;
	std::cout << std::endl;
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << *rrf << std::endl;;
	delete rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("NO NO NO !!! ", "Bender");

}
