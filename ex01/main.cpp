#include "Bureaucrat.hpp"
#include "Form.hpp" 

int main()
{
    try
    {
        Form f1("TaxForm", 50, 10);
        std::cout << f1 << std::endl;

        Bureaucrat b1("Alice", 30);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
        
        Bureaucrat b2("Bob", 60);
        b2.signForm(f1);   
    }
    catch(const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}