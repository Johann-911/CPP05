#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    if(formName == formNames[0])
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if(formName == formNames[1])
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
}