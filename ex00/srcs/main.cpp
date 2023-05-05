#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("Kohei", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();

		Bureaucrat bureaucrat2("test", 3);
		bureaucrat = bureaucrat2;
		bureaucrat = bureaucrat2;
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}