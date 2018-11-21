#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int main()
{
    float *array = malloc(3 * sizeof(float));
    float res = 0.0f;
    printf("Enter resistance: ");
    scanf("%f", &res);
    if (array != NULL)
    {
        int nbrOfRes = e_resistance(res, array);
        printf("Number of res:  %i\n", nbrOfRes);
        for (int i = 0; i < nbrOfRes; i++)
        {
            printf("resistor %i is %f\n", (i + 1), array[i]);
        }
        free(array);
    }
    return 0;
}