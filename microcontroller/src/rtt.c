#include "rtt.h"

size_t RTT_write(const uint8_t *bp, size_t n){
  return SEGGER_RTT_Write(0, (void*)bp, (unsigned)n);
}

// Note that the read wait here is a sleep in order not to hinder threads of lower priority
size_t RTT_read(uint8_t *bp, size_t n){
  while(!SEGGER_RTT_HasKey()){
  }
  return SEGGER_RTT_Read(0, (void*)bp, (unsigned)n);
}

// RTT initialization
void RTT_init(void){
  SEGGER_RTT_Init();
}
