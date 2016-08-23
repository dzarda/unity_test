all: test_arg_check test_mapping

test_arg_check:
	clang -std=c99 -I../unity/src ../unity/src/unity.c -I. -Iinclude ../partition.c mock_null.c test_arg_check.c -o test_arg_check.out

test_mapping:
	clang -std=c99 -I../unity/src ../unity/src/unity.c -Imapping -Iinclude ../partition.c mock_mapping.c test_mapping.c -o test_mapping.out

