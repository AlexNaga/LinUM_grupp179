
#include "libcomponent.h"
#include <math.h>


static float e12[12] = {1.0f, 1.2f, 1.5f, 1.8f, 2.2f, 2.7f, 3.3f, 3.9f, 4.7f, 5.6f, 6.8f, 8.2f};

int findIndex(float resistance) {
    int index = 0;
    for (int i = 1; i < 12; i++) {
        if (e12[i] > resistance) {
            return index;
        }
        index = i;
    }
    return index;
}

int e_resistance(float orig_resistance, float *res_array) {
    if (orig_resistance < 1){
        return 0;
    }
    for (int i = 0; i < 3; i++){
        res_array[i] = 0.0f;    //initialize to zero
    }
    float accumulated = 0;
    float current = orig_resistance;
    float currentError = 1E12;  //large error to start with
    for (int i = 0; i < 3; i++) {
        float multiplier = floorf(log10f(current));
        float baseValue = current / powf(10, multiplier);
        float temp = e12[findIndex(baseValue)] * pow(10, multiplier);
        float error = fabsf(accumulated + temp - orig_resistance);
        if (error >= currentError || multiplier < 0) {
            return i;   //if error is getting bigger or multiplier is less than zero then abort
        }
        currentError = error;
        accumulated += temp;
        current -= temp;
        res_array[i] =  temp;
    }
    return 3;
}

