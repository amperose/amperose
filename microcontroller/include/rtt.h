#ifndef RTT_H
#define RTT_H

#include <stdint.h>
#include <stdlib.h>

#include "amperose_conf.h"
#include "SEGGER_RTT.h"

// initialization function
void RTT_init(void);

// Writes on RTT stream
size_t RTT_write(const uint8_t *bp, size_t n);

// Reads from RTT stream
size_t RTT_read(uint8_t *bp, size_t n);

#endif
