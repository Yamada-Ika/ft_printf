#include "../ft_printf.h"
#include <stdio.h>

void test_upper_x_conversion(void) {
	printf("lib : %d\n", printf("%X\n", 0));
	printf("ft  : %d\n", ft_printf("%X\n", 0));

	printf("lib : %d\n", printf("%X\n", INT_MIN));
	printf("ft  : %d\n", ft_printf("%X\n", INT_MIN));

	printf("lib : %d\n", printf("%X\n", INT_MAX));
	printf("ft  : %d\n", ft_printf("%X\n", INT_MAX));

	printf("lib : %d\n", printf("%X%X\n", 0, 0));
	printf("ft  : %d\n", ft_printf("%X%X\n", 0, 0));

	printf("lib : %d\n", printf("%X%X\n", INT_MIN, INT_MIN));
	printf("ft  : %d\n", ft_printf("%X%X\n", INT_MIN, INT_MIN));

	printf("lib : %d\n", printf("%X%X\n", INT_MAX, INT_MAX));
	printf("ft  : %d\n", ft_printf("%X%X\n", INT_MAX, INT_MAX));
}

int main(void) {
	test_upper_x_conversion();
	system("leaks a.out");
}
