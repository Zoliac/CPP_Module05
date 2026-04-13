/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:22:33 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/13 16:41:32 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# include <iostream>
# include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& name);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void signForm(AForm &toSign);
		void executeForm(const AForm& form);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
	};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);