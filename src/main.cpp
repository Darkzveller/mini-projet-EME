
#include "mbed.h"
#include "Variable.h"
#include "Fonction.h"

int main()
{
    printf("Mini-projet-Initialiser \n");

    // huart2.Init.BaudRate = 115200; // Définir le baud rate à 11520
    while (1)
    {
        grandeur_calculer();
        // int x = 10;
        // float y = 25.0;
        // double z = 30.2;
        // printf("int x = %d ", x);
        // printf("float y = %f ", y); // Corrigé pour float
        // printf("double z = %f", z); // Corrigé pour double

        printf("\n");
        // ThisThread::sleep_for(500ms); // Pause pour éviter la saturation
    }
}
