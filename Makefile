# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alletond <alletond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:58:10 by alletond          #+#    #+#              #
#    Updated: 2023/11/03 15:25:27 by alletond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker

COMMON_SRCS = operation.c tgame.c op_best_num.c solver.c check_error.c sorted.c utils.c operation2.c utils2.c solver2.c operation3.c utils3.c
PS_SRCS = push_swap.c $(COMMON_SRCS)
CHECKER_SRCS = checker.c get_next_line.c get_next_line_utils.c $(COMMON_SRCS)

OBJS = $(PS_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

LIBFT = libft/libft.a
HEADERS = -I./libft -I.

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME) $(CHECKER_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	make fclean -C libft

re: fclean all
