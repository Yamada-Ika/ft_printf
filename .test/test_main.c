#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include "../bonus/ft_printf.h"

#define TEST(args...)						\
{											\
	int res_ft_printf = ft_printf(args);	\
	int res_printf = printf(args);			\
	fflush(stdout);							\
	printf("ft  : %d\n", res_ft_printf);	\
	printf("lib : %d\n", res_printf);		\
}

// #define TEST(args...)				\
// {									\
// 	int res_printf = printf(args);		\
// 	printf("%d\n", res_printf);		\
// }

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

	// minimum field
	#ifdef FIELD
	// c
	printf("-------- c --------\n");
	TEST("[%000c]\n", 'a');
	TEST("[%00c]\n", 'a');
	TEST("[%0c]\n", 'a');
	TEST("[%1c]\n", 'a');
	TEST("[%2c]\n", 'a');
	TEST("[%3c]\n", 'a');
	printf("-------- c --------\n");
	// s
	printf("-------- s --------\n");
	TEST("[%000s]\n", "");
	TEST("[%00s]\n", "");
	TEST("[%0s]\n", "");
	TEST("[%0s]\n", "");
	TEST("[%s]\n", "hello");
	TEST("[%10s]\n", "hello");
	TEST("[%1s]\n", "hello");
	TEST("[%1s]\n", "hello");
	printf("-------- s --------\n");
	// p
	printf("-------- p --------\n");
	TEST("[%000p]\n", 0);
	TEST("[%00p]\n", 0);
	TEST("[%0p]\n", 0);
	TEST("[%0p]\n", 1);
	TEST("[%p]\n", 1000);
	TEST("[%10p]\n", 1000);
	TEST("[%1p]\n", INT_MAX);
	TEST("[%1p]\n", INT_MIN);
	printf("-------- p --------\n");
	// d
	printf("-------- d --------\n");
	TEST("[%000d]\n", 0);
	TEST("[%00d]\n", 0);
	TEST("[%0d]\n", 0);
	TEST("[%0d]\n", 1);
	TEST("[%d]\n", 1000);
	TEST("[%10d]\n", 1000);
	TEST("[%1d]\n", INT_MAX);
	TEST("[%1d]\n", INT_MIN);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[%000i]\n", 0);
	TEST("[%00i]\n", 0);
	TEST("[%0i]\n", 0);
	TEST("[%0i]\n", 1);
	TEST("[%i]\n", 1000);
	TEST("[%10i]\n", 1000);
	TEST("[%1i]\n", INT_MAX);
	TEST("[%1i]\n", INT_MIN);
	printf("-------- i --------\n");
	// u
	printf("-------- u --------\n");
	TEST("[%000u]\n", 0);
	TEST("[%00u]\n", 0);
	TEST("[%0u]\n", 0);
	TEST("[%10u]\n", 0);
	printf("-------- u --------\n");
	// x
	TEST("[%000x]\n", 0);
	TEST("[%00x]\n", 0);
	TEST("[%0x]\n", 0);
	TEST("[%0x]\n", 1);
	TEST("[%x]\n", 1000);
	TEST("[%10x]\n", 1000);
	TEST("[%1x]\n", INT_MAX);
	TEST("[%1x]\n", INT_MIN);
	// X
	TEST("[%000X]\n", 0);
	TEST("[%00X]\n", 0);
	TEST("[%0X]\n", 0);
	TEST("[%0X]\n", 1);
	TEST("[%X]\n", 1000);
	TEST("[%10X]\n", 1000);
	TEST("[%1X]\n", INT_MAX);
	TEST("[%1X]\n", INT_MIN);
	#endif

	// zero padding
	#ifdef ZERO
	TEST("[%00c]\n", 'a');
	TEST("[%01c]\n", 'a');
	TEST("[%02c]\n", 'a');
	TEST("[%03c]\n", 'a');
	TEST("[%010c]\n", 'a');
	#endif

	// dot
	#ifdef DOT
	printf("........ DOT ........\n");
	// c
	printf("-------- c --------\n");
	TEST("[%.0c]\n", 'a');
	TEST("[%.0c]\n", 'a');
	TEST("[%.0c]\n", 'a');
	TEST("[%1.1c]\n", 'a');
	TEST("[%5.2c]\n", 'a');
	TEST("[%3.1c]\n", 'a');
	printf("-------- c --------\n");
	// s
	printf("-------- s --------\n");
	TEST("[%0.0s]\n", "");
	TEST("[%.0s]\n", "");
	TEST("[%00s]\n", "");
	TEST("[%0s]\n", "");
	TEST("[%10.3s]\n", "hello");
	TEST("[%1.6s]\n", "hello");
	TEST("[%1.1s]\n", "hello");
	TEST("[%10.10s]\n", "hello");
	TEST("[%10.6s]\n", "hello");
	printf("-------- s --------\n");
	// p
	printf("-------- p --------\n");
	TEST("[%000p]\n", 0);
	TEST("[%00p]\n", 0);
	TEST("[%0p]\n", 0);
	TEST("[%0p]\n", 1);
	TEST("[%p]\n", 1000);
	TEST("[%.0p]\n", 0);
	TEST("[%0.0p]\n", 0);
	TEST("[%10.7p]\n", 1000);
	TEST("[%20.10p]\n", INT_MAX);
	TEST("[%20.10p]\n", INT_MIN);
	printf("--------------------\n");
	// d
	printf("-------- d --------\n");
	TEST("[%0.0d]\n", 0);
	TEST("[%.0d]\n", 0);
	TEST("[%00d]\n", 0);
	TEST("[%0d]\n", 0);
	TEST("[%0d]\n", 1);
	TEST("[%10.3d]\n", 1000);
	TEST("[%10.5d]\n", 0);
	TEST("[%.5d]\n", 0);
	TEST("[%10d]\n", 0);
	TEST("[%1.5d]\n", 1000);
	TEST("[%.1d]\n", INT_MAX);
	TEST("[%.1d]\n", INT_MIN);
	printf("-------- d --------\n");
	printf("....................\n");
	#endif

	// sharp
	#ifdef SHARP
	TEST("[%#c]\n", 'b');
	TEST("[%#x]\n", 10);
	TEST("[%#0.0x]\n", 0);
	TEST("[%#0.0x]\n", 100);
	TEST("[%#10.5x]\n", 100);
	TEST("[%#5.10x]\n", 100);
	TEST("[%#x]\n", -1);
	TEST("[%##x]\n", 100);
	TEST("[%#X]\n", 10);
	TEST("[%#0.0X]\n", 0);
	TEST("[%#0.0X]\n", 100);
	TEST("[%#10.5X]\n", 100);
	TEST("[%#5.10X]\n", 100);
	TEST("[%#X]\n", -1);
	TEST("[%##X]\n", 100);
	#endif

	// space
	#ifdef SPACE
	TEST("[%  d]\n", -10);
	TEST("[%  d]\n", 10);
	TEST("[% #x]\n", -1);
	TEST("[% #x]\n", 100);
	#endif

	// plus
	#ifdef PLUS
	TEST("[%+d]\n", 10);
	TEST("[%+d]\n", -10);
	TEST("[%+#x]\n", 10);
	TEST("[%++d]\n", 10);
	#endif

	#ifdef ALL_MIX
	TEST("[%04c]fefe[%10.5s]fewo\n", 'a', "hello");
	TEST("[%04c][%10.5s][%5.5p][%+10.9d][%+u][%#12.1x][% X][%%]\n", 'a', "hello", 100000, INT_MAX, -1, -1, -900);
	#endif
	// sleep(30);
	// system("leaks ./a.out");
}
