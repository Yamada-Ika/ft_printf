#include "test_ft_printf.h"

void test_non_conversion(void) {
	printf("%d\n", ft_printf(""));
	printf("%d\n", printf(""));

	printf("%d\n", ft_printf("hello world\n"));
	printf("%d\n", printf("hello world\n"));
}

int main(void) {
	test_non_conversion();
	return (0);
}
