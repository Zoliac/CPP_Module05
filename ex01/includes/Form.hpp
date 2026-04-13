/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:40:04 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/08 17:19:44 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool _is_signed;
		const int _req_grade_sign;
		const int _req_grade_exec;
	public:
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &other);
		Form& operator=(const Form other);
		~Form();
		void beSigned(Bureaucrat &employee);
		bool getStatus() const;
		std::string getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form &tmp);