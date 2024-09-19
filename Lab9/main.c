/**************************************************************
 * main.c
 * rev 1.0 19-Sep-2024 kaeyo
 * Lab9
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>

#define BLUE_LED    13
#define RED_LED     12
#define GREEN_LED   11
#define SEND_BTN    2

#define t_interval  10

int main(void) {
  //init RGB LED's
  gpio_init(BLUE_LED);
  gpio_set_dir(BLUE_LED, GPIO_OUT);
  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);
  gpio_init(GREEN_LED);
  gpio_set_dir(GREEN_LED, GPIO_OUT);

  //init send button
  gpio_init(SEND_BTN);
  gpio_set_dir(SEND_BTN, GPIO_IN);

  int n = 10;
  bool signal[n];
  signal = [1,0,1,0,1,1,0,0,1,0];

  while (true) {
    if (gpio_get(SEND_BTN)) {
      send_signal(signal, n);
    }
  }
}

void send_signal(bool *signal, int n)  {
  for (int i = 0; i < n; i++)
  {
    if (signal[i])
    {
      signal_1();
    }
    else
    {
      signal_0();
    }
    
  }
  
}

//light on
void signal_1(void)  {
  gpio_put(BLUE_LED, true);
  gpio_put(GREEN_LED, true);
  gpio_put(RED_LED, true);

  sleep_ms(t_interval);
}

//light off
void signal_0(void) {
  gpio_put(BLUE_LED, false);
  gpio_put(GREEN_LED, false);
  gpio_put(RED_LED, false);

  sleep_ms(t_interval);
}
