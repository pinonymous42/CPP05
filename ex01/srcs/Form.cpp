#include "Form.hpp"

Form::Form():_name("unknown"), _signed(false), _neededSign(150), _neededExe(150)
{
	std::cout << GREEN << "Form's default constructor called" << DEFAULT << std::endl;
}

Form::Form(const std::string &name, int neededSign, int neededExe):_name(name), _signed(false),
	_neededSign(neededSign), _neededExe(neededExe)
{
	if (neededSign < 1 || neededExe < 1)
		throw Form::GradeTooHighException();
	if (neededSign > 150 || neededExe > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Form's constructor called" << DEFAULT << std::endl;
}

Form::~Form()
{
	std::cout << GREEN << "Form's destructor called" << DEFAULT << std::endl;
}

Form::Form(const Form &form):_name(form.getName()), _signed(false),
	_neededSign(form.getNeededSign()), _neededExe(form.getNeededExe())
{
	std::cout << GREEN << "Form's copy constructor called" << DEFAULT << std::endl;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
	{
		const_cast<std::string &>(this->_name) = form.getName();
		this->_signed = form.getSigned();
		const_cast<int &>(this->_neededSign) = form.getNeededSign();
		const_cast<int &>(this->_neededExe) = form.getNeededExe();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getNeededSign() const
{
	return (this->_neededSign);
}

int Form::getNeededExe() const
{
	return (this->_neededExe);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed == true)
		return ;
	if (bureaucrat.getGrade() > this->_neededSign)
		throw Form::GradeTooLowException();
	std::cout << GREEN << this->_name << " is signed by " << bureaucrat.getName() << DEFAULT << std::endl;
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

std::ostream &operator<<(std::ostream &ostr, const Form &form)
{
	ostr << GREEN << "Form's information" << DEFAULT << std::endl;
	ostr << GREEN << "name: " << form.getName() << DEFAULT << std::endl;
	ostr << GREEN << "signed: " << form.getSigned() << DEFAULT << std::endl;
	ostr << GREEN << "needed Sign: " << form.getNeededSign() << DEFAULT << std::endl;
	ostr << GREEN << "needed Execute: " << form.getNeededExe() << DEFAULT << std::endl;
	return (ostr);
}
