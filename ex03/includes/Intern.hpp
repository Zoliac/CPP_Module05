/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leny <leny@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:40:29 by leny              #+#    #+#             */
/*   Updated: 2026/09/19 12:44:10 by leny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern	&operator=(const Intern &src);
		~Intern();
	
		AForm*	makeForm(std::string FormName, std::string target);
};