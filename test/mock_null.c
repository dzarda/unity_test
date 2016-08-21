//#include "../flash_memory.h"
#include "status_codes.h"
#include "mock_null.h"
#include <stdint.h>


status_code_t memory_read(const struct memory_device *mem, uint32_t addr, char *dest, uint32_t bytes)
{
	(void)mem;
	(void)addr;
	(void)dest;
	(void)bytes;
	return STATUS_OK;
}

status_code_t memory_write(const struct memory_device *mem, uint32_t addr, char *src, uint32_t bytes)
{
	(void)mem;
        (void)addr;
        (void)src;
        (void)bytes;
	return STATUS_OK;
}

status_code_t memory_erase(const struct memory_device *mem, uint32_t addr, uint32_t bytes)
{
	(void)mem;
	(void)addr;
	(void)bytes;
	return STATUS_OK;
}
