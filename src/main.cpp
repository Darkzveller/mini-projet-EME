

#include "mbed.h"
#include "Variable.h"
#include "Fonction.h"
DigitalOut led1(LED1); // LED pour l'interruption 1

volatile bool prout = false;
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
    NVIC_SetPriority(TIM2_IRQn, 2);

    NVIC_SetPriority(TIM3_IRQn, 5);

    t1.attach(&interrupt_1, 1); // Appelle `interrupt_1` toutes les 500 ms

    // Timer 2 génère une interruption toutes les 1 seconde
    t2.attach(&instrumentation, Te); // Appelle `instrumentation` toutes les 1 seconde
    printf("Mini-projet-Initialiser \n");

    // Boucle principale
    while (true)
    {

        if (flag_interruption == 1)
        {

            grandeur_calculer();
            printf("finish");
            printf("\n");
            flag_interruption = false;
        }
        // La boucle principale peut rester vide ou effectuer d'autres tâches
        // Les interruptions se déclencheront indépendamment en fonction de la priorité
        // ThisThread::sleep_for(1000ms); // Par exemple, attendre 1 seconde
    }
}
