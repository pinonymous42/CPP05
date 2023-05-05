#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << MAGENTA << "ShrubberyCreationForm's default constructor called" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << MAGENTA << "ShrubberyCreationForm's constructor called" << DEFAULT << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << MAGENTA << "ShrubberyCreationForm's destructor called" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form):AForm(form)
{
	this->_target = form.getTarget();
	std::cout << MAGENTA << "ShrubberyCreationForm's copy constructor called" << DEFAULT << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
		AForm::operator=(form);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (this->getSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getNeededExe())
		throw AForm::GradeTooLowException();
	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs)
	{
		std::cout << MAGENTA << "cannot open the file" << DEFAULT << std::endl;
		std::exit(1);
	}
	ofs << "                                                 " << std::endl;
	ofs << "                                  .         ;    " << std::endl;
	ofs << "     .              .              ;%     ;;     " << std::endl;
	ofs << "       ,           ,                :;%  %;      " << std::endl;
	ofs << "        :         ;                   :;%;'     ." << std::endl;
	ofs << ".        %;     %;            ;        %;'    ,; " << std::endl;
	ofs << " ;       ;%;  %%;        ,     %;    ;%;    ,%'  " << std::endl;
	ofs << "  %;       %;%;      ,  ;       %;  ;%;   ,%;'   " << std::endl;
	ofs << "   ;%;      %;        ;%;        % ;%;  ,%;'     " << std::endl;
	ofs << "    `%;.     ;%;     %;'         `;%%;.%;'       " << std::endl;
	ofs << "     `:;%.    ;%%. %@;        %; ;@%;%'          " << std::endl;
	ofs << "        `:%;.  :;bd%;          %;@%;'            " << std::endl;
	ofs << "          `@%:.  :;%.         ;@@%;'             " << std::endl;
	ofs << "            `@%.  `;@%.      ;@@%;               " << std::endl;
	ofs << "              `@%%. `@%%    ;@@%;                " << std::endl;
	ofs << "                ;@%. :@%%  %@@%;                 " << std::endl;
	ofs << "                  %@bd%%%bd%%:;                  " << std::endl;
	ofs << "                    #@%%%%%:;;                   " << std::endl;
	ofs << "                    %@@%%%::;                    " << std::endl;
	ofs << "                    %@@@%(o);  . '               " << std::endl;
	ofs << "                    %@@@o%;:(.,'                 " << std::endl;
	ofs << "                `.. %@@@o%::;                    " << std::endl;
	ofs << "                   `)@@@o%::;                    " << std::endl;
	ofs << "                    %@@(o)::;                    " << std::endl;
	ofs << "                   .%@@@@%::;                    " << std::endl;
	ofs << "                   ;%@@@@%::;.                   " << std::endl;
	ofs << "                  ;%@@@@%%:;;;.                  " << std::endl;
	ofs << "              ...;%@@@@@%%:;;;;,..               " << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}