#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) 
{
    if(this != &copy)
    {
        AForm::operator=(copy);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    (void)executor;

    int random = std::rand() % 2;
    if(random == 0)
    {
        std::cout << "Bzzzzzz Bzzzz " << this->_target << " has been robotomized " << std::endl;

    }
    else
    {
        std::cout << this->_target << " robotomy has failed " << std::endl;
    }
}

