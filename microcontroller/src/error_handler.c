#include <stdint.h>

void _Error_Handler(char *file, int line) {

  // Unused parameters for now
  (void)file;
  (void)line;

  while(1) {

  }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line) {

  // Unused parameters for now
  (void)file;
  (void)line;

}

#endif /* USE_FULL_ASSERT */
