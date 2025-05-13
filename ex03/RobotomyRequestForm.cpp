/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:44:27 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 11:07:26 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target") {
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	_target = copy._target;
	setIsSigned(copy.getIsSigned());
	return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm() {	
}


void RobotomyRequestForm::doSomething() const {
	int random_number;

	random_number = rand() % 2;

	if (random_number == 1)
		std::cout << getName() << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotizationFailed();
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw() {
	return ("Robotomy failed. So sad :'(");
}