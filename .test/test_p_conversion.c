#include "../ft_printf.h"
#include <stdio.h>

void test_p_conversion(void) {
	printf("lib : %d\n", printf("%p\n", NULL));
	printf("ft  : %d\n", ft_printf("%p\n", NULL));

	printf("lib : %d\n", printf("%p\n", 0));
	printf("ft  : %d\n", ft_printf("%p\n", 0));

	printf("lib : %d\n", printf(" %p %p \n", 0, 0));
	printf("ft  : %d\n", ft_printf(" %p %p \n", 0, 0));

	printf("lib : %d\n", printf(" %p %p \n", NULL, NULL));
	printf("ft  : %d\n", ft_printf(" %p %p \n", NULL, NULL));
}

int main(void) {
	test_p_conversion();
	system("leaks a.out");
}
