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

NAME = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDES = ./libft.h

SRCS = \
	./ft_isalpha.c	\
	./ft_isdigit.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_strlen.c	\
	./ft_memset.c	\
	./ft_bzero.c	\
	./ft_memcpy.c	\
	./ft_memmove.c	\
	./ft_strlcpy.c	\
	./ft_strlcat.c	\
	./ft_toupper.c	\
	./ft_tolower.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_strnstr.c	\
	./ft_atoi.c		\
	./ft_calloc.c	\
	./ft_strdup.c	\
	./ft_substr.c	\
	./ft_strjoin.c	\
	./ft_strtrim.c	\
	./ft_split.c	\
	./ft_itoa.c		\
	./ft_strmapi.c	\
	./ft_striteri.c	\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c

SRC_BONUS = \
	./ft_lstnew.c	\
	./ft_lstadd_front.c	\
	./ft_lstsize.c	\
	./ft_lstlast.c	\
	./ft_lstadd_back.c	\
	./ft_lstdelone.c	\
	./ft_lstclear.c	\
	./ft_lstiter.c	\
	./ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

ifdef FLAG_BONUS
OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
OBJ_FILES = $(OBJS)
endif

$(NAME): $(OBJ_FILES)
	ar -crs $@ $^

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

bonus:
	FLAG_BONUS=1 make all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re bonus