# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 11:00:00 by aandom            #+#    #+#              #
#    Updated: 2023/04/20 12:27:09 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS 		= $(wildcard *.c)
OBJECTS		= $(SRCS:.c=.o)
RM			= rm -f
LIBCREATE	= ar -rcs		
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror

%.o: %.c 
		@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJECTS)
	@$(LIBCREATE) $(NAME) $(OBJECTS)
	@echo "+++++++ libft is complied!$(DEFAULT)"

all : $(NAME)

clean :
	@$(RM) $(OBJECTS)
	@echo "$-------- libft objects files removed $(DEFAULT)" 

fclean : clean
	@$(RM) $(NAME)
	@echo "-------- $(NAME) removed $(DEFAULT)" 

re : fclean all

.PHONY: all clean fclean re