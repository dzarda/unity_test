#include "../flash_memory.h"
#include "status_codes.h"

status_code_t flash_read(const struct flash_mem *mem, uint32_t addr, char *dest, uint32_t bytes)
{
	(void)mem;
	(void)addr;
	(void)dest;
	(void)bytes;
	return STATUS_OK;
}

status_code_t flash_write(const struct flash_mem *mem, uint32_t addr, char *src, uint32_t bytes)
{
	(void)mem;
        (void)addr;
        (void)src;
        (void)bytes;
	return STATUS_OK;
}

status_code_t flash_erase(const struct flash_mem *mem, uint32_t addr, uint32_t bytes)
{
	(void)mem;
	(void)addr;
	(void)bytes;
	return STATUS_OK;
}
