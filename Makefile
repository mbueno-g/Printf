# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 15:57:21 by mbueno-g          #+#    #+#              #
#    Updated: 2021/07/10 18:53:08 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

AR = ar rc

LIBFT = libft

SRCS = ft_printf.c ft_format.c ft_diu_type.c ft_sc_type.c ft_xp_type.c ft_abs.c ft_hex.c ft_type.c \
ft_putnchar.c ft_atoi2.c ft_uitoa.c

SRCSB = ft_printf.c ft_format.c ft_di_type.c ft_sc_type.c ft_xp_type.c ft_abs.c ft_hex.c ft_type.c \
ft_putnchar.c ft_atoi2.c ft_uitoa.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

$(NAME): $(OBJS) $(LIBFT).a
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

$(LIBFT).a:
	make all -C ./$(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(NAME)

bonus: all

test:
	gcc -c main.c $(SRCS)
	gcc $(NAME) main.o && ./a.out | cat -e
	rm -f main.o $(OBJS)

all: $(NAME) $(LIBFT)

clean:
	make clean -C $(LIBFT)/
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(LIBFT)/$(LIBFT).a
	rm -f $(NAME)

git:
	git add ../.
	git commit -m "$(m)"
	git push

re: fclean all

.PHONY: clean fclean all bonus re git
