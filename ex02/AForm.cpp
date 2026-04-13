/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:39:04 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/10 14:19:49 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

AForm::AForm() : _name("Default AForm"), _is_signed(false) , GradeToSign(150), GradeToExecute(150) {
		std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int GradeTosign, int GradeToExecute) : _name(name),GradeToSign(GradeTosign), GradeToExecute(GradeToExecute) {
	std::cout << "AForm constructor called" << std::endl;
	this->_is_signed = false;
	if (GradeTosign > 150 || GradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (GradeTosign < 1 || GradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy) : GradeToSign(copy.GradeToSign), GradeToExecute(copy.GradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName()const {
	return this->_name;
}

AForm& AForm::operator=(const AForm &copy) {
	this->_is_signed = copy._is_signed;
	return *this;
}

const bool& AForm::getSigned()const {
	return this->_is_signed;
}

const int& AForm::getGradeToSign()const {
	return this->GradeToSign;
}

const  int& AForm::getGradeToExecute()const {
	return this->GradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->GradeToSign >= bureaucrat.getGrade())
		this->_is_signed = true;
	else
		throw AForm::GradeTooLowException();   
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm : Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm : Grade too low");
}

const char*  AForm::FormNotSigned::what() const throw () {
	return ("Form not signed");
}

std::ostream& operator<<(std::ostream& os, AForm& AForm) {
	std::string SignedOrNot[2];
	SignedOrNot[true] = "is signed";
	SignedOrNot[false] = "is not signed";
	os << AForm.getName()
		<< "'s AForm " 
		<< SignedOrNot[AForm.getSigned()]
		<< " with grade to sign "
		<< AForm.getGradeToSign()
		<< " and grade to execute "
		<< AForm.getGradeToExecute()
		<< std::endl;
	return (os);
} 