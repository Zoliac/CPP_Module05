/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:30:23 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/13 14:42:09 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};