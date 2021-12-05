#include "../ft_printf.h"
#include <stdio.h>

void test_d_conversion(void) {
	printf("lib : %d\n", printf("%d\n", 0));
	printf("ft  : %d\n", ft_printf("%d\n", 0));

	printf("lib : %d\n", printf("%d\n", INT_MIN));
	printf("ft  : %d\n", ft_printf("%d\n", INT_MIN));


	printf("lib : %d\n", printf("%d%d\n", 0, 0));
	printf("ft  : %d\n", ft_printf("%d%d\n", 0, 0));

	printf("lib : %d\n", printf("%d%d\n", INT_MIN, INT_MIN));
	printf("ft  : %d\n", ft_printf("%d%d\n", INT_MIN, INT_MIN));
}

int main(void) {
	test_d_conversion();
	system("leaks a.out");
}
