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

  #define RED_LED 11
  #define GREEN_LED 12
  #define BLUE_LED 13
  
  gpio_init(RED_LED);
  gpio_init(GREEN_LED);
  gpio_init(BLUE_LED);

  gpio_set_dir(RED_LED, GPIO_OUT);
  gpio_set_dir(GREEN_LED, GPIO_OUT);
  gpio_set_dir(BLUE_LED, GPIO_OUT);

  while (true) {
    printf("On\r\n");
    gpio_put(RED_LED, 1);
    sleep_ms(1000);
    printf("Off\r\n");
    gpio_put(RED_LED, 0);
    sleep_ms(1000);
  }
}
