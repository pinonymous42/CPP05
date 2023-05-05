#include "AForm.hpp"

AForm::AForm():_name("unknown"), _signed(false), _neededSign(150), _neededExe(150)
{
	std::cout << GREEN << "AForm's default constructor called" << DEFAULT << std::endl;
}

AForm::AForm(const std::string &name, int neededSign, int neededExe):_name(name), _signed(false),
	_neededSign(neededSign), _neededExe(neededExe)
{
	if (neededSign < 1 || neededExe < 1)
		throw AForm::GradeTooHighException();
	if (neededSign > 150 || neededExe > 150)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "AForm's constructor called" << DEFAULT << std::endl;
}

AForm::~AForm()
{
	std::cout << GREEN << "AForm's destructor called" << DEFAULT << std::endl;
}

AForm::AForm(const AForm &Aform):_name(Aform.getName()), _signed(false),
	_neededSign(Aform.getNeededSign()), _neededExe(Aform.getNeededExe())
{
	std::cout << GREEN << "AForm's copy constructor called" << DEFAULT << std::endl;
}

AForm &AForm::operator=(const AForm &Aform)
{
	if (this != &Aform)
	{
		const_cast<std::string &>(this->_name) = Aform.getName();
		this->_signed = Aform.getSigned();
		const_cast<int &>(this->_neededSign) = Aform.getNeededSign();
		const_cast<int &>(this->_neededExe) = Aform.getNeededExe();
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getNeededSign() const
{
	return (this->_neededSign);
}

int AForm::getNeededExe() const
{
	return (this->_neededExe);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_neededSign)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << this->_name << " is signed by " << bureaucrat.getName() << DEFAULT << std::endl;
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
	return ("The form is not signed");
}

std::ostream &operator<<(std::ostream &ostr, const AForm &Aform)
{
	ostr << GREEN << "AForm's inAformation" << DEFAULT << std::endl;
	ostr << GREEN << "name: " << Aform.getName() << DEFAULT << std::endl;
	ostr << GREEN << "signed: " << Aform.getSigned() << DEFAULT << std::endl;
	ostr << GREEN << "needed Sign: " << Aform.getNeededSign() << DEFAULT << std::endl;
	ostr << GREEN << "needed Execute: " << Aform.getNeededExe() << DEFAULT << std::endl;
	return (ostr);
}

void	AForm::setName(const std::string &name)
{
	const_cast<std::string &>(this->_name) = name;
}

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

void	AForm::setNeededSign(int neededSign)
{
	const_cast<int &>(this->_neededSign) = neededSign;
}

void	AForm::setNeededExe(int neededExe)
{
	const_cast<int &>(this->_neededExe) = neededExe;
}