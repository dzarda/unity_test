#include "../memory_device.h"
#include "status_codes.h"

status_code_t memory_read(const struct mem_dev *mem, uint32_t addr, char * dest, uint32_t bytes)
{
	(void)mem;
	(void)addr;
	(void)dest;
	(void)bytes;
	return STATUS_OK;
}

status_code_t memory_write(const struct mem_dev *mem, uint32_t addr, char * src, uint32_t bytes)
{
	(void)mem;
        (void)addr;
        (void)src;
        (void)bytes;
	return STATUS_OK;
}
