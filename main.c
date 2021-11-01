#include "ft_printf.h"
#include "libft/libft.h"

int main(void) {
	printf("ret : %d\n", printf("%0*.*s\n",10, 3, "abcdefg"));
	putchar('\n');
	printf("ret : %d\n", ft_printf("%0*.*s\n",10, 3, "abcdefg"));
	putchar('\n');
}
