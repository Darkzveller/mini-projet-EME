

#include "mbed.h"
#include "Variable.h"
#include "Fonction.h"

DigitalOut led1(LED1); // LED pour l'interruption 1

// Déclaration des objets Ticker pour générer des interruptions périodiques comme des taches
Ticker t1;
Ticker t2;
void controle()
{
    led1 = !led1; 
    flag_controle = true;
}

void instrumentation()
{
    flag_interruption = true;
}
int main()
{
    printf("Mini-projet-Initialiser \n");

    t1.attach(&controle, 1.0);

    t2.attach(&instrumentation, Te);
    printf("Initialisation des tache effectuer\n");

    while (true)
    {

        if (flag_interruption)
        {

            grandeur_calculer();
            // printf("\n");

            flag_interruption = false;
        }
        if (flag_controle)
        {

            // printf("LED");
            flag_controle = false;
        }
    }
}
/*
#include "mbed.h"
#include "stm32f3xx.h" // Pour utiliser les registres spécifiques au STM32F303

DigitalOut led1(LED1);
volatile bool flag_interruption = false;

// Fonction d'interruption pour TIM2
void TIM2_IRQHandler() {
    if (TIM2->SR & TIM_SR_UIF) { // Vérifier si une interruption de mise à jour a eu lieu
        TIM2->SR &= ~TIM_SR_UIF; // Réinitialiser le flag d'interruption
        led1 = !led1; // Toggle de la LED1
    }
}

// Fonction d'interruption pour TIM3
void TIM3_IRQHandler() {
    if (TIM3->SR & TIM_SR_UIF) { // Vérifier si une interruption de mise à jour a eu lieu
        TIM3->SR &= ~TIM_SR_UIF; // Réinitialiser le flag d'interruption
        flag_interruption = true; // Mettre à jour le flag
    }
}

void init_TIM2(uint32_t priority) {
    // Activer l'horloge pour TIM2
    __HAL_RCC_TIM2_CLK_ENABLE();

    TIM2->PSC = 8000 - 1; // Prescaler pour diviser la fréquence (80 MHz / 8000 = 10 kHz)
    TIM2->ARR = 10000 - 1; // Compte jusqu'à 10 000 -> 1 Hz (1 seconde)
    TIM2->DIER |= TIM_DIER_UIE; // Activer l'interruption de mise à jour
    TIM2->CR1 |= TIM_CR1_CEN; // Démarrer le timer

    // Configurer la priorité et activer l'interruption
    NVIC_SetPriority(TIM2_IRQn, priority);
    NVIC_EnableIRQ(TIM2_IRQn);
}

void init_TIM3(uint32_t priority) {
    // Activer l'horloge pour TIM3
    __HAL_RCC_TIM3_CLK_ENABLE();

    TIM3->PSC = 8000 - 1; // Prescaler pour diviser la fréquence (80 MHz / 8000 = 10 kHz)
    TIM3->ARR = 5000 - 1; // Compte jusqu'à 5000 -> 2 Hz (0.5 seconde)
    TIM3->DIER |= TIM_DIER_UIE; // Activer l'interruption de mise à jour
    TIM3->CR1 |= TIM_CR1_CEN; // Démarrer le timer

    // Configurer la priorité et activer l'interruption
    NVIC_SetPriority(TIM3_IRQn, priority);
    NVIC_EnableIRQ(TIM3_IRQn);
}

int main() {
    printf("Initialisation des Timers matériels\n");

    // Initialiser TIM2 et TIM3 avec des priorités différentes
    init_TIM2(2); // Priorité 2 pour TIM2
    init_TIM3(5); // Priorité 5 pour TIM3

    // Boucle principale
    while (true) {
        if (flag_interruption) {
            printf("Interruption TIM3 déclenchée\n");
            flag_interruption = false;
        }
        // Faire une pause pour éviter de saturer le terminal
        ThisThread::sleep_for(500ms);
    }
}
*/