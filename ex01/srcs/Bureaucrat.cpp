#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("unknown"), _grade(150)
{
	std::cout << RED << "Bureaucrat's default constructor called" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):_name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << RED << "Bureaucrat's constructor called" << DEFAULT << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat's destructor called" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):_name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
	std::cout << RED << "Bureaucrat's copy constructor called" << DEFAULT << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		const_cast<std::string &>(this->_name) = bureaucrat.getName();
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	(this->_grade)--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	(this->_grade)++;
}

std::ostream &operator<<(std::ostream &ostr, const Bureaucrat &bureaucrat)
{
	ostr << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (ostr);
}

void	Bureaucrat::signForm(const Form &form)
{
	try
	{
		const_cast<Form &>(form).beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
	
}