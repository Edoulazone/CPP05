/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:44:30 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 10:43:33 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <string>
# include <stdlib.h>     /* srand, rand */
# include <time.h>       /* time */

class RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;
		virtual void	doSomething() const;
	
	public:
	// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		// exceptions
		class RobotizationFailed : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif