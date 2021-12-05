#include "../ft_printf.h"
#include <stdio.h>

void test_c_conversion(void) {
	for (int i = - 100; i < 100; i++) {
		printf("lib : %d\n", printf("%c\n", i));
		printf("ft  : %d\n", ft_printf("%c\n", i));
	}
	for (int i = - 100; i < 100; i++) {
		printf("lib : %d\n", printf("%c%c\n", i, i));
		printf("ft  : %d\n", ft_printf("%c%c\n", i, i));
	}
}

int main(void) {
	test_c_conversion();
	system("leaks a.out");
}
