/**************************************************************
 * main.c
 * rev 1.0 08-Aug-2024 Kae Young
 * Lab3
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>


int main(void) {
  stdio_usb_init();

  #define RED_LED 15
  #define GREEN_LED 16
  #define BLUE_LED 17
  
  gpio_init(RED_LED);
  gpio_init(GREEN_LED);
  gpio_init(BLUE_LED);

  gpio_set_dir(RED_LED, 1);
  gpio_set_dir(GREEN_LED, 1);
  gpio_set_dir(BLUE_LED, 1);

  while (true) {
    printf("On\r\n");
    gpio_put(RED_LED, 1);
    sleep_ms(500);
    printf("Off\r\n");
    gpio_put(RED_LED, 0);
    sleep_ms(500);
  }
}
