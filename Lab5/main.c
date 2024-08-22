/**************************************************************
 * main.c
 * rev 1.0 22-Aug-2024 kaeyo
 * Lab5
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include "hardware/pwm.h"
#include <stdio.h>

#define CONTENT_OF(addr)        (*(volatile uint32_t*)addr)
#define PAD_CONTROL_BASE        0x4001c000
#define REG_PAD_CONTROL_GPIO15  (PAD_CONTROL_BASE+0x40)
#define CTRL_PDE                0x4
#define CTRL_PUE                0x8

int main(void) {
  // TODO - Initialise components and variables
  while (true) {
    // TODO - Repeated code here
  }
}
