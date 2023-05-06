/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:06:51 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/29 12:23:13 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{

	Intern someRandomIntern;
	AForm *form;
	form = someRandomIntern.makeForm("Robotomy Request", "Bender");
	if (form)
		std::cout << "Name: " << form->getName() << " GradeToSign: " << form->getNeededSign() << " GradeToExecute: " << form->getNeededExe() << std::endl;
	delete form;
	form = someRandomIntern.makeForm("Presidential Pardon", "Bender");
	if (form)
		std::cout << "Name: " << form->getName() << " GradeToSign: " << form->getNeededSign() << " GradeToExecute: " << form->getNeededExe() << std::endl;
	delete form;
	form = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
	if (form)
		std::cout << "Name: " << form->getName() << " GradeToSign: " << form->getNeededSign() << " GradeToExecute: " << form->getNeededExe() << std::endl;
	delete form;
	form = someRandomIntern.makeForm("invalid form name", "Bender");
	if (form)
		std::cout << "Name: " << form->getName() << " GradeToSign: " << form->getNeededSign() << " GradeToExecute: " << form->getNeededExe() << std::endl;
	delete form;
}
