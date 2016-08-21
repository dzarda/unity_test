#include "flash_memory.h"
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

status_code_t partition_read(const struct partition *part, uint32_t addr, char *dest, uint32_t bytes)
{
	check_args_valid(part, dest, bytes);
	check_in_range(part, addr, bytes);
	return memory_read(part->mem_dev, part->start, dest, bytes);
}

status_code_t partition_write(const struct partition *part, uint32_t addr, char *src, uint32_t bytes)
{
	check_args_valid(part, src, bytes);
	check_in_range(part, addr, bytes);
	return memory_write(part->mem_dev, part->start, src, bytes);
}

status_code_t partition_erase(const struct partition *part, uint32_t addr, uint32_t bytes)
{
	if (part == NULL || bytes == 0)
	{
		return ERR_INVALID_ARG;
	}
	check_in_range(part, addr, bytes);
	return memory_erase(part->mem_dev, addr, bytes);
}
