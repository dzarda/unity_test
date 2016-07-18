#include "partition.h"

#define check_in_range(part, addr, ptr, bytes) \
	(addr + bytes <= part->start + part->size)


status_code_t partition_read(const partition_t *part, uint32_t addr, unsigned char *dest, uint32_t bytes)
{
	if (!check_in_range(part, addr, dest, bytes)) {
		return ERR_BAD_ADDRESS;
	}
}

status_code_t partition_write(const partition_t *part, uint32_t addr, unsigned char *src, uint32_t bytes)
{
	if (!check_in_range(part, addr, src, bytes)) {
		return ERR_BAD_ADDRESS;
	}
}
