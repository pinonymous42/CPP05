#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		std::string form_name = "form no ";
		Bureaucrat bureaucrat("Kohei", 2);
		// for (int i = 5; i >= 0; --i)
		for (int i = 5; i >= 1; --i)
		{
			Form form(form_name + std::to_string(i), i, i);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}