#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int minExec, const int minGrade) : _name(name), _signed(false), _minGrade(minGrade), _minExec(minExec){
    if(_minGrade < 1 || _minGrade > 150)
        throw GradeTooHighException();
    if(_minExec < 1 || _minExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _minGrade(copy._minGrade), _minExec(copy._minExec)
{
}

AForm &AForm::operator=(const AForm &copy)
{
    if(this != &copy)
    {
        _signed = copy._signed;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return _name;
} 

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToExecute() const
{
    return _minExec;
}

int AForm::getGradeToSign() const
{
    return _minGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() <= _minGrade)
    {
        _signed = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", signed: "
        << (f.isSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
