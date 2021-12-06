#include "test_ft_printf.h"

void test_d_conversion(void) {
	int test_case_min = -100;
	int test_case_max = 100;
	int ret;

	# ifdef FT_TEST
	for (int i = test_case_min; i < test_case_max; i++) {
		ret = ft_printf("%d", i);
		printf("%d\n", ret);
		fflush(stdout);
	}
	# endif

	# ifdef LIB_TEST
	for (int i = test_case_min; i < test_case_max; i++) {
		ret = printf("%d", i);
		printf("%d\n", ret);
		fflush(stdout);
	}
	# endif
}

int main(void) {
	test_d_conversion();

	# ifdef LEAKS_TEST
	system("leaks a.out");
	# endif
}
