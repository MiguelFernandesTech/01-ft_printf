# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:30:19 by migmarti          #+#    #+#              #
#    Updated: 2022/12/06 10:44:11 by migmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
RM = rm -f
CFLAG = -Wall -Wextra -Werror
AR = ar rcs

FILES = $(shell find . -type f -name '*.c')

OBJ = $(FILES:%.c=%.o)
FILES_O = $(shell find . -type f -name '*.o')

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(FILES_O)
clean:
		@$(RM) $(FILES_O)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
