#!/bin/zsh

DUMP_FILE="/dev/null"

cd ..
make > ${DUMP_FILE}
cd .test

./grade_c.sh
./grade_d.sh
./grade_i.sh
./grade_lower_x.sh
./grade_p.sh
./grade_s.sh
./grade_upper_x.sh
