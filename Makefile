CC			:= gcc
CFLAGS		:= -c -Wall -Wextra -Werror

# libft
LIBFT_DIR	:= libft
LIBFT_A		:= libft.a
LIBFT_A		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

# ft_printf mandatory
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

# ft_printf bonus
ifdef WITH_BONUS
PRINTF_DIR	:= bonus
SRCS		:= \
ft_calc_fills_bonus.c         ft_flags_bonus.c				\
ft_conv_cspdiu_bonus.c        ft_print_c_with_flags_bonus.c	\
ft_conv_upxlwxper_bonus.c     ft_print_fills_bonus.c		\
ft_conv_utils_bonus.c         ft_print_with_flags_bonus.c	\
ft_fills_utils_bonus.c        ft_printf_bonus.c
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
	rm -rf mandatory/*.o
	rm -rf bonus/*.o
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft empty bonus
