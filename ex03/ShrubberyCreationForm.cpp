/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:44:34 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 10:53:34 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	_target = copy._target;
	setIsSigned(copy.getIsSigned());
	return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm() {	
}


void ShrubberyCreationForm::doSomething() const {
	std::ofstream outFile((_target + std::string("ShrubbyDick")).c_str());

	if (outFile)
	{
		outFile << "    __     \n";
		outFile << "   /  \\   \n";
		outFile << "   |  |    \n";
		outFile << "   |  |    \n";
		outFile << "   |  |    \n";
		outFile << "   |  |    \n";
		outFile << "   |  |    \n";
		outFile << "   |  |    \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "|        | \n";
		outFile << " \\__/\\__/  \n";
		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileExeption();
		
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw() {
	return ("Error: Open and/or write in the file");
}