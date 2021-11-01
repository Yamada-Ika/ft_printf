#include "../libft.h"

void run_ft_itoa_base_test(void) {
	int n;
	char *ret;

	n = 100;
	ret = ft_itoa_base(n, "0123456789");
	printf("%s\n", ret);
	printf("%d\n", n);
	free(ret);

	n = -100;
	ret = ft_itoa_base(n, "0123456789");
	printf("%s\n", ret);
	printf("%d\n", n);
	free(ret);

	n = 11;
	ret = ft_itoa_base(n, "0123456789abcdef");
	printf("%s\n", ret);
	printf("%x\n", n);
	free(ret);

	n = 100;
	ret = ft_itoa_base(n, "0123456789abcdef");
	printf("%s\n", ret);
	printf("%x\n", n);
	free(ret);

	n = -100;
	ret = ft_itoa_base(n, "0123456789abcdef");
	printf("%s\n", ret);
	printf("%x\n", n);
	free(ret);
}

int main(void) {
	run_ft_itoa_base_test();
	return (0);
}
