all: arg_check

arg_check:
	gcc -std=c99 -I../unity/src ../unity/src/unity.c -Iinclude ../flash_partition.c mock_null.c test_arg_check.c -o test_arg_check
