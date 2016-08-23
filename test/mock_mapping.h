#pragma once
#include "status_codes.h"
#include "memory_device.h"
#include <stdint.h>

extern const struct memory_device *used_mem;
extern uint32_t used_addr;
extern char *used_ptr;
extern uint32_t used_bytes;

void mock_setUp(void);
void mock_tearDown(void);

status_code_t memory_read(const struct memory_device *mem, uint32_t addr, char *dest, uint32_t bytes);
status_code_t memory_write(const struct memory_device *mem, uint32_t addr, char *src, uint32_t bytes);
status_code_t memory_erase(const struct memory_device *mem, uint32_t addr, uint32_t bytes);

