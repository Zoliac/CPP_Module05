/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:24:26 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/13 17:06:37 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RobotomyRequestForm.hpp"
#include "includes/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default"){
	std::cout << "Default constructor called for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm("RobotomyRequestForm", 72, 45) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	this->target = copy.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw RobotomyRequestForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	
	std::cout << "Vrrrrrrrrrrrrrrrr" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
}
