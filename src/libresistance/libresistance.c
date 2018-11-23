#include <ctype.h>
#include "libresistance.h"

/*
	Calculates the parallel or serial resistance.
	
	@param count - the amount of resistors in the array.
	@param conn - a single char that is S for serial or P for
	parallel.
	@param array - the float array with resistors
	
	@returns - the final resistance.
*/
float calc_resistance(int count, char conn, float *array)
{
    float resistance = 0;
    if (count < 1)
    {
        return -1;
    }

    switch (tolower(conn))
    {

    case 's':
        for (int i = 0; i < count; i++)
        {
            resistance += array[i];
        }
        break;
    
    case 'p':
        for (int i = 0; i < count; i++)
        {
            resistance += 1 / array[i];
        }
        resistance = 1 / resistance;
        break;

    default:
        printf("connection type must be either S or P\n");
        return -1;
    }
    return resistance;
}