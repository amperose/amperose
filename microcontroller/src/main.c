// TODO: ADD HEADER

// Application Entry Point

#include "stm32f7xx_hal.h"
#include "stm32f7xx_system_clock.h"

int main(void) {
  // Reset of all peripherals, Initializes the Flash interface and the Systick.
  HAL_Init();

  // Configure system clocks
  System_Clock_Config();


  while (1) {

  }
}
