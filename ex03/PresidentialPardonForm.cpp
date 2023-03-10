#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Presidential", 72, 45)
{
    std::cout << "PresidentialPardonForm : Default Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 72, 45)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c)
{
    std::cout << "PresidentialPardonForm : Copy Constructor called\n";
    *this = c;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
    std::cout << "PresidentialPardonForm : Copy assignment operator called\n";
    this->target = c.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getsiGned() == false)
        throw(FormNotSigned());
    if (this->getGradeExecute() >= executor.getGrade())
        throw(Bureaucrat::GradeTooHighException());
    std::cout << this->target << "PresidentialPardonForm : has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm : Destructor called\n";
}
