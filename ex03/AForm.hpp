/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:47:18 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 11:01:30 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		virtual void		doSomething() const = 0;

	public:
		// Constructors
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &copy);
		
		// Operator overload
		AForm &operator=(const AForm &copy);
		
		// Destructors
		virtual ~AForm();
		
		// Getters
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;
		
		// Other member functions
		void		beSigned(const Bureaucrat &bureaucrat);
		void		setIsSigned(bool _signed);
		void		exec(const Bureaucrat &bureaucrat) const;

		// Exceptions
		class GradeTooHighE: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowE: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class IsNotSignedE: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &copy);

#endif
