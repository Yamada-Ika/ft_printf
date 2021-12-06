#!/bin/zsh

DUMP_FILE="/dev/null"
TEST="test_c_conversion.c"

gcc ${TEST} ../libftprintf.a 2> ${DUMP_FILE}
./a.out 2> ${DUMP_FILE} | grep -a "lib" | awk '{print $3 $4}' > lib_result_c
./a.out 2> ${DUMP_FILE} | grep -a "ft" | awk '{print $3 $4}' > ft_result_c
LEAKS_CNT=$(./a.out 2> ${DUMP_FILE} | grep -a 'leaks' | awk 'NR==3 {print $3}')
diff ft_result lib_result > diff_result_c
diff_size=$(ls -l | grep diff_result_c | awk '{print $5}')
if [ ${diff_size} = 0 ]; then
	printf "${TEST} \033[32mOK!\033[m ${LEAKS_CNT} leaks!\n"
else
	printf "${TEST} \033[31mKO!\033[m\ ${LEAKS_CNT} leaks!n"
fi
