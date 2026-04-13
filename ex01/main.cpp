/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:22:31 by lpatin            #+#    #+#             */
/*   Updated: 2026/04/09 13:32:59 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("Boris", 150);
		Form		contract("test 1", 150, 150);
	
		std::cout << std::endl;
		std::cout << contract;
		test.signForm(contract);
		std::cout << std::endl;
		std::cout << contract;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
}