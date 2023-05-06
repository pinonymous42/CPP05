#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern's default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern's destructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
	std::cout << "Intern's copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	int	i = 0;
	AForm *ret = NULL;
	std::string form[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	while (i < 3 && name != form[i])
		i++;
	try
	{
		switch(i)
		{
			case 0:
				ret = new PresidentialPardonForm(target);
				std::cout << "Intern creates " << name << std::endl;
				break ;
			case 1:
				ret = new RobotomyRequestForm(target);
				std::cout << "Intern creates " << name << std::endl;
				break ;
			case 2:
				ret = new ShrubberyCreationForm(target);
				std::cout << "Intern creates " << name << std::endl;
				break ;
			default:
				std::cerr << "Invalid input" << std::endl;
		}
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (ret);
}