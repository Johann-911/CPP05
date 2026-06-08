#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int minGrade, const int minExec) : _name(name), _signed(false), _minGrade(minGrade), _minExec(minExec){
    if(_minGrade < 1 || _minGrade > 150)
        throw GradeTooHighException();
    if(_minExec < 1 || _minExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _minGrade(copy._minGrade), _minExec(copy._minExec)
{
}

Form &Form::operator=(const Form &copy)
{
    if(this != &copy)
    {
        _signed = copy._signed;
    }
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return _name;
} 

bool Form::isSigned() const
{
    return _signed;
}

int Form::getGradeToExecute() const
{
    return _minExec;
}

int Form::getGradeToSign() const
{
    return _minGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() <= _minGrade)
    {
        _signed = true;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", signed: "
        << (f.isSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
