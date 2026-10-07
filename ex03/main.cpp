#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    try
    {

        Bureaucrat Rob("Rob", 40);
        
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        Rob.signForm(*rrf);
        Rob.executeForm(*rrf);
        delete rrf;

    }
    catch(const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}