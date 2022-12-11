
NAME = gnl
CFLAGS = -g3
CC = gcc
SRCS =	get_next_line.c get_next_line_utils.c test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS)  -c $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) $(OBJS)  -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all