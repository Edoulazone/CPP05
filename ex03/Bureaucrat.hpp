/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:01:06 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 10:44:20 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Operator overload
		Bureaucrat &operator=(const Bureaucrat &copy);
		
		// Destructors
		~Bureaucrat();
		
		// Getters
		std::string	getName() const;
		int			getGrade() const;
		
		// Other member functions
		void		incrementGrade();
		void		decrementGrade();

		void		signForm(AForm &form);
		void		execForm(const AForm &form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &copy);

#endif
