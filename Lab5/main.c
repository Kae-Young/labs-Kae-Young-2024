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

#define BLUE_LED                13
#define GREEN_LED               12
#define RED_LED                 11

int main(void) {
  // Initialize serial usb io
  stdio_usb_init();

  // Clear pull up and pull down registers for GPIO15
  CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= ~CTRL_PUE;
  CONTENT_OF(REG_PAD_CONTROL_GPIO15) |= ~CTRL_PDE;
  // CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= ~0xc

  // Configure blue LED
  gpio_init(BLUE_LED);
  gpio_set_dir(BLUE_LED, GPIO_OUT);
  gpio_set_function(BLUE_LED, GPIO_FUNC_PWM);

  // Configure red LED
  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);
  gpio_set_function(RED_LED, GPIO_FUNC_PWM);

  // Configure green LED
  gpio_init(GREEN_LED);
  gpio_set_dir(GREEN_LED, GPIO_OUT);
  gpio_set_function(GREEN_LED, GPIO_FUNC_PWM);

  // Configure floating pin 15
  gpio_init(15);
  gpio_set_dir(15, GPIO_IN);

  while (true) {
    gpio_put(BLUE_LED, gpio_get(15)); // Set blue LED state to GPIO15 state

    int ch = getchar_timeout_us(0);
    if(ch != PICO_ERROR_TIMEOUT)  {
      switch(ch)  {
        case 'u':
          printf("Pin 15 to pull up\r\n");
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= ~CTRL_PUE;
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) |= ~CTRL_PDE;
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= CTRL_PUE;
          break;
        
        case 'd':
          printf("Pin 15 to pull down\r\n");
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= ~CTRL_PUE;
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) |= ~CTRL_PDE;
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= CTRL_PDE;
          break;
        
        case 'o':
          printf("Pin 15 to pull none\r\n");
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) &= ~CTRL_PUE;
          CONTENT_OF(REG_PAD_CONTROL_GPIO15) |= ~CTRL_PDE;
          break;
        
        default:
          break;
      }
    }
  }
}
