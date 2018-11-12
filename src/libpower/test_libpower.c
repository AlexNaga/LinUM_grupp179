#include "libpower.h"
#include <stdbool.h>
#include <stdio.h>

void main(int argc, char const *argv[])
{
  float volt = 50.0;
  float resistance = 800.0;
  float current = 0.0625; // I = V / R

  const float expected = 3.125;

  float actualA = calc_power_r(volt, resistance);
  float actualB = calc_power_i(volt, current);

  bool resultA = expected == actualA;
  bool resultB = expected == actualA;

  printf("[%s] calc_power_r() gives the expected output: %.3f\n", resultA ? "true" : "false", actualA);
  printf("[%s] calc_power_i() gives the expected output: %.3f\n", resultB ? "true" : "false", actualB);
}