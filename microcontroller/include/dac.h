#ifndef DAC_H
#define DAC_H

#include <stdint.h>

// Initialization of DAC (Used for reference voltages)
void DAC_Init(void);

// Ref_on = 5 - 3.3 * output / 4096 [V] (= 5 - DAC Output)
void DAC_Set_Ref_On(uint16_t output);

// Ref_off = 3.3 * output / 4096 [V] ( = DAC Output)
void DAC_Set_Ref_Off(uint16_t output);

#endif
