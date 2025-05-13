/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:56:11 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 10:58:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Intern
{
	private:

	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		// Member functions
		AForm	*makeForm(const std::string formName, const std::string formTarget) ;
};

#endif