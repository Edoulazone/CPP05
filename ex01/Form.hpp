/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:06:36 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/08 17:31:04 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		// Constructors
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &copy);
		
		// Operator overload
		Form &operator=(const Form &copy);
		
		// Destructors
		~Form();
		
		// Getters
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		isSigned() const;
		
		// Other member functions
		void		beSigned(const Bureaucrat &bureaucrat);

		// Exceptions
		class GradeTooHighE: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowE: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &copy);

#endif
