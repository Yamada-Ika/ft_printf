CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c
NAME 		:= libftprintf.a
HEADERFILE 	:= ft_printf.h
SRCS		:= ft_printf.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERFILE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
