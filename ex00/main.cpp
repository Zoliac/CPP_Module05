/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:22:31 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/08 10:36:42 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat test1("Henry", 12);
	Bureaucrat test2("Connor", 137);
	Bureaucrat test3("John", 75);

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	try {
		for(int i = 0; i < 13; i++){
			test1.incGrade();
		} 
	}
	
	catch (Bureaucrat::GradeTooHighException& except){
		std::cout << except.what() << std::endl;
	}

	try {
		for(int i = 0; i < 14; i++){
			test2.decGrade();
		}
	}

	catch (Bureaucrat::GradeTooLowException& except){
		std::cout << except.what() << std::endl;
	}

	catch (std::exception& except){
		std::cout << except.what() << std::endl;
	}

	try {
		for (int i = 0; i < 20; i++){
			test3.incGrade();
		}
	}

	catch (Bureaucrat::GradeTooHighException& except){
		std::cout << except.what() << std::endl;
	}

	catch (Bureaucrat::GradeTooLowException& except){
		std::cout << except.what() << std::endl;
	}

	catch (std::exception& except){
		std::cout << except.what() << std::endl;
	}

	try {
		Bureaucrat("Tony", -1);
	}
	
	catch (Bureaucrat::GradeTooHighException& except){
		std::cout << except.what() << std::endl;
	}

	try {
		Bureaucrat("Bob", 151);
	}
	
	catch (Bureaucrat::GradeTooLowException& except){
		std::cout << except.what() << std::endl;
	}

	return 0;
}