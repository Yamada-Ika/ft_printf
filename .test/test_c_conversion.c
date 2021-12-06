#include "test_ft_printf.h"

void test_c_conversion(void) {
	int test_case_min = 40;
	int test_case_max = 100;
	int ret;

	# ifdef FT_TEST
	for (int i = test_case_min; i < test_case_max; i++) {
		ret = ft_printf("%c", i);
		printf("%d\n", ret);
		fflush(stdout);
	}
	# endif

	# ifdef LIB_TEST
	for (int i = test_case_min; i < test_case_max; i++) {
		ret = printf("%c", i);
		printf("%d\n", ret);
	}
	# endif
}

int main(void) {
	test_c_conversion();
	// system("leaks a.out");
}
