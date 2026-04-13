/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:40:12 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/09 13:32:51 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Form.hpp"

Form::Form() : _name("Default"), _is_signed(0), _req_grade_sign(75), _req_grade_exec(30){
	std::cout << this->_name << " has been created\n";
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(0), _req_grade_sign(sign_grade), _req_grade_exec(exec_grade){
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw Form::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw Form::GradeTooHighException();
	std::cout << this->_name << " has been created\n";
}

Form& Form::operator=(const Form other){
	this->_is_signed = other.getStatus();
	return(*this);
}

Form::Form(const Form &other) : _name(other.getName() + "/copy"), _is_signed(other.getStatus()), _req_grade_sign(other.getSignGrade()), _req_grade_exec(other.getExecGrade()) {
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw Form::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw Form::GradeTooHighException();
	std::cout << this;
}

Form::~Form(){
	std::cout << this->_name << " Has been closed !\n";
}

std::string	Form::getName() const {
	return(this->_name);
}

bool	Form::getStatus() const {
	return(this->_is_signed);
}

int	Form::getSignGrade() const {
	return(this->_req_grade_sign);
}

int	Form::getExecGrade() const {
	return(this->_req_grade_exec);
}

void Form::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() <= this->getSignGrade())
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return("Grade too high !\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return("Grade too low !\n");
}

std::ostream &operator<<(std::ostream &out, Form &tmp)
{
	out
		<< "Form information :\n"
		<< "\t- Name : " << tmp.getName() << std::endl
		<< "\t- Status : " << ((tmp.getStatus() == 1) ? "true" : "false") << std::endl
		<< "\t- Required Grade to sign it : " << tmp.getSignGrade() << std::endl
		<< "\t- Required Grade to execute it : " << tmp.getExecGrade() << std::endl
		<< std::endl;
	return(out);
}