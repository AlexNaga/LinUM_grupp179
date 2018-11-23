#include <stdio.h>
#include <stdlib.h>
#include "libcomponent/libcomponent.h"
#include "libpower/libpower.h"
#include "libresistance/libresistance.h"

int getInputFloat(char askFor[], float *userInput, int maxAttempts)
{
    for (int i = 0; i < maxAttempts; i++)
    {
        printf("%s", askFor);
        int result = scanf("%f", userInput);
        if (result > 0)
        {
            return 1;
        }
        if (result == 0)
        {
            while (fgetc(stdin) != '\n')
            { // Ta bort alla slasktecken för att tömma bufferten fram till \n
                ;
            }
            printf("...ogiltig indata...försök igen...\n");
        }
        if (result == EOF)
        {
            printf("...kunde inte läsa från stdin...försök igen...\n");
        }
    }
    return 0;
}

int getInputChar(char askFor[], char *userInput, int maxAttempts)
{
    for (int i = 0; i < maxAttempts; i++)
    {
        printf("%s", askFor);
        int result = scanf(" %c", userInput);
        if (result > 0)
        {
            if ((*userInput) == 'P' || (*userInput) == 'S')
            {
                return 1;
            }
            printf("...ogiltig indata...giltiga värden är P eller S...försök igen...\n");
        }
        if (result == 0)
        {
            while (fgetc(stdin) != '\n')
            { // Ta bort alla slasktecken för att tömma bufferten fram till \n
                ;
            }
            printf("...ogiltig indata...försök igen...\n");
        }
        if (result == EOF)
        {
            printf("...kunde inte läsa från stdin...försök igen...\n");
        }
    }
    return 0;
}

int getInputInt(char askFor[], int *userInput, int maxAttempts)
{
    for (int i = 0; i < maxAttempts; i++)
    {
        printf("%s", askFor);
        int result = scanf("%d", userInput);
        if (result > 0)
        {
            return 1;
        }
        if (result == 0)
        {
            while (fgetc(stdin) != '\n')
            { // Ta bort alla slasktecken för att tömma bufferten fram till \n
                ;
            }
            printf("...ogiltig indata...försök igen...\n");
        }
        if (result == EOF)
        {
            printf("...kunde inte läsa från stdin...försök igen...\n");
        }
    }
    return 0;
}

int main()
{
    float voltage;
    char connectionType;
    int componentCount;
    float *componentArray;
    float *e12Resistance;

    if (!getInputFloat("Ange spänningskälla i V: ", &voltage, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        goto error;
    }

    if (!getInputChar("Ange koppling[S | P]: ", &connectionType, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        goto error;
    }

    if (!getInputInt("Antal komponenter: ", &componentCount, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        goto error;
    }

    componentArray = malloc(componentCount * sizeof(float));
    if (!componentArray)
    {
        printf("Kunde inte allokera minne för komponenter...avbryter...\n");
        goto error;
    }

    for (int i = 0; i < componentCount; i++)
    {
        char buffer[50];
        sprintf(buffer, "Komponent %d i ohm: ", i + 1);
        if (!getInputFloat(buffer, &voltage, 3))
        {
            printf("Max antal försök har uppnåtts...avbryter...\n");
            free(componentArray);
            goto error;
        }
        componentArray[i]=voltage;
    }

    e12Resistance = malloc(3 * sizeof(float));
    if (!e12Resistance)
    {
        printf("Kunde inte allokera minne för E12-resistanser...avbryter...\n");
        free(componentArray);
        goto error;
    }

    float resistance = calc_resistance(componentCount, connectionType, componentArray);
    printf("Ersättningsresistans: %.1f ohm\n", resistance);
    free(componentArray);

    float power = calc_power_r(voltage, resistance);
    printf("Effekt: %.2f W\n", power);

    int resistorCount = e_resistance(resistance, e12Resistance);
    printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

    for (size_t i = 0; i < resistorCount; i++)
    {
        printf("%.0f\n", e12Resistance[i]);
    }

    free(e12Resistance);
    exit(EXIT_SUCCESS);

error:
    exit(EXIT_FAILURE);
}
