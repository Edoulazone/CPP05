# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 17:01:12 by eschmitz          #+#    #+#              #
#    Updated: 2025/05/13 10:59:29 by eschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)

NAME = killmenow

all: $(NAME)

$(NAME):$(OBJ)
	$(C++) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re