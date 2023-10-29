NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = operation.c push_swap.c tgame.c op_best_num.c solver.c check_error.c sorted.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

debug: $(OBJS)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug