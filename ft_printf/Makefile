# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 17:49:41 by knoh              #+#    #+#              #
#    Updated: 2022/02/14 17:49:42 by knoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = ./ft_printf.c ./print_hex.c ./print_int.c ./print_string.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -crs $(NAME) $(OBJS)

all : $(NAME)

bonus:
	make all

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)



test :
	gcc -Wall -Wextra -Werror $(SRCS) ./libft/*.c main.c -o test.out



re : fclean all

.PHONY:	all clean fclean re bonus