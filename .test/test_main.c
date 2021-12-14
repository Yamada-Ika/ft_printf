#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include "../bonus/ft_printf_bonus.h"
#include "test.h"

#define TEST(args...)							\
{												\
	int res_ft_printf = ft_printf(args);		\
	int res_printf = printf(args);				\
	fflush(stdout);								\
	ft_check_value(res_ft_printf, res_printf);	\
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
	fflush(stdout);
	printf("%d\n", printf("%s", str));
	// printf("%d\n", ft_printf("%s", str));
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
	TEST("[%010p]\n", (void *)1);
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
	TEST(" [%03d] \n", -11);
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
	printf("-------- x --------\n");
	TEST("[%000x]\n", 0);
	TEST("[%00x]\n", 0);
	TEST("[%0x]\n", 0);
	TEST("[%0x]\n", 1);
	TEST("[%x]\n", 1000);
	TEST("[%10x]\n", 1000);
	TEST("[%1x]\n", INT_MAX);
	TEST("[%1x]\n", INT_MIN);
	printf("-------- x --------\n");
	// X
	printf("-------- X --------\n");
	TEST("[%000X]\n", 0);
	TEST("[%00X]\n", 0);
	TEST("[%0X]\n", 0);
	TEST("[%0X]\n", 1);
	TEST("[%X]\n", 1000);
	TEST("[%10X]\n", 1000);
	TEST("[%1X]\n", INT_MAX);
	TEST("[%1X]\n", INT_MIN);
	printf("-------- X --------\n");
	// %
	printf("-------- %% --------\n");
	TEST("[%%]\n");
	TEST("[%1%]\n");
	TEST("[%2%]\n");
	TEST("[%3%]\n");
	TEST("[%4%]\n");
	TEST("[%5%]\n");
	TEST("[%6%]\n");
	printf("-------- %% --------\n");
	#endif

	// zero padding
	#ifdef ZERO
	// s
	printf("-------- s --------\n");
	TEST("[%010s]\n", "hello");
	TEST("[%10.6s]\n", "hello");
	TEST("[%.1s]\n", "hello");
	TEST("[%.6s]\n", "hello");
	printf("-------- s --------\n");
	// d
	printf("-------- d --------\n");
	// TEST("[ %01d ]\n", 0);
	// exit(1);
	TEST("[ %02d ]\n", -1);
	// exit(1);
	TEST("[ %04d ]\n", 9);
	TEST("[ %01d ]\n", 10);
	TEST("[ %02d ]\n", 11);
	TEST("[ %03d ]\n", 15);
	TEST("[ %04d ]\n", 16);
	TEST("[ %05d ]\n", 17);
	TEST("[ %01d ]\n", 99);
	TEST("[ %02d ]\n", 100);
	TEST("[ %03d ]\n", 101);
	TEST("[ %01d ]\n", -9);
	TEST("[ %02d ]\n", -10);
	TEST("[ %03d ]\n", -11);
	TEST("[ %04d ]\n", -14);
	TEST("[ %05d ]\n", -15);
	TEST("[ %06d ]\n", -16);
	TEST("[ %01d ]\n", -99);
	TEST("[ %02d ]\n", -100);
	TEST("[ %03d ]\n", -101);
	TEST("[ %09d ]\n", INT_MAX);
	TEST("[ %010d ]\n", INT_MIN);
	TEST("[ %011d ]\n", LONG_MAX);
	TEST("[ %012d ]\n", LONG_MIN);
	TEST("[ %013d ]\n", UINT_MAX);
	TEST("[ %014d ]\n", ULONG_MAX);
	TEST("[ %015d ]\n", 9223372036854775807LL);
	TEST("[ %09d %010d %011d %012d %013d %014d %015d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[ %01i ]\n", 0);
	TEST("[ %02i ]\n", -1);
	TEST("[ %04i ]\n", 9);
	TEST("[ %01i ]\n", 10);
	TEST("[ %02i ]\n", 11);
	TEST("[ %03i ]\n", 15);
	TEST("[ %04i ]\n", 16);
	TEST("[ %05i ]\n", 17);
	TEST("[ %01i ]\n", 99);
	TEST("[ %02i ]\n", 100);
	TEST("[ %03i ]\n", 101);
	TEST("[ %01i ]\n", -9);
	TEST("[ %02i ]\n", -10);
	TEST("[ %03i ]\n", -11);
	TEST("[ %04i ]\n", -14);
	TEST("[ %05i ]\n", -15);
	TEST("[ %06i ]\n", -16);
	TEST("[ %01i ]\n", -99);
	TEST("[ %02i ]\n", -100);
	TEST("[ %03i ]\n", -101);
	TEST("[ %09i ]\n", INT_MAX);
	TEST("[ %010i ]\n", INT_MIN);
	TEST("[ %011i ]\n", LONG_MAX);
	TEST("[ %012i ]\n", LONG_MIN);
	TEST("[ %013i ]\n", UINT_MAX);
	TEST("[ %014i ]\n", ULONG_MAX);
	TEST("[ %015i ]\n", 9223372036854775807LL);
	TEST("[ %09i %010i %011i %012i %013i %014i %015i]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- i --------\n");
	// u
	printf("-------- u --------\n");
	TEST("[ %01u ]\n", 0);
	TEST("[ %02u ]\n", -1);
	TEST("[ %04u ]\n", 9);
	TEST("[ %01u ]\n", 10);
	TEST("[ %02u ]\n", 11);
	TEST("[ %03u ]\n", 15);
	TEST("[ %04u ]\n", 16);
	TEST("[ %05u ]\n", 17);
	TEST("[ %01u ]\n", 99);
	TEST("[ %02u ]\n", 100);
	TEST("[ %03u ]\n", 101);
	TEST("[ %01u ]\n", -9);
	TEST("[ %02u ]\n", -10);
	TEST("[ %03u ]\n", -11);
	TEST("[ %04u ]\n", -14);
	TEST("[ %05u ]\n", -15);
	TEST("[ %06u ]\n", -16);
	TEST("[ %01u ]\n", -99);
	TEST("[ %02u ]\n", -100);
	TEST("[ %03u ]\n", -101);
	TEST("[ %09u ]\n", INT_MAX);
	TEST("[ %010u ]\n", INT_MIN);
	TEST("[ %011u ]\n", LONG_MAX);
	TEST("[ %012u ]\n", LONG_MIN);
	TEST("[ %013u ]\n", UINT_MAX);
	TEST("[ %014u ]\n", ULONG_MAX);
	TEST("[ %015u ]\n", 9223372036854775807LL);
	TEST("[ %09u %010u %011u %012u %013u %014u %015u]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- u --------\n");
	// x
	printf("-------- x --------\n");
	TEST("[ %01x ]\n", 0);
	TEST("[ %02x ]\n", -1);
	TEST("[ %04x ]\n", 9);
	TEST("[ %01x ]\n", 10);
	TEST("[ %02x ]\n", 11);
	TEST("[ %03x ]\n", 15);
	TEST("[ %04x ]\n", 16);
	TEST("[ %05x ]\n", 17);
	TEST("[ %01x ]\n", 99);
	TEST("[ %02x ]\n", 100);
	TEST("[ %03x ]\n", 101);
	TEST("[ %01x ]\n", -9);
	TEST("[ %02x ]\n", -10);
	TEST("[ %03x ]\n", -11);
	TEST("[ %04x ]\n", -14);
	TEST("[ %05x ]\n", -15);
	TEST("[ %06x ]\n", -16);
	TEST("[ %01x ]\n", -99);
	TEST("[ %02x ]\n", -100);
	TEST("[ %03x ]\n", -101);
	TEST("[ %09x ]\n", INT_MAX);
	TEST("[ %010x ]\n", INT_MIN);
	TEST("[ %011x ]\n", LONG_MAX);
	TEST("[ %012x ]\n", LONG_MIN);
	TEST("[ %013x ]\n", UINT_MAX);
	TEST("[ %014x ]\n", ULONG_MAX);
	TEST("[ %015x ]\n", 9223372036854775807LL);
	TEST("[ %09x %010x %011x %012x %013x %014x %015x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- x --------\n");
	// X
	printf("-------- X --------\n");
	TEST("[ %01X ]\n", 0);
	TEST("[ %02X ]\n", -1);
	TEST("[ %04X ]\n", 9);
	TEST("[ %01X ]\n", 10);
	TEST("[ %02X ]\n", 11);
	TEST("[ %03X ]\n", 15);
	TEST("[ %04X ]\n", 16);
	TEST("[ %05X ]\n", 17);
	TEST("[ %01X ]\n", 99);
	TEST("[ %02X ]\n", 100);
	TEST("[ %03X ]\n", 101);
	TEST("[ %01X ]\n", -9);
	TEST("[ %02X ]\n", -10);
	TEST("[ %03X ]\n", -11);
	TEST("[ %04X ]\n", -14);
	TEST("[ %05X ]\n", -15);
	TEST("[ %06X ]\n", -16);
	TEST("[ %01X ]\n", -99);
	TEST("[ %02X ]\n", -100);
	TEST("[ %03X ]\n", -101);
	TEST("[ %09X ]\n", INT_MAX);
	TEST("[ %010X ]\n", INT_MIN);
	TEST("[ %011X ]\n", LONG_MAX);
	TEST("[ %012X ]\n", LONG_MIN);
	TEST("[ %013X ]\n", UINT_MAX);
	TEST("[ %014X ]\n", ULONG_MAX);
	TEST("[ %015X ]\n", 9223372036854775807LL);
	TEST("[ %09X %010X %011X %012X %013X %014X %015X]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- X --------\n");
	// %
	printf("-------- %% --------\n");
	TEST("[%010%]\n");
	TEST("[%.10%]\n");
	TEST("[%10.5%]\n");
	TEST("[%010.5%]\n");
	TEST("[%-010%]\n");
	TEST("[%0-10%]\n");
	printf("-------- %% --------\n");
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
	TEST("[%.s]\n", "");
	TEST("[ %.1s]\n", "");
	TEST("[%.1s ]\n", "");
	TEST("[ %.s ]\n", "");
	TEST("[ %.s ]\n", "-");
	TEST("[ %.2s %.1s ]\n", "", "-");
	TEST("[ %.3s %.2s ]\n", " - ", "");
	TEST("[ %.1s %.2s %.3s %.4s ]\n", " - ", "", "4", "");
	TEST("[ %.2s %.3s %.4s %.5s %.1s ]\n", " - ", "", "4", "", "2 ");
	printf("-------- s --------\n");
	// d
	printf("-------- d --------\n");
	TEST("[ %.1d ]\n", 0);
	TEST("[ %.2d ]\n", -1);
	TEST("[ %.2d ]\n", 9);
	TEST("[ %.1d ]\n", 10);
	TEST("[ %.2d ]\n", 11);
	TEST("[ %.3d ]\n", 15);
	TEST("[ %.4d ]\n", 16);
	TEST("[ %.5d ]\n", 17);
	TEST("[ %.6d ]\n", 99);
	TEST("[ %.1d ]\n", 100);
	TEST("[ %.2d ]\n", 101);
	TEST("[ %.3d ]\n", -9);
	TEST("[ %.1d ]\n", -10);
	TEST("[ %.2d ]\n", -11);
	TEST("[ %.3d ]\n", -14);
	TEST("[ %.4d ]\n", -15);
	TEST("[ %.1d ]\n", -16);
	TEST("[ %.2d ]\n", -99);
	TEST("[ %.3d ]\n", -100);
	TEST("[ %.3d ]\n", -101);
	TEST("[ %.4d ]\n", INT_MAX);
	TEST("[ %.8d ]\n", INT_MIN);
	TEST("[ %.9d ]\n", LONG_MAX);
	TEST("[ %.10d ]\n", LONG_MIN);
	TEST("[ %.11d ]\n", UINT_MAX);
	TEST("[ %.12d ]\n", ULONG_MAX);
	TEST("[ %.13d ]\n", 9223372036854775807LL);
	TEST("[ %.14d ]\n", 9223372036854775807LL);
	TEST("[ %.8d %.9d %.10d %.11d %.12d %.13d %.14d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[ %.1i ]\n", 0);
	TEST("[ %.2i ]\n", -1);
	TEST("[ %.2i ]\n", 9);
	TEST("[ %.1i ]\n", 10);
	TEST("[ %.2i ]\n", 11);
	TEST("[ %.3i ]\n", 15);
	TEST("[ %.4i ]\n", 16);
	TEST("[ %.5i ]\n", 17);
	TEST("[ %.6i ]\n", 99);
	TEST("[ %.1i ]\n", 100);
	TEST("[ %.2i ]\n", 101);
	TEST("[ %.3i ]\n", -9);
	TEST("[ %.1i ]\n", -10);
	TEST("[ %.2i ]\n", -11);
	TEST("[ %.3i ]\n", -14);
	TEST("[ %.4i ]\n", -15);
	TEST("[ %.1i ]\n", -16);
	TEST("[ %.2i ]\n", -99);
	TEST("[ %.3i ]\n", -100);
	TEST("[ %.3i ]\n", -101);
	TEST("[ %.4i ]\n", INT_MAX);
	TEST("[ %.8i ]\n", INT_MIN);
	TEST("[ %.9i ]\n", LONG_MAX);
	TEST("[ %.10i ]\n", LONG_MIN);
	TEST("[ %.11i ]\n", UINT_MAX);
	TEST("[ %.12i ]\n", ULONG_MAX);
	TEST("[ %.13i ]\n", 9223372036854775807LL);
	TEST("[ %.14i ]\n", 9223372036854775807LL);
	TEST("[ %.8i %.9i %.10i %.11i %.12i %.13i %.14i]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- i --------\n");
	// u
	printf("-------- u --------\n");
	TEST("[ %.1u ]\n", 0);
	TEST("[ %.2u ]\n", -1);
	TEST("[ %.2u ]\n", 9);
	TEST("[ %.1u ]\n", 10);
	TEST("[ %.2u ]\n", 11);
	TEST("[ %.3u ]\n", 15);
	TEST("[ %.4u ]\n", 16);
	TEST("[ %.5u ]\n", 17);
	TEST("[ %.6u ]\n", 99);
	TEST("[ %.1u ]\n", 100);
	TEST("[ %.2u ]\n", 101);
	TEST("[ %.3u ]\n", -9);
	TEST("[ %.1u ]\n", -10);
	TEST("[ %.2u ]\n", -11);
	TEST("[ %.3u ]\n", -14);
	TEST("[ %.4u ]\n", -15);
	TEST("[ %.1u ]\n", -16);
	TEST("[ %.2u ]\n", -99);
	TEST("[ %.3u ]\n", -100);
	TEST("[ %.3u ]\n", -101);
	TEST("[ %.4u ]\n", INT_MAX);
	TEST("[ %.8u ]\n", INT_MIN);
	TEST("[ %.9u ]\n", LONG_MAX);
	TEST("[ %.10u ]\n", LONG_MIN);
	TEST("[ %.11u ]\n", UINT_MAX);
	TEST("[ %.12u ]\n", ULONG_MAX);
	TEST("[ %.13u ]\n", 9223372036854775807LL);
	TEST("[ %.14u ]\n", 9223372036854775807LL);
	TEST("[ %.8u %.9u %.10u %.11u %.12u %.13u %.14u]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- u --------\n");
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
	TEST("[%10.6p]\n", 100);
	printf("-------- p ----------\n");
	// x
	printf("-------- x --------\n");
	TEST("[ %.1x ]\n", 0);
	TEST("[ %.2x ]\n", -1);
	TEST("[ %.2x ]\n", 9);
	TEST("[ %.1x ]\n", 10);
	TEST("[ %.2x ]\n", 11);
	TEST("[ %.3x ]\n", 15);
	TEST("[ %.4x ]\n", 16);
	TEST("[ %.5x ]\n", 17);
	TEST("[ %.6x ]\n", 99);
	TEST("[ %.1x ]\n", 100);
	TEST("[ %.2x ]\n", 101);
	TEST("[ %.3x ]\n", -9);
	TEST("[ %.1x ]\n", -10);
	TEST("[ %.2x ]\n", -11);
	TEST("[ %.3x ]\n", -14);
	TEST("[ %.4x ]\n", -15);
	TEST("[ %.1x ]\n", -16);
	TEST("[ %.2x ]\n", -99);
	TEST("[ %.3x ]\n", -100);
	TEST("[ %.3x ]\n", -101);
	TEST("[ %.4x ]\n", INT_MAX);
	TEST("[ %.8x ]\n", INT_MIN);
	TEST("[ %.9x ]\n", LONG_MAX);
	TEST("[ %.10x ]\n", LONG_MIN);
	TEST("[ %.11x ]\n", UINT_MAX);
	TEST("[ %.12x ]\n", ULONG_MAX);
	TEST("[ %.13x ]\n", 9223372036854775807LL);
	TEST("[ %.14x ]\n", 9223372036854775807LL);
	TEST("[ %.8x %.9x %.10x %.11x %.12x %.13x %.14x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- x --------\n");
	// X
	printf("-------- X --------\n");
	TEST("[ %.1X ]\n", 0);
	TEST("[ %.2X ]\n", -1);
	TEST("[ %.2X ]\n", 9);
	TEST("[ %.1X ]\n", 10);
	TEST("[ %.2X ]\n", 11);
	TEST("[ %.3X ]\n", 15);
	TEST("[ %.4X ]\n", 16);
	TEST("[ %.5X ]\n", 17);
	TEST("[ %.6X ]\n", 99);
	TEST("[ %.1X ]\n", 100);
	TEST("[ %.2X ]\n", 101);
	TEST("[ %.3X ]\n", -9);
	TEST("[ %.1X ]\n", -10);
	TEST("[ %.2X ]\n", -11);
	TEST("[ %.3X ]\n", -14);
	TEST("[ %.4X ]\n", -15);
	TEST("[ %.1X ]\n", -16);
	TEST("[ %.2X ]\n", -99);
	TEST("[ %.3X ]\n", -100);
	TEST("[ %.3X ]\n", -101);
	TEST("[ %.4X ]\n", INT_MAX);
	TEST("[ %.8X ]\n", INT_MIN);
	TEST("[ %.9X ]\n", LONG_MAX);
	TEST("[ %.10X ]\n", LONG_MIN);
	TEST("[ %.11X ]\n", UINT_MAX);
	TEST("[ %.12X ]\n", ULONG_MAX);
	TEST("[ %.13X ]\n", 9223372036854775807LL);
	TEST("[ %.14X ]\n", 9223372036854775807LL);
	TEST("[ %.8X %.9X %.10X %.11X %.12X %.13X %.14X]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- X --------\n");
	printf("....................\n");
	#endif

	// sharp
	#ifdef SHARP
	// x
	printf("#######SHARP#######\n");
	printf("-------- x --------\n");
	TEST("[ %#x ]\n", 0);
	TEST("[ %#x ]\n", -1);
	TEST("[ %#x ]\n", 1);
	TEST("[ %#x ]\n", 9);
	TEST("[ %#x ]\n", 10);
	TEST("[ %#x ]\n", 11);
	TEST("[ %#x ]\n", 15);
	TEST("[ %#x ]\n", 16);
	TEST("[ %#x ]\n", 17);
	TEST("[ %#x ]\n", 99);
	TEST("[ %#x ]\n", 100);
	TEST("[ %#x ]\n", 101);
	TEST("[ %#x ]\n", -9);
	TEST("[ %#x ]\n", -10);
	TEST("[ %#x ]\n", -11);
	TEST("[ %#x ]\n", -15);
	TEST("[ %#x ]\n", -16);
	TEST("[ %#x ]\n", -17);
	TEST("[ %#x ]\n", -99);
	TEST("[ %#x ]\n", -100);
	TEST("[ %#x ]\n", -101);
	TEST("[ %#x ]\n", INT_MAX);
	TEST("[ %#x ]\n", INT_MIN);
	TEST("[ %#x ]\n", LONG_MAX);
	TEST("[ %#x ]\n", LONG_MIN);
	TEST("[ %#x ]\n", UINT_MAX);
	TEST("[ %#x ]\n", ULONG_MAX);
	TEST("[ %#x ]\n", 9223372036854775807LL);
	TEST("[ %#x %#x %#x %#x %#x %#x %#x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	TEST("[ %#x%#x ]\n", INT_MAX, INT_MIN);
	printf("-------- x --------\n");
	// X
	printf("-------- X --------\n");
	TEST("[ %#X ]\n", 0);
	TEST("[ %#X ]\n", -1);
	TEST("[ %#X ]\n", 1);
	TEST("[ %#X ]\n", 9);
	TEST("[ %#X ]\n", 10);
	TEST("[ %#X ]\n", 11);
	TEST("[ %#X ]\n", 15);
	TEST("[ %#X ]\n", 16);
	TEST("[ %#X ]\n", 17);
	TEST("[ %#X ]\n", 99);
	TEST("[ %#X ]\n", 100);
	TEST("[ %#X ]\n", 101);
	TEST("[ %#X ]\n", -9);
	TEST("[ %#X ]\n", -10);
	TEST("[ %#X ]\n", -11);
	TEST("[ %#X ]\n", -15);
	TEST("[ %#X ]\n", -16);
	TEST("[ %#X ]\n", -17);
	TEST("[ %#X ]\n", -99);
	TEST("[ %#X ]\n", -100);
	TEST("[ %#X ]\n", -101);
	TEST("[ %#X ]\n", INT_MAX);
	TEST("[ %#X ]\n", INT_MIN);
	TEST("[ %#X ]\n", LONG_MAX);
	TEST("[ %#X ]\n", LONG_MIN);
	TEST("[ %#X ]\n", UINT_MAX);
	TEST("[ %#X ]\n", ULONG_MAX);
	TEST("[ %#X ]\n", 9223372036854775807LL);
	TEST("[ %#X %#X %#X %#X %#X %#X %#X]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	TEST("[ %#X%#X ]\n", INT_MAX, INT_MIN);
	printf("-------- X --------\n");
	printf("###################\n");
	#endif

	// space
	#ifdef SPACE
	printf("       SPACE       \n");
	// s
	printf("-------- s --------\n");
	TEST("[% s]\n", "");
	TEST("[ % 1s]\n", "");
	TEST("[% 1s ]\n", "");
	TEST("[ % s ]\n", "");
	TEST("[ % s ]\n", "-");
	TEST("[ % s % s ]\n", "", "-");
	TEST("[ % s % s ]\n", " - ", "");
	TEST("[ % s % s % s % s ]\n", " - ", "", "4", "");
	TEST("[ % s % s % s % s % s ]\n", " - ", "", "4", "", "2 ");
	printf("-------- s --------\n");
	// d
	printf("-------- d --------\n");
	TEST("[ % d ]\n", 0);
	TEST("[ % d ]\n", -1);
	TEST("[ % d ]\n", 1);
	TEST("[ % d ]\n", 9);
	TEST("[ % d ]\n", 10);
	TEST("[ % d ]\n", 11);
	TEST("[ % d ]\n", 15);
	TEST("[ % d ]\n", 16);
	TEST("[ % d ]\n", 17);
	TEST("[ % d ]\n", 99);
	TEST("[ % d ]\n", 100);
	TEST("[ % d ]\n", 101);
	TEST("[ % d ]\n", -9);
	TEST("[ % d ]\n", -10);
	TEST("[ % d ]\n", -11);
	TEST("[ % d ]\n", -14);
	TEST("[ % d ]\n", -15);
	TEST("[ % d ]\n", -16);
	TEST("[ % d ]\n", -99);
	TEST("[ % d ]\n", -100);
	TEST("[ % d ]\n", -101);
	TEST("[ % d ]\n", INT_MAX);
	TEST("[ % d ]\n", INT_MIN);
	TEST("[ % d ]\n", LONG_MAX);
	TEST("[ % d ]\n", LONG_MIN);
	TEST("[ % d ]\n", UINT_MAX);
	TEST("[ % d ]\n", ULONG_MAX);
	TEST("[ % d ]\n", 9223372036854775807LL);
	TEST("[ % d % d % d % d % d % d % d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[ % i ]\n", 0);
	TEST("[ % i ]\n", -1);
	TEST("[ % i ]\n", 1);
	TEST("[ % i ]\n", 9);
	TEST("[ % i ]\n", 10);
	TEST("[ % i ]\n", 11);
	TEST("[ % i ]\n", 15);
	TEST("[ % i ]\n", 16);
	TEST("[ % i ]\n", 17);
	TEST("[ % i ]\n", 99);
	TEST("[ % i ]\n", 100);
	TEST("[ % i ]\n", 101);
	TEST("[ % i ]\n", -9);
	TEST("[ % i ]\n", -10);
	TEST("[ % i ]\n", -11);
	TEST("[ % i ]\n", -14);
	TEST("[ % i ]\n", -15);
	TEST("[ % i ]\n", -16);
	TEST("[ % i ]\n", -99);
	TEST("[ % i ]\n", -100);
	TEST("[ % i ]\n", -101);
	TEST("[ % i ]\n", INT_MAX);
	TEST("[ % i ]\n", INT_MIN);
	TEST("[ % i ]\n", LONG_MAX);
	TEST("[ % i ]\n", LONG_MIN);
	TEST("[ % i ]\n", UINT_MAX);
	TEST("[ % i ]\n", ULONG_MAX);
	TEST("[ % i ]\n", 9223372036854775807LL);
	TEST("[ % i % i % i % i % i % i % i]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- i --------\n");
	printf("       SPACE       \n");
	#endif

	// plus
	#ifdef PLUS
	printf("+++++++PLUS++++++++\n");
	// d
	printf("-------- d --------\n");
	TEST("[ %+d ]\n", 0);
	TEST("[ %+d ]\n", -1);
	TEST("[ %+d ]\n", 9);
	TEST("[ %+d ]\n", 10);
	TEST("[ %+d ]\n", 11);
	TEST("[ %+d ]\n", 15);
	TEST("[ %+d ]\n", 16);
	TEST("[ %+d ]\n", 17);
	TEST("[ %+d ]\n", 99);
	TEST("[ %+d ]\n", 100);
	TEST("[ %+d ]\n", 101);
	TEST("[ %+d ]\n", -9);
	TEST("[ %+d ]\n", -10);
	TEST("[ %+d ]\n", -11);
	TEST("[ %+d ]\n", -14);
	TEST("[ %+d ]\n", -15);
	TEST("[ %+d ]\n", -16);
	TEST("[ %+d ]\n", -99);
	TEST("[ %+d ]\n", -100);
	TEST("[ %+d ]\n", -101);
	TEST("[ %+d ]\n", INT_MAX);
	TEST("[ %+d ]\n", INT_MIN);
	TEST("[ %+d ]\n", LONG_MAX);
	TEST("[ %+d ]\n", LONG_MIN);
	TEST("[ %+d ]\n", UINT_MAX);
	TEST("[ %+d ]\n", ULONG_MAX);
	TEST("[ %+d ]\n", 9223372036854775807LL);
	TEST("[ %+d %+d %+d %+d %+d %+d %+d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[ %+i ]\n", 0);
	TEST("[ %+i ]\n", -1);
	TEST("[ %+i ]\n", 9);
	TEST("[ %+i ]\n", 10);
	TEST("[ %+i ]\n", 11);
	TEST("[ %+i ]\n", 15);
	TEST("[ %+i ]\n", 16);
	TEST("[ %+i ]\n", 17);
	TEST("[ %+i ]\n", 99);
	TEST("[ %+i ]\n", 100);
	TEST("[ %+i ]\n", 101);
	TEST("[ %+i ]\n", -9);
	TEST("[ %+i ]\n", -10);
	TEST("[ %+i ]\n", -11);
	TEST("[ %+i ]\n", -14);
	TEST("[ %+i ]\n", -15);
	TEST("[ %+i ]\n", -16);
	TEST("[ %+i ]\n", -99);
	TEST("[ %+i ]\n", -100);
	TEST("[ %+i ]\n", -101);
	TEST("[ %+i ]\n", INT_MAX);
	TEST("[ %+i ]\n", INT_MIN);
	TEST("[ %+i ]\n", LONG_MAX);
	TEST("[ %+i ]\n", LONG_MIN);
	TEST("[ %+i ]\n", UINT_MAX);
	TEST("[ %+i ]\n", ULONG_MAX);
	TEST("[ %+i ]\n", 9223372036854775807LL);
	TEST("[ %+i %+i %+i %+i %+i %+i %+i]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- i --------\n");
	printf("++++++++++++++++++++\n");
	#endif

	// minus
	#ifdef MINUS
	printf("-------MINUS-------\n");
	printf("-------- c --------\n");
	TEST("[%-000c]\n", 'a');
	TEST("[%-00c]\n", 'a');
	TEST("[%-0c]\n", 'a');
	TEST("[%-1c]\n", 'a');
	TEST("[%-2c]\n", 'a');
	TEST("[%-3c]\n", 'a');
	printf("-------- c --------\n");
	// s
	printf("-------- s --------\n");
	TEST("[%-0.0s]\n", "");
	TEST("[%-.0s]\n", "");
	TEST("[%-00s]\n", "");
	TEST("[%-0s]\n", "");
	TEST("[%-10.3s]\n", "hello");
	TEST("[%-1.6s]\n", "hello");
	TEST("[%-1.1s]\n", "hello");
	TEST("[%-10.10s]\n", "hello");
	TEST("[%-10.6s]\n", "hello");
	printf("-------- s --------\n");
	// p
	printf("-------- p --------\n");
	TEST(" [%-2p] \n", 1);
	TEST("[%-00p]\n", 0);
	TEST("[%-0p]\n", 0);
	TEST("[%-0p]\n", 1);
	TEST("[%-p]\n", 1000);
	TEST("[%-.0p]\n", 0);
	TEST("[%-0.0p]\n", 0);
	TEST("[%-10.7p]\n", 1000);
	TEST("[%-20.10p]\n", INT_MAX);
	TEST("[%-20.10p]\n", INT_MIN);
	printf("--------------------\n");
	// d
	printf("-------- d --------\n");
	TEST("[ %-1d ]\n", 0);
	TEST("[ %-2d ]\n", -1);
	TEST("[ %-2d ]\n", 9);
	TEST("[ %-1d ]\n", 10);
	TEST("[ %-2d ]\n", 11);
	TEST("[ %-3d ]\n", 15);
	TEST("[ %-4d ]\n", 16);
	TEST("[ %-5d ]\n", 17);
	TEST("[ %-6d ]\n", 99);
	TEST("[ %-1d ]\n", 100);
	TEST("[ %-2d ]\n", 101);
	TEST("[ %-3d ]\n", -9);
	TEST("[ %-1d ]\n", -10);
	TEST("[ %-2d ]\n", -11);
	TEST("[ %-3d ]\n", -14);
	TEST("[ %-4d ]\n", -15);
	TEST("[ %-1d ]\n", -16);
	TEST("[ %-2d ]\n", -99);
	TEST("[ %-3d ]\n", -100);
	TEST("[ %-3d ]\n", -101);
	TEST("[ %-4d ]\n", INT_MAX);
	TEST("[ %-8d ]\n", INT_MIN);
	TEST("[ %-9d ]\n", LONG_MAX);
	TEST("[ %-10d ]\n", LONG_MIN);
	TEST("[ %-11d ]\n", UINT_MAX);
	TEST("[ %-12d ]\n", ULONG_MAX);
	TEST("[ %-13d ]\n", 9223372036854775807LL);
	TEST("[ %-14d ]\n", 9223372036854775807LL);
	TEST("[ %-8d %-9d %-10d %-11d %-12d %-13d %-14d]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- d --------\n");
	// i
	printf("-------- i --------\n");
	TEST("[ %-1i ]\n", 0);
	TEST("[ %-2i ]\n", -1);
	TEST("[ %-2i ]\n", 9);
	TEST("[ %-1i ]\n", 10);
	TEST("[ %-2i ]\n", 11);
	TEST("[ %-3i ]\n", 15);
	TEST("[ %-4i ]\n", 16);
	TEST("[ %-5i ]\n", 17);
	TEST("[ %-6i ]\n", 99);
	TEST("[ %-1i ]\n", 100);
	TEST("[ %-2i ]\n", 101);
	TEST("[ %-3i ]\n", -9);
	TEST("[ %-1i ]\n", -10);
	TEST("[ %-2i ]\n", -11);
	TEST("[ %-3i ]\n", -14);
	TEST("[ %-4i ]\n", -15);
	TEST("[ %-1i ]\n", -16);
	TEST("[ %-2i ]\n", -99);
	TEST("[ %-3i ]\n", -100);
	TEST("[ %-3i ]\n", -101);
	TEST("[ %-4i ]\n", INT_MAX);
	TEST("[ %-8i ]\n", INT_MIN);
	TEST("[ %-9i ]\n", LONG_MAX);
	TEST("[ %-10i ]\n", LONG_MIN);
	TEST("[ %-11i ]\n", UINT_MAX);
	TEST("[ %-12i ]\n", ULONG_MAX);
	TEST("[ %-13i ]\n", 9223372036854775807LL);
	TEST("[ %-14i ]\n", 9223372036854775807LL);
	TEST("[ %-8i %-9i %-10i %-11i %-12i %-13i %-14i]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- i --------\n");
	// u
	printf("-------- u --------\n");
	TEST("[ %-1u ]\n", 0);
	TEST("[ %-2u ]\n", -1);
	TEST("[ %-2u ]\n", 9);
	TEST("[ %-1u ]\n", 10);
	TEST("[ %-2u ]\n", 11);
	TEST("[ %-3u ]\n", 15);
	TEST("[ %-4u ]\n", 16);
	TEST("[ %-5u ]\n", 17);
	TEST("[ %-6u ]\n", 99);
	TEST("[ %-1u ]\n", 100);
	TEST("[ %-2u ]\n", 101);
	TEST("[ %-3u ]\n", -9);
	TEST("[ %-1u ]\n", -10);
	TEST("[ %-2u ]\n", -11);
	TEST("[ %-3u ]\n", -14);
	TEST("[ %-4u ]\n", -15);
	TEST("[ %-1u ]\n", -16);
	TEST("[ %-2u ]\n", -99);
	TEST("[ %-3u ]\n", -100);
	TEST("[ %-3u ]\n", -101);
	TEST("[ %-4u ]\n", INT_MAX);
	TEST("[ %-8u ]\n", INT_MIN);
	TEST("[ %-9u ]\n", LONG_MAX);
	TEST("[ %-10u ]\n", LONG_MIN);
	TEST("[ %-11u ]\n", UINT_MAX);
	TEST("[ %-12u ]\n", ULONG_MAX);
	TEST("[ %-13u ]\n", 9223372036854775807LL);
	TEST("[ %-14u ]\n", 9223372036854775807LL);
	TEST("[ %-8u %-9u %-10u %-11u %-12u %-13u %-14u]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- u --------\n");
	// x
	printf("-------- x --------\n");
	TEST("[ %-1x ]\n", 0);
	TEST("[ %-2x ]\n", -1);
	TEST("[ %-2x ]\n", 9);
	TEST("[ %-1x ]\n", 10);
	TEST("[ %-2x ]\n", 11);
	TEST("[ %-3x ]\n", 15);
	TEST("[ %-4x ]\n", 16);
	TEST("[ %-5x ]\n", 17);
	TEST("[ %-6x ]\n", 99);
	TEST("[ %-1x ]\n", 100);
	TEST("[ %-2x ]\n", 101);
	TEST("[ %-3x ]\n", -9);
	TEST("[ %-1x ]\n", -10);
	TEST("[ %-2x ]\n", -11);
	TEST("[ %-3x ]\n", -14);
	TEST("[ %-4x ]\n", -15);
	TEST("[ %-1x ]\n", -16);
	TEST("[ %-2x ]\n", -99);
	TEST("[ %-3x ]\n", -100);
	TEST("[ %-3x ]\n", -101);
	TEST("[ %-4x ]\n", INT_MAX);
	TEST("[ %-8x ]\n", INT_MIN);
	TEST("[ %-9x ]\n", LONG_MAX);
	TEST("[ %-10x ]\n", LONG_MIN);
	TEST("[ %-11x ]\n", UINT_MAX);
	TEST("[ %-12x ]\n", ULONG_MAX);
	TEST("[ %-13x ]\n", 9223372036854775807LL);
	TEST("[ %-14x ]\n", 9223372036854775807LL);
	TEST("[ %-8x %-9x %-10x %-11x %-12x %-13x %-14x]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- x --------\n");
	// X
	printf("-------- X --------\n");
	TEST("[ %-1X ]\n", 0);
	TEST("[ %-2X ]\n", -1);
	TEST("[ %-2X ]\n", 9);
	TEST("[ %-1X ]\n", 10);
	TEST("[ %-2X ]\n", 11);
	TEST("[ %-3X ]\n", 15);
	TEST("[ %-4X ]\n", 16);
	TEST("[ %-5X ]\n", 17);
	TEST("[ %-6X ]\n", 99);
	TEST("[ %-1X ]\n", 100);
	TEST("[ %-2X ]\n", 101);
	TEST("[ %-3X ]\n", -9);
	TEST("[ %-1X ]\n", -10);
	TEST("[ %-2X ]\n", -11);
	TEST("[ %-3X ]\n", -14);
	TEST("[ %-4X ]\n", -15);
	TEST("[ %-1X ]\n", -16);
	TEST("[ %-2X ]\n", -99);
	TEST("[ %-3X ]\n", -100);
	TEST("[ %-3X ]\n", -101);
	TEST("[ %-4X ]\n", INT_MAX);
	TEST("[ %-8X ]\n", INT_MIN);
	TEST("[ %-9X ]\n", LONG_MAX);
	TEST("[ %-10X ]\n", LONG_MIN);
	TEST("[ %-11X ]\n", UINT_MAX);
	TEST("[ %-12X ]\n", ULONG_MAX);
	TEST("[ %-13X ]\n", 9223372036854775807LL);
	TEST("[ %-14X ]\n", 9223372036854775807LL);
	TEST("[ %-8X %-9X %-10X %-11X %-12X %-13X %-14X]\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("-------- X --------\n");
	printf("-------------------\n");
	#endif

	#ifdef ALL_MIX
	TEST("[%04c][%10.5s][%5.5p][%+10.9d][%+u][%#12.1x][% X][%%]\n", 'a', "hello", 100000, INT_MAX, -1, -1, -900);
	#endif

	#ifdef COMPLEX
	// If a precision is given with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.
	// d
	printf("-------- d --------\n");
	TEST("[%%00.0d] : [%00.0d]\n", 0);
	TEST("[%%00.1d] : [%00.1d]\n", 0);
	TEST("[%%00.2d] : [%00.2d]\n", 0);
	TEST("[%%00.3d] : [%00.3d]\n", 0);
	TEST("[%%00.4d] : [%00.4d]\n", 0);
	TEST("[%%01.0d] : [%01.0d]\n", 0);
	TEST("[%%02.1d] : [%02.1d]\n", 0);
	TEST("[%%03.2d] : [%03.2d]\n", 0);
	TEST("[%%04.3d] : [%04.3d]\n", 0);
	TEST("[%%05.4d] : [%05.4d]\n", 0);

	TEST("[%%00.0d] : [%00.0d]\n", 123);
	TEST("[%%00.1d] : [%00.1d]\n", 123);
	TEST("[%%00.2d] : [%00.2d]\n", 123);
	TEST("[%%00.3d] : [%00.3d]\n", 123);
	TEST("[%%00.4d] : [%00.4d]\n", 123);
	TEST("[%%01.0d] : [%01.0d]\n", 123);
	TEST("[%%02.1d] : [%02.1d]\n", 123);
	TEST("[%%03.2d] : [%03.2d]\n", 123);
	TEST("[%%04.3d] : [%04.3d]\n", 123);
	TEST("[%%05.4d] : [%05.4d]\n", 123);
	printf("-------- d --------\n");

	// i
	printf("-------- i --------\n");
	TEST("[%%00.0i] : [%00.0i]\n", 0);
	TEST("[%%00.1i] : [%00.1i]\n", 0);
	TEST("[%%00.2i] : [%00.2i]\n", 0);
	TEST("[%%00.3i] : [%00.3i]\n", 0);
	TEST("[%%00.4i] : [%00.4i]\n", 0);
	TEST("[%%01.0i] : [%01.0i]\n", 0);
	TEST("[%%02.1i] : [%02.1i]\n", 0);
	TEST("[%%03.2i] : [%03.2i]\n", 0);
	TEST("[%%04.3i] : [%04.3i]\n", 0);
	TEST("[%%05.4i] : [%05.4i]\n", 0);

	TEST("[%%00.0i] : [%00.0i]\n", 123);
	TEST("[%%00.1i] : [%00.1i]\n", 123);
	TEST("[%%00.2i] : [%00.2i]\n", 123);
	TEST("[%%00.3i] : [%00.3i]\n", 123);
	TEST("[%%00.4i] : [%00.4i]\n", 123);
	TEST("[%%01.0i] : [%01.0i]\n", 123);
	TEST("[%%02.1i] : [%02.1i]\n", 123);
	TEST("[%%03.2i] : [%03.2i]\n", 123);
	TEST("[%%04.3i] : [%04.3i]\n", 123);
	TEST("[%%05.4i] : [%05.4i]\n", 123);
	printf("-------- i --------\n");

	// u
	printf("-------- u --------\n");
	TEST("[%%00.0u] : [%00.0u]\n", 0);
	TEST("[%%00.1u] : [%00.1u]\n", 0);
	TEST("[%%00.2u] : [%00.2u]\n", 0);
	TEST("[%%00.3u] : [%00.3u]\n", 0);
	TEST("[%%00.4u] : [%00.4u]\n", 0);
	TEST("[%%01.0u] : [%01.0u]\n", 0);
	TEST("[%%02.1u] : [%02.1u]\n", 0);
	TEST("[%%03.2u] : [%03.2u]\n", 0);
	TEST("[%%04.3u] : [%04.3u]\n", 0);
	TEST("[%%05.4u] : [%05.4u]\n", 0);

	TEST("[%%00.0u] : [%00.0u]\n", 123);
	TEST("[%%00.1u] : [%00.1u]\n", 123);
	TEST("[%%00.2u] : [%00.2u]\n", 123);
	TEST("[%%00.3u] : [%00.3u]\n", 123);
	TEST("[%%00.4u] : [%00.4u]\n", 123);
	TEST("[%%01.0u] : [%01.0u]\n", 123);
	TEST("[%%02.1u] : [%02.1u]\n", 123);
	TEST("[%%03.2u] : [%03.2u]\n", 123);
	TEST("[%%04.3u] : [%04.3u]\n", 123);
	TEST("[%%05.4u] : [%05.4u]\n", 123);
	printf("-------- u --------\n");

	// x
	printf("-------- x --------\n");
	TEST("[%%00.0x] : [%00.0x]\n", 0);
	TEST("[%%00.1x] : [%00.1x]\n", 0);
	TEST("[%%00.2x] : [%00.2x]\n", 0);
	TEST("[%%00.3x] : [%00.3x]\n", 0);
	TEST("[%%00.4x] : [%00.4x]\n", 0);
	TEST("[%%01.0x] : [%01.0x]\n", 0);
	TEST("[%%02.1x] : [%02.1x]\n", 0);
	TEST("[%%03.2x] : [%03.2x]\n", 0);
	TEST("[%%04.3x] : [%04.3x]\n", 0);
	TEST("[%%05.4x] : [%05.4x]\n", 0);

	TEST("[%%00.0x] : [%00.0x]\n", 123);
	TEST("[%%00.1x] : [%00.1x]\n", 123);
	TEST("[%%00.2x] : [%00.2x]\n", 123);
	TEST("[%%00.3x] : [%00.3x]\n", 123);
	TEST("[%%00.4x] : [%00.4x]\n", 123);
	TEST("[%%01.0x] : [%01.0x]\n", 123);
	TEST("[%%02.1x] : [%02.1x]\n", 123);
	TEST("[%%03.2x] : [%03.2x]\n", 123);
	TEST("[%%04.3x] : [%04.3x]\n", 123);
	TEST("[%%05.4x] : [%05.4x]\n", 123);
	printf("-------- x --------\n");

	// X
	printf("-------- X --------\n");
	TEST("[%%00.0X] : [%00.0X]\n", 0);
	TEST("[%%00.1X] : [%00.1X]\n", 0);
	TEST("[%%00.2X] : [%00.2X]\n", 0);
	TEST("[%%00.3X] : [%00.3X]\n", 0);
	TEST("[%%00.4X] : [%00.4X]\n", 0);
	TEST("[%%01.0X] : [%01.0X]\n", 0);
	TEST("[%%02.1X] : [%02.1X]\n", 0);
	TEST("[%%03.2X] : [%03.2X]\n", 0);
	TEST("[%%04.3X] : [%04.3X]\n", 0);
	TEST("[%%05.4X] : [%05.4X]\n", 0);

	TEST("[%%00.0X] : [%00.0X]\n", 123);
	TEST("[%%00.1X] : [%00.1X]\n", 123);
	TEST("[%%00.2X] : [%00.2X]\n", 123);
	TEST("[%%00.3X] : [%00.3X]\n", 123);
	TEST("[%%00.4X] : [%00.4X]\n", 123);
	TEST("[%%01.0X] : [%01.0X]\n", 123);
	TEST("[%%02.1X] : [%02.1X]\n", 123);
	TEST("[%%03.2X] : [%03.2X]\n", 123);
	TEST("[%%04.3X] : [%04.3X]\n", 123);
	TEST("[%%05.4X] : [%05.4X]\n", 123);
	printf("-------- X --------\n");

	// p
	printf("-------- p --------\n");
	TEST("[%%00.0p] : [%00.0p]\n", 0);
	TEST("[%%00.1p] : [%00.1p]\n", 0);
	TEST("[%%00.2p] : [%00.2p]\n", 0);
	TEST("[%%00.3p] : [%00.3p]\n", 0);
	TEST("[%%00.4p] : [%00.4p]\n", 0);
	// TEST("[%%01.0p] : [%01.0p]\n", 0);
	// TEST("[%%02.1p] : [%02.1p]\n", 0);
	// TEST("[%%03.2p] : [%03.2p]\n", 0);
	// TEST("[%%04.3p] : [%04.3p]\n", 0);
	// TEST("[%%05.4p] : [%05.4p]\n", 0);

	// TEST("[%%00.0p] : [%00.0p]\n", 123);
	// TEST("[%%00.1p] : [%00.1p]\n", 123);
	// TEST("[%%00.2p] : [%00.2p]\n", 123);
	// TEST("[%%00.3p] : [%00.3p]\n", 123);
	// TEST("[%%00.4p] : [%00.4p]\n", 123);
	// TEST("[%%01.0p] : [%01.0p]\n", 123);
	// TEST("[%%02.1p] : [%02.1p]\n", 123);
	// TEST("[%%03.2p] : [%03.2p]\n", 123);
	// TEST("[%%04.3p] : [%04.3p]\n", 123);
	// TEST("[%%05.4p] : [%05.4p]\n", 123);
	printf("-------- p --------\n");

	// A - overrides a 0 if both are given.

	// A + overrides a space if both are used.
	#endif
	// sleep(30);
	// system("leaks ./a.out");
}
