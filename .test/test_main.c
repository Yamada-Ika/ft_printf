#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include "../ft_printf.h"

#define TEST(args...)						\
{											\
	int res_ft_printf = ft_printf(args);	\
	int res_printf = printf(args);			\
	fflush(stdout);							\
	assert(res_printf == res_ft_printf);	\
}

int main(void) {
	// non-conversion
	#ifdef N
	TEST("Hello, world\n");
	TEST("");
	#endif

	// c
	#ifdef C
	TEST("%c\n", 'a');
	TEST("%c%c\n", 'a', 'b');
	TEST("%c %c\n", 'a', 'b');
	#endif

	// s
	#ifdef S
	TEST("%s\n", "hello");
	TEST("%s%s\n", "hello", "world");
	TEST("%s %s\n", "hello", "world");
	#endif

	// p
	#ifdef P
	int ptr_1;
	char ptr_2;
	long ptr_3;
	double ptr_4;
	TEST("%p\n", &ptr_1);
	TEST("%p%p\n", &ptr_2, &ptr_2);
	TEST("%p %p\n", &ptr_3, &ptr_4);
	#endif

	// d
	#ifdef D
	TEST("%d\n", 0);
	TEST("%d%d\n", -1, 100);
	TEST("%d %d\n", -100, 100);
	TEST("%d %d\n", INT_MIN, INT_MAX);
	TEST("%d %d\n", LONG_MIN, LONG_MAX);
	TEST("%d %d\n", LLONG_MIN, LLONG_MAX);
	TEST("%d\n", ULONG_MAX);
	#endif

	// i
	#ifdef I
	TEST("%i\n", 0);
	TEST("%i%i\n", -1, 100);
	TEST("%i %i\n", -100, 100);
	TEST("%i %i\n", INT_MIN, INT_MAX);
	TEST("%i %i\n", LONG_MIN, LONG_MAX);
	TEST("%i %i\n", LLONG_MIN, LLONG_MAX);
	TEST("%i\n", ULONG_MAX);
	#endif

	// u
	#ifdef U
	TEST("%u\n", 0);
	TEST("%u%u\n", 0, 100);
	TEST("%u %u\n", UINT_MAX, 123);
	TEST("%u %u %u\n", -1, INT_MIN, LLONG_MAX);
	#endif

	// x
	#ifdef LX
	TEST("%x\n", 0);
	TEST("%x%x\n", 10, 11);
	TEST("%x %x\n", -1, INT_MAX);
	TEST("%x %x %x\n", INT_MIN, LLONG_MIN, 0);
	#endif

	// X
	#ifdef UX
	TEST("%X\n", 0);
	TEST("%X%X\n", 100, -1);
	TEST("%X %X\n", INT_MIN, INT_MAX);
	TEST("%X %X %X\n", LLONG_MIN, UINT_MAX, LLONG_MAX);
	#endif

	// %
	#ifdef PERCENT
	TEST("%%\n");
	TEST("%%%%\n");
	TEST("%% %%\n");
	TEST("%% %% %%\n");
	#endif

	// mix
	#ifdef MIX
	int num;
	TEST("%c %s %p %d %i %u %x %X %%\n", 'J', "string", &num, LONG_MIN, LONG_MAX, -1, -1, INT_MAX);
	#endif

	// Over INT_MAX length
	#ifdef BIG_STR
	long long size = 1LL * INT_MAX + 10LL;
	char *str = (char *)malloc(size * sizeof(char));
	memset(str, 'a', size - 1LL);
	str[size - 1] = '\0';
	printf("%d\n", printf("%s", str));
	printf("%d\n", ft_printf("%s", str));
	#endif

	// Over INT_MAX length
	#ifdef BIG_MIX
	long long size = 1LL * INT_MAX + 0LL;
	char *str = (char *)malloc(size * sizeof(char));
	memset(str, '_', size - 1LL);
	str[size - 1LL] = '\0';
	printf("%d\n", printf("ab\n%s", str));
	printf("%d\n", ft_printf("ab\n%s", str));
	#endif

	// sleep(30);
	// system("leaks ./a.out");
}
