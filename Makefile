CC			:= gcc
CFLAGS		:= -c #-Wall -Wextra -Werror
LIBFT_DIR	:= libft
LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))
NAME 		:= libftprintf.a
PRINTF_DIR	:= mandatory
HEADER		:= ft_printf.h
SRCS		:= \
ft_printf.c         ft_printf_lower_x.c ft_printf_s.c		\
ft_printf_c.c       ft_printf_p.c       ft_printf_u.c		\
ft_printf_di.c      ft_printf_percent.c ft_printf_upper_x.c
SRCS		:= $(addprefix $(PRINTF_DIR)/, $(SRCS))
HEADER		:= $(addprefix $(PRINTF_DIR)/, $(HEADER))
OBJS		:= $(SRCS:.c=.o)

ifdef WITH_BONUS
PRINTF_DIR	:= bonus
SRCS		:= \
ft_flags_utils_bonus.c    ft_printf_lower_x_bonus.c ft_printf_u_bonus.c			\
ft_printf_bonus.c         ft_printf_p_bonus.c       ft_printf_upper_x_bonus.c	\
ft_printf_c_bonus.c       ft_printf_percent_bonus.c								\
ft_printf_di_bonus.c      ft_printf_s_bonus.c
SRCS		:= $(addprefix $(PRINTF_DIR)/, $(SRCS))
HEADER		:= ft_printf_bonus.h
HEADER		:= $(addprefix $(PRINTF_DIR)/, $(HEADER))
OBJS		:= $(SRCS:.c=.o)
endif

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS) $(HEADER)
	cp $(LIBFT_A) $(NAME)
	ar rc $(NAME) $(OBJS)

$(LIBFT_A): empty
	make -C $(LIBFT_DIR)

empty:

bonus:
	make WITH_BONUS=1

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft empty bonus
