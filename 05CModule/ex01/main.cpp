#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "Form tests - no exceptions" << std::endl;
	try
	{
		Form fa("New building", 49, 40);
		Form fb(fa);
		Form fc("Repair something", 1, 1);
		fc = fb;
		std::cout << "Fa: "<< fa << "Fb: " << fb << "Fc: " << fc << std::endl;

		Bureaucrat a("Angela", 49);
		a.signForm(fa);
		std::cout << "Fa: " << fa << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) 
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooLowException &e) 
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e) 
	{
		std::cerr << "Should never happen! - " << e.what();
	}

	std::cout << std::endl << "Form tests - bad constructor values" << std::endl;
	try
	{
		Form fa("Building", 0, 50);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Expected! - " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}

	try
	{
		Form fa("Building", 50, 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Expected! - " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}

	try
	{
		Form fa("Building", 151, 50);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Expected! - " << e.what() << std::endl;
	}

	try
	{
		Form fa("Building", 50, 151);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Expected! - " << e.what() << std::endl;
	}

	std::cout << std::endl << "Overall test - Bureaucrat + form" << std::endl;
	try
	{
		Form shouldNotSing("Should not sign", 30, 20);
		Form shouldSign("Should sign", 100, 100);
		Bureaucrat ba("Angela", 50);

		ba.signForm(shouldNotSing);
		ba.signForm(shouldSign);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << "Should never happen! - " << e.what();
	}

}
