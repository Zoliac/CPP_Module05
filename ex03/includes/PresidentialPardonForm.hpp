/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:29:31 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/09 13:29:54 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};