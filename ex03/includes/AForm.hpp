/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:26:55 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/10 14:08:39 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _is_signed;
		const int GradeToSign;
		const int GradeToExecute;

	public:
		AForm();
		AForm(std::string name, int GradeTosign, int GradeToExecute);
		AForm(const AForm &copy);
		~AForm();
		AForm &operator=(const AForm &copy);
		const std::string &getName()const;
		const bool &getSigned()const;
		const int &getGradeToSign()const;
		const int &getGradeToExecute()const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSigned : public std::exception{
			public :
				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &os, AForm &AForm);