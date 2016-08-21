all: mapping

arg_check:
	clang -std=c99 -I../unity/src ../unity/src/unity.c -Iinclude ../flash_partition.c mock_null.c test_arg_check.c -o test_arg_check.out

mapping:
	clang -std=c99 -I../unity/src ../unity/src/unity.c -Iinclude ../flash_partition.c mock_mapping.c test_mapping.c -o test_mapping.out

