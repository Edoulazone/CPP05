/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:01:02 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 10:42:10 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(): _name("Fabrice"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {	
	if (grade < 1)
		throw GradeTooHighE();
	else if (grade > 150)
		throw GradeTooLowE();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		_grade = copy._grade;	
	return (*this);
}


Bureaucrat::~Bureaucrat() {
}

// Getters
std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

//Setters
void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighE();
	else
		_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowE();
	else
		_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	}
	catch(const std::exception &e) {
		std::cout << _name << " could not sign " << form. getName() << ". Error: " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << "." << std::endl;
}

void Bureaucrat::execForm(const AForm &form) {
	try
	{
		form.exec(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &copy) {
	os << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (os);
}

// Exceptions
const char *Bureaucrat::GradeTooHighE::what() const throw() {
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowE::what() const throw() {
	return ("Grade too low!");
}
