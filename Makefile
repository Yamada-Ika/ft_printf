CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c

MAKE		:= make --warn-undefined-variables

PRINTF_DIR	:= .
LIBFT_DIR	:= libft

LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

NAME 		:= libftprintf.a
HEADER		:= ft_printf.h
SRCS		:= \
	ft_printf.c         ft_printf_di.c      ft_printf_p.c       ft_printf_s.c       ft_printf_upper_x.c	\
	ft_printf_c.c       ft_printf_lower_x.c ft_printf_percent.c ft_printf_u.c
SRCS		:= $(addprefix $(PRINTF_DIR)/, $(SRCS))
OBJS		:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_A) $(NAME)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

libft:
	touch $(OBJS)
	make $(NAME)

.PHONY: all clean fclean re libft
