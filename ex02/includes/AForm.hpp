#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define DEFAULT "\033[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, int neededSign, int neededExe);
		virtual ~AForm();
		AForm(const AForm &Aform);
		AForm &operator=(const AForm &Aform);
		virtual std::string getName() const;
		virtual bool getSigned() const;
		virtual int	getNeededSign() const;
		virtual int getNeededExe() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) = 0;
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
		class FormIsNotSignedException: public std::exception
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

std::ostream &operator<<(std::ostream &ostr, const AForm &Aform);
#endif