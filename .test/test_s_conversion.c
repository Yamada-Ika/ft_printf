#include "../ft_printf.h"
#include <stdio.h>

void test_s_conversion(void) {
	printf("lib : %d\n", printf("%s\n", 0));
	printf("ft  : %d\n", ft_printf("%s\n", 0));

	printf("lib : %d\n", printf("%s\n", ""));
	printf("ft  : %d\n", ft_printf("%s\n", ""));

	printf("lib : %d\n", printf("%s\n", NULL));
	printf("ft  : %d\n", ft_printf("%s\n", NULL));


	printf("lib : %d\n", printf("%s%s\n", 0));
	printf("ft  : %d\n", ft_printf("%s%s\n", 0));

	printf("lib : %d\n", printf("%s%s\n", ""));
	printf("ft  : %d\n", ft_printf("%s%s\n", ""));

	printf("lib : %d\n", printf("%s%s\n", NULL));
	printf("ft  : %d\n", ft_printf("%s%s\n", NULL));
}

int main(void) {
	test_s_conversion();
	system("leaks a.out");
}
