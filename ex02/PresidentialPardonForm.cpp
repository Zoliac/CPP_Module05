/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:19:26 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/13 17:12:13 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw PresidentialPardonForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
