// TODO: ADD HEADER

// Application Entry Point

#include "board.h"
#include "rtt.h"
#include "debug.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_system_clock.h"

int main(void) {
  // Reset of all peripherals, Initializes the Flash interface and the Systick.
  HAL_Init();

  // Configure system clocks
  System_Clock_Config();

  // Initialize Board (Set all pins to floating input except SWD)
  Board_Init();

  RTT_init();
  int i = 0;

  while (1) {
    i += 1;
    AMPEROSE_DEBUG("Hello World %d", i);
  }
}
