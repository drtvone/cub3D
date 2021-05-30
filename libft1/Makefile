# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rturnip <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 18:27:21 by rturnip           #+#    #+#              #
#    Updated: 2020/11/27 18:51:28 by rturnip          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_putnbr_fd.c \
			  ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_strncmp.c\
			  ft_split.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c \
			  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c  ft_strnstr.c \
			  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstsize.c \
			  ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_strcmp.c

INCLUDES	= ./

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

FLAGS		= -Wall -Werror -Wextra

.c.o:
		@gcc ${FLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		@ar rcs ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean : clean
		@${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
