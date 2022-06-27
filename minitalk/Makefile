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

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all : $(LIBFT_NAME) $(NAME)

$(NAME) : $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)/

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${\e[0m}"

$(NAME_CLIENT): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${\e[0m}"

bonus:
	make all

clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean :
	make clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)
	
re :
	make fclean
	make all

.PHONY:	all clean fclean re bonus
