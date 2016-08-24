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

#define ASSERT_RW(RET, MEM, ADDR, PTR, BYTES) \
	TEST_ASSERT_EQUAL_INT(STATUS_OK, RET); \
	TEST_ASSERT_EQUAL_PTR(&MEM, used_mem); \
	TEST_ASSERT_EQUAL_UINT32(ADDR, used_addr); \
	TEST_ASSERT_EQUAL_PTR((char*)PTR, used_ptr); \
	TEST_ASSERT_EQUAL_UINT32(BYTES, used_bytes)


#define ASSERT_ERASE(RET, MEM, ADDR, BYTES) \
	TEST_ASSERT_EQUAL_INT(STATUS_OK, RET); \
	TEST_ASSERT_EQUAL_PTR(&MEM, used_mem); \
	TEST_ASSERT_EQUAL_UINT32(ADDR, used_addr); \
	TEST_ASSERT_EQUAL_UINT32(BYTES, used_bytes)


void test_identity(void)
{
	DECLARE_NULL_MEMORY_DEVICE(mem);
	DECLARE_PARTITION(part, &mem, 0, 1000);
	ASSERT_RW(partition_read(&part, 123, (char*)0xDEAD, 100), mem, 123, 0xDEAD, 100);
	ASSERT_RW(partition_write(&part, 123, (char*)0xDEAD, 100), mem, 123, 0xDEAD, 100);
	ASSERT_ERASE(partition_erase(&part, 123, 100), mem, 123, 100);
}

void test_offset(void)
{
	DECLARE_NULL_MEMORY_DEVICE(mem);
	DECLARE_PARTITION(part, &mem, 1000, 1000);
	ASSERT_RW(partition_read(&part, 123, (char*)0xDEAD, 100), mem, 1123, 0xDEAD, 100);
	ASSERT_RW(partition_write(&part, 123, (char*)0xDEAD, 100), mem, 1123, 0xDEAD, 100);
	ASSERT_ERASE(partition_erase(&part, 0, 100), mem, 1000, 100);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_identity);
	RUN_TEST(test_offset);
	return UNITY_END();
}
