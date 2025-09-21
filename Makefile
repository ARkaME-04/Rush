NAME = rush-02

SRCS = rush-02.c \
       dictionnary.c \
       read.c\
       convert.c \
       utils.c
OBJS = $(SRCS:.c=o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
