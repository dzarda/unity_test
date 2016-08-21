#include "status_codes.h"
#include "../flash_memory.h"

#include <stdint.h>
#include <limits.h>


const struct memory_device *used_mem;
uint32_t used_addr;
char *used_ptr;
uint32_t used_bytes;

void mock_setUp(void)
{
	used_mem = (struct memory_device*)0xDEADDEAD;
	used_addr = UINT_MAX;
	used_ptr = (char*)0xDEADDEAD;
	used_bytes = UINT_MAX;
}

void mock_tearDown(void)
{
}

status_code_t memory_read(const struct memory_device *mem, uint32_t addr, char *dest, uint32_t bytes)
{
	used_mem = mem;
	used_addr = addr;
	used_ptr = dest;
	used_bytes = bytes;
	return STATUS_OK;
}

status_code_t memory_write(const struct memory_device *mem, uint32_t addr, char *src, uint32_t bytes)
{
	used_mem = mem;
        used_addr = addr;
        used_ptr = src;
        used_bytes = bytes;
	return STATUS_OK;
}


status_code_t memory_erase(const struct memory_device *mem, uint32_t addr, uint32_t bytes)
{
	used_mem = mem;
        used_addr = addr;
        used_bytes = bytes;
	return STATUS_OK;
}
