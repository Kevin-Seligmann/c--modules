#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	srand(time(0));

	Bureaucrat a("A", 1);
	Bureaucrat b("B", 50);
	Bureaucrat c("C", 149);

	PresidentialPardonForm presidental("Bobby who stopped transit to save a kitten");
	RobotomyRequestForm robotomy("Kitten");
	ShrubberyCreationForm shrubbery2("CatTown");
	ShrubberyCreationForm shrubbery("CatTown");

	a.signForm(presidental);
	a.signForm(robotomy);
	a.signForm(shrubbery);

	std::cout << std::endl << std::endl << "Failure tests" << std::endl;

	a.executeForm(shrubbery2);
	c.executeForm(robotomy);
	c.executeForm(presidental);
	
	std::cout << std::endl << std::endl << "Success tests" << std::endl;
	
	a.executeForm(presidental);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(robotomy);
	a.executeForm(shrubbery);

}
