#ifndef FORM_HPP
#define FORM_HPP

#include <stdbool.h>
#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool  _signed;
        const int _minGrade;
        const int _minExec;

    public:
        Form(const std::string name, const int _minExec, const int _minGrade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what () const noexcept override;
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const noexcept override;
        };
        std::string getName() const;
        void beSigned(const Bureaucrat &b);
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;



        
};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif