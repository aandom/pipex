# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:41:09 by aandom            #+#    #+#              #
#    Updated: 2023/04/20 12:30:31 by aandom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
SRC = $(wildcard mandatory/*.c) $(wildcard *.c)
SRC_B = $(wildcard bonus/*.c) $(wildcard bonus/get_next_line/*.c)
OBJS =  $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc

%.o: %.c 
		@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
		 @rm -f $(OBJS_B)
		 @$(MAKE) -C ./ft_printf/ 
		 @$(MAKE) -C ./libft/
		 @$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -o $(NAME)
		 @echo "+++++++ $(NAME) for Mandatory Created!$(DEFAULT)"

all: $(NAME)

bonus: $(OBJS_B)
	   @rm -f $(OBJS)
	   @$(MAKE) -C ./ft_printf/
	   @$(MAKE) -C ./libft/
	   @$(CC) $(CFLAGS) $(OBJS_B) ft_printf/libftprintf.a libft/libft.a -o $(NAME)
	   @echo "+++++++ $(NAME) for Bonus is Created!$(DEFAULT)"

clean: 
		@echo "$-------- CLEAN $(DEFAULT)"
		@$(MAKE) clean -C ./ft_printf/
		@$(MAKE) clean -C ./libft/
		@rm -f $(OBJS)
		@echo "$-------- pipex objects files are removed!$(DEFAULT)"
		@rm -f $(OBJS_B)
		@echo "$-------- pipex bonus objects files are removed!$(DEFAULT)"

fclean: clean 
		@rm -f ft_printf/libftprintf.a
		@echo "$-------- ft_printf/libftprintf.a removed!$(DEFAULT)"
		@rm -f libft/libft.a
		@echo "$-------- ibft/libft.a removed!$(DEFAULT)"
		@rm -f $(NAME)
		@echo "$-------- $(NAME) Removed!$(DEFAULT)"

re: fclean	all

.PHONY: all clean fclean re