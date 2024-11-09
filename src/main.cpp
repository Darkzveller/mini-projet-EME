

#include "mbed.h"
#include "Variable.h"
#include "Fonction.h"

DigitalOut led1(LED1); // LED pour l'interruption 1

// Déclaration des objets Ticker pour générer des interruptions périodiques
Ticker t1;
Ticker t2;
// Fonction d'interruption pour le premier timer (Ticker)
void interrupt_1()
{
    led1 = !led1; // Toggle de la LED1
}

// Fonction d'interruption pour le second timer (Ticker)
void instrumentation()
{
    flag_interruption = true;
}

int main()
{
    printf("Mini-projet-Initialiser \n");
    // Initialisation des timers
    NVIC_SetPriority(TIM2_IRQn, 2);

    NVIC_SetPriority(TIM3_IRQn, 5);

    t1.attach(&interrupt_1, 1);

    t2.attach(&instrumentation, Te);
    printf("Initialisation des Timer effectuer\n");

    // Boucle principale
    while (true)
    {

        if (flag_interruption)
        {

            grandeur_calculer();
            printf("finish");
            printf("\n");
            flag_interruption = false;
        }
        // ThisThread::sleep_for(1000ms);
    }
}
