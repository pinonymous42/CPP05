#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		AForm *makeForm(const std::string &name, const std::string &target);
};
#endif