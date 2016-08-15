#include "partition.h"
#include <stdlib.h>

#define check_in_range(part, addr, bytes) \
	if (addr + bytes > part->start + part->size) { \
		return ERR_BAD_ADDRESS; \
	}

#define check_args_valid(part, ptr, bytes) \
	if (part == NULL || ptr == NULL || bytes == 0) { \
		return ERR_INVALID_ARG; \
	}

status_code_t partition_read(const partition_t *part, uint32_t addr, unsigned char *dest, uint32_t bytes)
{
	check_args_valid(part, dest, bytes);
	check_in_range(part, addr, bytes);
	return STATUS_OK;
}

status_code_t partition_write(const partition_t *part, uint32_t addr, unsigned char *src, uint32_t bytes)
{
	check_args_valid(part, src, bytes);
	check_in_range(part, addr, bytes);
	return STATUS_OK;
}

status_code_t partition_erase(const partition_t *part, uint32_t addr, uint32_t bytes)
{
	if (part == NULL || bytes == 0)
	{
		return ERR_INVALID_ARG;
	}
	check_in_range(part, addr, bytes);
	return STATUS_OK;
}
