#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <iostream>

int	main()
{
	try
	{
		// Bureaucrat bureaucrat("Kohei", 155); // error cace
		Bureaucrat bureaucrat("Kohei", 150);
		ShrubberyCreationForm form1("Shrubbery");
		RobotomyRequestForm form2("Robot");
		PresidentialPardonForm form3("President");

		std::cout << "sign check" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		std::cout << std::endl;

		for (int i = 155; i > 0; i -= 5) // error cace
		// for (int i = 150; i > 0; i -= 5)
		{
			bureaucrat.setGrade(i);
			std::cout << MAGENTA << "Form 1 (Shrubbery)" << DEFAULT << std::endl;
			bureaucrat.signForm(form1);
			bureaucrat.executeForm(form1);
			std::cout << YELLOW << "Form 2 (Robotomy)" << DEFAULT << std::endl;
			bureaucrat.signForm(form2);
			bureaucrat.executeForm(form2);
			std::cout << BLUE << "Form 3 (President)" << DEFAULT << std::endl;
			bureaucrat.signForm(form3);
			bureaucrat.executeForm(form3);
			std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
