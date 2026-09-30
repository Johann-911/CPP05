#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern 
{
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target);

};

#endif