/**************************************************************
 * main.c
 * rev 1.0 15-Aug-2024 kaeyo
 * Lab4
 * ***********************************************************/

#include "pico/stdlib.h"

#define SIO_BASE 0xd00000000
#define REG_GPIO_OE_SET (SIO_BASE+0x024)
#define LED_PIN 25
#define CONTENT_OF(addr) (*(volatile uint32_t*)addr)

typedef unsigned long uint32_t;

int main(void) {
  // TODO - Initialise components and variables
  while (true) {
    // TODO - Repeated code here
  }
}
