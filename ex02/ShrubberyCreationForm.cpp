#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),  _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if(this != &copy) 
    {
        AForm::operator=(copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    (void)executor;

    std::ofstream file(_target + "_shrubbery");
    if(!file)
        throw std::runtime_error(" could not create shrubbery file");
    file << "       ^       " << std::endl;
    file << "      ^^^      " << std::endl;
    file << "     ^^^^^     " << std::endl;
    file << "       |       " << std::endl;

}