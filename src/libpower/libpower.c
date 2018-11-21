#include <math.h>
#include <stdio.h>

/**
 * Beräknar den totala effektutvecklingen med följande formell:
 * P = U^2 / R (Spänning i kvadrat delat på resistansen)
 */
float calc_power_r(float voltage, float resistance)
{
    float power = 0.0;

    if (resistance > 0)
    {
        power = pow(voltage, 2.0) / resistance;
    }

    return power;
}

/**
 * Beräknar den totala effektutvecklingen med följande formell:
 * P = U * I (Spänning gånger strömmen)
 */
float calc_power_i(float voltage, float current)
{
    return voltage * current;
}