#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"

void main(int argc, char const *argv[])
{
  float voltage = 0.0;
  float resistance = 0.0;
  float current = 0.0;
  float effect = 0.0;
  int componentsCount = 0;

  // TODO: Dynamicly allocate an array

  /**
   * Get user input
   * (Should include some error handling for invalid input)
   */

  /**
   * Calculate the resistance
   */
  // float calc_resistance(int count, char conn, float *array);

  /**
   * Calculate the parallel resistance
   */
  // int e_resistance(float orig_resistance, float *res_array);

  /**
   * Calculate the effect using the resistance
   */
  effect = calc_power_r(voltage, resistance);

  /**
   * Display results to user
   */
  printf("Resistance: %s", resistance);
  printf("Effect: %s", effect);
}