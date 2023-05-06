#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &form);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
		virtual void	execute(Bureaucrat const & executor);
		std::string		getTarget() const;
	private:
		std::string _target;
};

#endif