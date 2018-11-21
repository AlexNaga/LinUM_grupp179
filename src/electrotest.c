#include <stdio.h>
#include <stdlib.h>

int getInputFloat(char askFor[], float *userInput, int maxAttempts)
{
    for (int i = 0; i < maxAttempts; i++)
    {
        printf(askFor);
        int result = scanf("%f", userInput);
        if (result > 0)
        {
            return 1;
        }
        if (result == 0)
        {
            while (fgetc(stdin) != '\n')
            { //ta bort alla slasktecken för att tömma bufferten fram till \n
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
        printf(askFor);
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
            { //ta bort alla slasktecken för att tömma bufferten fram till \n
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
        printf(askFor);
        int result = scanf("%d", userInput);
        if (result > 0)
        {
            return 1;
        }
        if (result == 0)
        {
            while (fgetc(stdin) != '\n')
            { //ta bort alla slasktecken för att tömma bufferten fram till \n
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
    int nbrOfcomponents;
    float *componentArray;
    float *e12Resistance;

    if (!getInputFloat("Ange spänningskälla i V: ", &voltage, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        return -1;
    }

    if (!getInputChar("Ange koppling[S | P]: ", &connectionType, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        return -1;
    }

    if (!getInputInt("Antal komponenter: ", &nbrOfcomponents, 3))
    {
        printf("Max antal försök har uppnåtts...avbryter...\n");
        return -1;
    }

    componentArray = malloc(nbrOfcomponents * sizeof(float));
    if (!componentArray)
    {
        printf("Kunde inte allokera minne för komponenter...avbryter...\n");
        return -1;
    }

    for (int i = 0; i < nbrOfcomponents; i++)
    {
        char buffer[50];
        sprintf(buffer, "Komponent %d i ohm: ", i + 1);
        if (!getInputFloat(buffer, &voltage, 3))
        {
            printf("Max antal försök har uppnåtts...avbryter...\n");
            free(componentArray);
            return -1;
        }
    }

    e12Resistance = malloc(3 * sizeof(float));
    if (!e12Resistance)
    {
        printf("Kunde inte allokera minne för E12-resistanser...avbryter...\n");
        free(componentArray);
        return -1;
    }

    free(componentArray);
    free(e12Resistance);

    //TODO add function calls and output values

    return 0;
}