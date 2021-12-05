#include "../ft_printf.h"
#include <stdio.h>

void test_i_conversion(void) {
	printf("lib : %d\n", printf("%i\n", 0));
	printf("ft  : %d\n", ft_printf("%i\n", 0));

	printf("lib : %d\n", printf("%i\n", INT_MIN));
	printf("ft  : %d\n", ft_printf("%i\n", INT_MIN));


	printf("lib : %d\n", printf("%i%i\n", 0, 0));
	printf("ft  : %d\n", ft_printf("%i%i\n", 0, 0));

	printf("lib : %d\n", printf("%i%i\n", INT_MIN, INT_MIN));
	printf("ft  : %d\n", ft_printf("%i%i\n", INT_MIN, INT_MIN));
}

int main(void) {
	test_i_conversion();
	system("leaks a.out");
}
