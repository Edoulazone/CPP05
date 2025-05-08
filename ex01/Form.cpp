/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:34 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/08 17:29:34 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors and destructors
Form::Form(): _name("Default form"), _signed(false), _signGrade(150), _execGrade(150) {
}

Form::~Form() {
}

Form::Form(const std::string name, const int signGrade, const int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
}

// Function operator overload
Form &Form::operator=(const Form &copy) {
	_signed = copy._signed;
	return (*this);
}

// Getters, setters and member functions
void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowE();
}

std::string	Form::getName() const {
	return (_name);
}

bool Form::isSigned() const {
	return (_signed);
}

int	Form::getSignGrade() const {
	return (_signGrade);
}

int Form::getExecGrade() const {
	return (_execGrade);
}

// << operator overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Name: " << form.getName() << " isSigned: " << form.isSigned() << " Sign grade: " << form.getSignGrade() << " Exec grade: " << form.getExecGrade() << std::endl;
	return (os);
}

// Exceptions
const char *Form::GradeTooHighE::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowE::what() const throw() {
	return ("Grade too low!");
}
