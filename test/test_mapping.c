#include "unity.h"
#include "mock_mapping.h"
#include "../partition.h"

void setUp(void)
{
	mock_setUp();
}

void tearDown(void)
{
	mock_tearDown();
}

void test_read_identity(void)
{
	DECLARE_NULL_MEMORY_DEVICE(mem);
	DECLARE_PARTITION(part, &mem, 0, 1000);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_read(&part, 0, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_UINT32(0, used_addr);
	TEST_ASSERT_EQUAL_PTR((char*)0xDEAD, used_ptr);
	TEST_ASSERT_EQUAL_UINT32(1, used_bytes);
}

void test_write_identity(void)
{
	DECLARE_NULL_MEMORY_DEVICE(mem);
	DECLARE_PARTITION(part, &mem, 0, 1000);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_write(&part, 0, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_PTR(&mem, used_mem);
	TEST_ASSERT_EQUAL_UINT32(0, used_addr);
	TEST_ASSERT_EQUAL_PTR((char*)0xDEAD, used_ptr);
	TEST_ASSERT_EQUAL_UINT32(1, used_bytes);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_read_identity);
	RUN_TEST(test_write_identity);
	return UNITY_END();
}
