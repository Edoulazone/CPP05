/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:01:09 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 11:05:21 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;



	std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;



	std::cout << "\033[34m" << std::endl << "Test ex03" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test ex03 ShrubberyCreationForm" << "\033[0m" << std::endl;
	Bureaucrat Mr_Shrubby("Shrub Daddy", 130);
	ShrubberyCreationForm Shrubby_form("Hello");
	std::cout << std::endl;
	std::cout << Shrubby_form;
	Mr_Shrubby.signForm(Shrubby_form);
	std::cout << Shrubby_form;
	Mr_Shrubby.execForm(Shrubby_form);

	std::cout << "\033[33m" << std::endl << "Test ex03 RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr.Robot (not the movie)", 45);

	Mr_Robo.execForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.execForm(Robo_form);
	Mr_Robo.execForm(Robo_form);
	Mr_Robo.execForm(Robo_form);

	std::cout << "\033[33m" << std::endl << "Test ex03 PresidentialPardonForm" << "\033[0m" << std::endl;
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Mr_President("My dude president daddy", 5);

	Mr_Robo.execForm(President_form);
	Mr_Robo.signForm(President_form);

	Mr_President.execForm(President_form);
	Mr_President.signForm(President_form);
	Mr_President.execForm(President_form);
	

	std::cout << "\033[33m" << std::endl << "Test ex03 Intern" << "\033[0m" << std::endl;

	Intern Jr_Intern;
	AForm *robo_intern;

	robo_intern = Jr_Intern.makeForm("DoYouKnowMe", "Hmmmm");
	robo_intern = Jr_Intern.makeForm("RobotomyRequestForm", "World");

	std::cout << robo_intern->getName() << std::endl;
	std::cout << std::endl;
	delete robo_intern;
	return (0);
}