#include "../ft_printf.h"
#include <stdio.h>

void test_lower_x_conversion(void) {
	printf("lib : %d\n", printf("%x\n", 0));
	printf("ft  : %d\n", ft_printf("%x\n", 0));

	printf("lib : %d\n", printf("%x\n", INT_MIN));
	printf("ft  : %d\n", ft_printf("%x\n", INT_MIN));

	printf("lib : %d\n", printf("%x\n", INT_MAX));
	printf("ft  : %d\n", ft_printf("%x\n", INT_MAX));

	printf("lib : %d\n", printf("%x%x\n", 0, 0));
	printf("ft  : %d\n", ft_printf("%x%x\n", 0, 0));

	printf("lib : %d\n", printf("%x%x\n", INT_MIN, INT_MIN));
	printf("ft  : %d\n", ft_printf("%x%x\n", INT_MIN, INT_MIN));

	printf("lib : %d\n", printf("%x%x\n", INT_MAX, INT_MAX));
	printf("ft  : %d\n", ft_printf("%x%x\n", INT_MAX, INT_MAX));
}

int main(void) {
	test_lower_x_conversion();
	system("leaks a.out");
}
