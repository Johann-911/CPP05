#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{

    if(this != &copy)
    {
        AForm::operator=(copy);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}