#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "libpower.h"

void main(int argc, char const *argv[])
{
    const float voltage = 50.0;
    const float resistance = 1398.0;
    const float current = 0.0357; // I = V / R

    const float expected = 1.79f;
    float actualA = calc_power_r(voltage, resistance);
    float actualB = calc_power_i(voltage, current);

    // Round values to approximate nearest value
    actualA = roundf(actualA * 100) / 100;
    actualB = roundf(actualB * 100) / 100;

    const bool resultA = expected == actualA;
    const bool resultB = expected == actualB;

    printf("[%s] calc_power_r() returns the expected value (%.3f). Actual output: %.3f\n", resultA ? "true" : "false", expected, actualA);
    printf("[%s] calc_power_i() returns the expected value (%.3f). Actual output: %.3f\n", resultB ? "true" : "false", expected, actualB);
}
