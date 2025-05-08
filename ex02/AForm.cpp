/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:52:46 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/08 17:55:37 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors and destructors
AForm::AForm(): _name("Default form"), _signed(false), _signGrade(150), _execGrade(150) {
}

AForm::~AForm() {
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
}

// Function operator overload
AForm &AForm::operator=(const AForm &copy) {
	_signed = copy._signed;
	return (*this);
}

// Getters, setters and member functions
void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowE();
}

void	Aform::setIsSigned(bool _signed) {
}

void	Aform::exec(const Bureaucrat &bureaucrat) {
}

std::string	AForm::getName() const {
	return (_name);
}

bool AForm::getIsSigned() const {
	return (_signed);
}

int	AForm::getSignGrade() const {
	return (_signGrade);
}

int AForm::getExecGrade() const {
	return (_execGrade);
}

// << operator overload
std::ostream &operator<<(std::ostream &os, const AForm &Aform) {
	os << "Name: " << Aform.getName() << " isSigned: " << Aform.isSigned() << " Sign grade: " << Aform.getSignGrade() << " Exec grade: " << Aform.getExecGrade() << std::endl;
	return (os);
}

// Exceptions
const char *AForm::GradeTooHighE::what() const throw() {
	return ("Grade too high!");
}

const char *AForm::GradeTooLowE::what() const throw() {
	return ("Grade too low!");
}
