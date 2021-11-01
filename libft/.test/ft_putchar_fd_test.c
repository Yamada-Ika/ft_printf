#include "../libft.h"

void run_ft_putchar_fd_test(void) {
	for (int i = 0; i < 256; ++i) {
		ft_putchar_fd(i, STDOUT_FILENO);
		if ((i + 1) % 41 == 0)
			putchar('\n');
	}
}

int main(void) {
	run_ft_putchar_fd_test();
	return (0);
}