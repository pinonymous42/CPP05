#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		std::string getName() const;
		int	getGrade() const;
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
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(const AForm &form);
		void	executeForm(AForm const & form);
	// protected:
	// 	void	setName(const std::string &name);
		void	setGrade(int grade);
	private:
		const std::string _name;
		int	_grade;
};

std::ostream &operator<<(std::ostream &ostr, const Bureaucrat &bureaucrat);
#endif