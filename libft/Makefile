# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 15:57:21 by mbueno-g          #+#    #+#              #
#    Updated: 2021/07/11 16:04:00 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

FLAGS = -Wall -Werror -Wextra 

AR = ar rc

SRCS =	ft_memset.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_itoa.c \

OBJS = $(SRCS:.c=.o)

$(NAME): 
	gcc $(FLAGS) -c $(SRCS) 
	$(AR) $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re
