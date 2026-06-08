#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
#include <iostream>
#include "Form.hpp"
#include <exception>
#include "Form.hpp" 

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
        void signForm(Form &f);
        void incrementGrade();
        void decrementGrade();
        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
