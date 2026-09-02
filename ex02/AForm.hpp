#ifndef AForm_HPP
#define AForm_HPP

#include <stdbool.h>
#include <string>
#include <iostream>
#include <exception> 

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool  _signed;
        const int _minGrade;
        const int _minExec;

    public:
        AForm(const std::string name, const int _minExec, const int _minGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        ~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif