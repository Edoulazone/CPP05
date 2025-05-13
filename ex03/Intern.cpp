/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:56:14 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 11:09:47 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern() {
}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return (*this);
}

Intern::~Intern() {
}

// Member functions
AForm *Intern::makeForm(const std::string formName, const std::string formTarget) {
	int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && formName != available_forms[i])
		i++;
	
	switch (i)
	{
	case 0:
		std::cout << "The intern (Again, not the movie. You known,the one with Robert De Niro of course) created " << formName << std::endl;
		return (new ShrubberyCreationForm(formTarget));
	case 1:
		std::cout << "The intern (Again, not the movie. You known,the one with Robert De Niro of course) created " << formName << std::endl;
		return (new RobotomyRequestForm(formName));
	case 2:
		std::cout << "The intern (Again, not the movie. You known,the one with Robert De Niro of course) created " << formName << std::endl;
		return (new PresidentialPardonForm (formTarget));
	default:
		std::cout << "Form is not existing" << std::endl;
		return NULL;
	}
}