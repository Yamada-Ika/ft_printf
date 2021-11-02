CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -c
PRINTF_DIR		:= .
LIBFT_DIR		:= libft
NAME 			:= libftprintf.a
PRINTF_HEADER	:= ft_printf.h
LIBFT_HEADER	:= libft.h
PRINTF_SRCS		:= ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c
LIBFT_SRCS		:= \
ft_atoi.c         ft_lltoa_base.c   ft_memcpy.c       ft_split.c        ft_strnstr.c\
ft_bzero.c        ft_lstadd_back.c  ft_memmove.c      ft_strchr.c       ft_strrchr.c\
ft_calloc.c       ft_lstadd_front.c ft_memset.c       ft_strcmp.c       ft_strrev.c\
ft_free_s.c       ft_lstclear.c     ft_putchar.c      ft_strdup.c       ft_strstr.c\
ft_isalnum.c      ft_lstdelone.c    ft_putchar_fd.c   ft_striteri.c     ft_strtrim.c\
ft_isalpha.c      ft_lstiter.c      ft_putendl_fd.c   ft_strjoin.c      ft_substr.c\
ft_isascii.c      ft_lstlast.c      ft_putnbr.c       ft_strlcat.c      ft_tolower.c\
ft_isdigit.c      ft_lstmap.c       ft_putnbr_base.c  ft_strlcpy.c      ft_toupper.c\
ft_isprint.c      ft_lstnew.c       ft_putnbr_fd.c    ft_strlen.c       ft_uitoa.c\
ft_itoa.c         ft_lstsize.c      ft_putstr.c       ft_strlen_s.c\
ft_itoa_base.c    ft_memchr.c       ft_putstr_fd.c    ft_strmapi.c\
ft_lltoa.c        ft_memcmp.c       ft_putuinbr.c     ft_strncmp.c
PRINTF_SRCS		:= $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS))
LIBFT_SRCS		:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
PRINTF_SRCS		+= $(LIBFT_SRCS)
PRINTF_OBJS		:= $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF_OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(PRINTF_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
