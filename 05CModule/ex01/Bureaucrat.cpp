#include "Bureaucrat.hpp"

// Canonic
Bureaucrat::Bureaucrat()
:_grade(MinGrade),
_name("Anonymous")
{
	std::cout << this << " 'Bureaucrat' "
	<< "Default constructor called."
	<< std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
:_grade(grade),
_name(name)
{
	if (_grade < MaxGrade)
	{
		throw GradeTooHighException();
	}
	if (_grade > MinGrade)
	{
		throw GradeTooLowException();
	}
	std::cout << this << " 'Bureaucrat'. "
	<< "Constructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
:_grade(src._grade),
_name(src._name)
{
	std::cout << this << " 'Bureaucrat'. "
	<< "Copy constructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this << " 'Bureaucrat'. "
	<< "Destructor called. " 
	<< "Name: " << _name << ". " 
	<< "Grade: " << _grade << ". "
	<< std::endl;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_name = rhs._name;
	_grade = rhs._grade;
	return *this;
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

// Members
int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == MaxGrade)
	{
		throw GradeTooHighException();
	}
	_grade --;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == MinGrade)
	{
		throw GradeTooLowException();
	}
	_grade ++;
}

void Bureaucrat::signForm(Form & form) const
{
	try 
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException & e) 
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

// Insertion
std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

