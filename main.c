#include "ft_printf.h"
#include "libft/libft.h"

int main(void) {
	printf("ret : %d\n", printf(" %p %p ", 0, 0));
	putchar('\n');
	printf("ret : %d\n", ft_printf(" %p %p ", 0, 0));
	putchar('\n');
}
