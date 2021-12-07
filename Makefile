CC			:= gcc
CFLAGS		:= -c #-Wall -Wextra -Werror

PRINTF_DIR	:= bonus
LIBFT_DIR	:= libft

LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

NAME 		:= libftprintf.a
HEADER		:= ft_printf.h
SRCS		:= \
ft_printf.c         ft_printf_lower_x.c ft_printf_s.c		\
ft_printf_c.c       ft_printf_p.c       ft_printf_u.c		\
ft_printf_di.c      ft_printf_percent.c ft_printf_upper_x.c
SRCS		:= $(addprefix $(PRINTF_DIR)/, $(SRCS))
HEADER		:= $(addprefix $(PRINTF_DIR)/, $(HEADER))
OBJS		:= $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS) $(HEADER)
	cp $(LIBFT_A) $(NAME)
	ar rc $(NAME) $(OBJS)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft empty
