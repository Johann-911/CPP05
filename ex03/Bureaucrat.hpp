#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp" 

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(const std::string name, int grade);        
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception 
        {
			public:
				const char* what() const noexcept override;
		};
        
        class GradeTooLowException : public std::exception 
        {
			public:
				const char* what() const noexcept override;
		};

        std::string getName() const;
        int getGrade() const;
        void signForm(AForm &f);
        void incrementGrade();
        void decrementGrade();
        void executeForm(AForm const &form) const;
        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
