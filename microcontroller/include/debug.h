#ifndef DEBUG_H
#define DEBUG_H

#include "SEGGER_RTT.h"

#define AMPEROSE_DEBUG(...) do { if(DEBUG) SEGGER_RTT_printf(0, __VA_ARGS__); } while(0)

#endif /* DEBUG_H */
