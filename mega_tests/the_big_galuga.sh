#!/bin/bash

#Lets gooooo!

CC=cc
CFLAGS="-WAll -Wextra -Werror"

TEST_FILES("e_main.c" "lm_main.c" "ls_main.c" "lt_main.c" "ss_main.c" "st_main.c" "sm_main.c" "w_main.c" "n_main.c")

for test_file in "${TEST_FILES[@]}"; do
	test_name=$(basename "$test_file" .c)
	$CC $CFLAGS -o "$test_name" get_next_line.c get_next_line_utils.c "$test_file"
	if [ $? -eq 0 ]; then
		echo "Running test: $test_name"
		./"$test_name"
	else
		echo "Error compiling test: $test_name"
	fi

	rm -f "$test_name
done