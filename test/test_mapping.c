#include "unity.h"
#include "../flash_memory.h"
#include "../partition.h"
#include "mock_mapping.h"

void setUp(void)
{
	mock_setUp();
}

void tearDown(void)
{
	mock_tearDown();
}

void test_identity(void)
{
	DECLARE_FLASH_MEMORY_DEVICE(flash, 1, 1);
	DECLARE_PARTITION(part, &flash, 0, 1000);
	status_code_t ret = partition_read(&part, 0, (char*)0xDEAD, 1);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, ret);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_identity);
	return UNITY_END();
}
