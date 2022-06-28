# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 16:22:28 by knoh              #+#    #+#              #
#    Updated: 2022/05/05 16:22:30 by knoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS_SERVER = ./server.c
SRCS_CLIENT = ./client.c

SRCS_SERVER_BONUS = ./server_bonus.c
SRCS_CLIENT_BONUS = ./client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

ifdef BONUS
OBJS_SERVER = $(OBJS_SERVER_BONUS)
OBJS_CLIENT = $(OBJS_CLIENT_BONUS)
endif

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $@

bonus:
	BONUS=1 make all

clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -rf $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean :
	make clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)
	rm -rf $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	
re :
	make fclean
	make all

.PHONY:	all clean fclean re bonus
