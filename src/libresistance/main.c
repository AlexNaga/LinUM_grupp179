#include <stdio.h>
#include <stdlib.h>

/*
	Test program for resistance, sends a float array
	with different resistances, a char with either P
	or S and an integer with the amount of values in the
	array to the function that calculates the resistance.
*/
float calc_resistance(int count, char conn, float *array);
int main(int argc, char *argv[])
{
	float array[]={100, 350, 73,2};
	
	float resistance;
	resistance = calc_resistance(3, 'P', array);
	printf("Parallel resistance is:%.2f\n", resistance);

	resistance = calc_resistance(3, 'S', array);
	printf("Serial resistance is:%.2f\n", resistance);
	return 0;
}
