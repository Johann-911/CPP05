#include "Bureaucrat.hpp"
#include "AForm.hpp" 
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    try
    {
        RobotomyRequestForm RoboForm("RoboForm");
        ShrubberyCreationForm form("home");
        PresidentialPardonForm PresiForm("Pardon");

        Bureaucrat Rob("Rob", 40);
        Bureaucrat alice("Alice", 100);
        Bureaucrat Bob("Bob", 150);
        Bureaucrat boss("Boss", 5);

        Bob.executeForm(form);
        Rob.signForm(RoboForm);
        Rob.executeForm(RoboForm);

        boss.signForm(PresiForm);
        boss.executeForm(PresiForm);
        
        alice.signForm(form);
        alice.executeForm(form);
    }
    catch(const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}