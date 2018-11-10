#include <math.h>
#include <stdio.h>

/**
 * Beräknar den totala effektutvecklingen med följande formell:
 * P = U^2 / R (Spänning i kvadrat delat på resistansen)
 */
float calc_power_r(float volt, float resistance)
{
  float power = 0;

  if (resistance > 0)
  {
    power = pow(volt, 2.0) / resistance;
  }

  return power;
}

/**
 * Beräknar den totala effektutvecklingen med följande formell:
 * P = U * I (Spänning gånger strömmen)
 */
float calc_power_i(float volt, float current)
{
}