#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	std::cout << BLUE << "PresidentialPardonForm's default constructor called" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << BLUE << "PresidentialPardonForm's constructor called" << DEFAULT << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLUE << "PresidentialPardonForm's destructor called" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
{
	this->_target = form.getTarget();
	this->setName(form.getName());
	this->setSigned(form.getSigned());
	this->setNeededSign(form.getNeededSign());
	this->setNeededExe(form.getNeededExe());
	std::cout << BLUE << "PresidentialPardonForm's copy constructor called" << DEFAULT << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
		this->setName(form.getName());
		this->setSigned(form.getSigned());
		this->setNeededSign(form.getNeededSign());
		this->setNeededExe(form.getNeededExe());
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (this->getSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getNeededExe())
		throw AForm::GradeTooLowException();
	std::cout << BLUE << this->_target << " has been pardoned by Zaphod Beeblebrox" << DEFAULT << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}