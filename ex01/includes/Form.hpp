#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, int neededSign, int neededExe);
		~Form();
		Form(const Form &form);
		Form &operator=(const Form &form);
		std::string getName() const;
		bool getSigned() const;
		int	getNeededSign() const;
		int getNeededExe() const;
		void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		const std::string _name;
		bool _signed;
		const int _neededSign;
		const int _neededExe;
};

std::ostream &operator<<(std::ostream &ostr, const Form &form);
#endif