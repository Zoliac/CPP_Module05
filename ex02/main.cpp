/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:22:31 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/13 17:13:32 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main () {
	Bureaucrat Didier("Didier", 137);
	Bureaucrat Denis("Denis", 30);
	Bureaucrat Obama("Obama", 2);
	ShrubberyCreationForm form("Lény");
	RobotomyRequestForm form2("Robot");
	PresidentialPardonForm form3("Tailor");
	try {
		Didier.signForm(form);
		Didier.executeForm(form);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Didier.signForm(form2);
		Didier.executeForm(form2);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Denis.signForm(form2);
		Denis.executeForm(form2);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Obama.signForm(form3);
		Obama.executeForm(form3);
	}

	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}