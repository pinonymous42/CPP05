#ifndef SHRUBBERYREQUESTFORM_HPP
#define SHRUBBERYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
		virtual void	execute(Bureaucrat const & executor);
		std::string		getTarget() const;
	private:
		std::string _target;
};
#endif