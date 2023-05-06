#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << YELLOW << "RobotomyRequestForm's default constructor called" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << YELLOW << "RobotomyRequestForm's constructor called" << DEFAULT << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm's destructor called" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form):AForm(form)
{
	this->_target = form.getTarget();
	std::cout << YELLOW << "RobotomyRequestForm's copy constructor called" << DEFAULT << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
		AForm::operator=(form);
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	int i = std::rand();
	if (this->getSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getNeededExe())
		throw AForm::GradeTooLowException();
	if (i % 2 == 0)
		std::cout << YELLOW << "pip pip pip...brrrrrrrrrrrrrrrrr..., " << this->_target << " has been robotomized" << DEFAULT << std::endl;
	else
		std::cout << YELLOW << "robotomy failed" << DEFAULT << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}