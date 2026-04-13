/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:22:35 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/09 13:32:44 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75){
	std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << this->_name << " created." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called, bureaucrat " << this->_name << " got deleted." << std::endl;
}

std::string Bureaucrat::getName() const{
	return(this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::incGrade(){
	if (this->_grade - 1 < 1)
	throw GradeTooHighException();
		this->_grade--;
	std::cout << "Incremented grade : grade=" << this->_grade << std::endl;
}

void Bureaucrat::decGrade(){
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Decremented grade : grade=" << this->_grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

void Bureaucrat::signForm(Form & form)
{	
	try{
		form.beSigned(*this);
		std::cout << this->getName() << " signed" << form.getName();
	}
	catch(const std::exception& e){
		std::cerr << this->getName() << " couldn’t sign" << form.getName() << " Because grade(" << this->getGrade() << ") is lower than grade to sign" << std::endl;
	}
	
}