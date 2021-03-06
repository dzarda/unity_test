#include "unity.h"
#include "mock_null.h"
#include "../partition.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_failsWhenAddressLastPlusOne(void)
{
	DECLARE_NULL_MEMORY_DEVICE(dev);
	DECLARE_PARTITION(part, &dev, 1000, 1000);
	TEST_ASSERT_EQUAL_INT(ERR_BAD_ADDRESS, partition_read(&part, 2000, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(ERR_BAD_ADDRESS, partition_write(&part, 2000, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(ERR_BAD_ADDRESS, partition_erase(&part, 2000, 1));
}

void test_okWhenAddressLast(void)
{
	DECLARE_NULL_MEMORY_DEVICE(dev);
	DECLARE_PARTITION(part, &dev, 1000, 1000);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_read(&part, 1999, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_write(&part, 1999, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_erase(&part, 1999, 1));
}

void test_okWhenAddressFirst(void)
{
	DECLARE_NULL_MEMORY_DEVICE(dev);
	DECLARE_PARTITION(part, &dev, 1000, 1000);
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_read(&part, 0, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_write(&part, 0, (char*)0xDEAD, 1));
	TEST_ASSERT_EQUAL_INT(STATUS_OK, partition_erase(&part, 0, 1));
}

void test_failsWhenDestNull(void)
{
	DECLARE_NULL_MEMORY_DEVICE(dev);
	DECLARE_PARTITION(part, &dev, 1000, 1000);
	TEST_ASSERT_EQUAL_INT(ERR_INVALID_ARG, partition_read(&part, 0, NULL, 1));
	TEST_ASSERT_EQUAL_INT(ERR_INVALID_ARG, partition_write(&part, 0, NULL, 1));
}

void test_failsWhenBytesZero(void)
{
	DECLARE_NULL_MEMORY_DEVICE(dev);
	DECLARE_PARTITION(part, &dev, 1000, 1000);
	TEST_ASSERT_EQUAL_INT(ERR_INVALID_ARG, partition_read(&part, 0, (char*)0xDEAD, 0));
	TEST_ASSERT_EQUAL_INT(ERR_INVALID_ARG, partition_write(&part, 0, (char*)0xDEAD, 0));
	TEST_ASSERT_EQUAL_INT(ERR_INVALID_ARG, partition_erase(&part, 0, 0));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_failsWhenAddressLastPlusOne);
	RUN_TEST(test_okWhenAddressLast);
	RUN_TEST(test_okWhenAddressFirst);
	RUN_TEST(test_failsWhenDestNull);
	RUN_TEST(test_failsWhenBytesZero);
	return UNITY_END();
}
