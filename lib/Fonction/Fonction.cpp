#include "Variable.h"
#include "Fonction.h"
void tension_batterie()
{
    Vbat = analog_alim.read();
    Vbat = Vbat * 3.3 / 1.0;
    Vbat = Vbat * 57.6 / 3.34;
    Vbat = Vbat; // Pour l'avoir en mV
#ifdef Vbat_observation
    printf(" Vbat ");
    adapte_print_double(Vbat);

#endif
}

void capteur_effet_hall()
{
    double Voutput = analog_hall_effect.read() * 3.3 / 1.0;
    Voutput = Voutput;
    double coeff = 0.625;
    double IPN = 50;
    double Vref = 2.5;

    current_ask = ((Voutput * IPN) / (coeff * Vref)) / 1000;
#ifdef Current_observation
    printf(" Voutput =  ");
    adapte_print_double(Voutput);
    printf(" current ask ");
    adapte_print_double(current_ask);

#endif
}

void encoder()
{

    val_tick = digital_encoder.read() + val_tick;
    dist = (2.0 * M_PI * (SIZE_WHEEL_DIAMETER_mm / 2.0) / TIC_PER_TOUR) * val_tick;

    vitesse = (dist - dist_prec) / Te;
    dist_prec = dist;
#ifdef encoder_observation

    printf(" val tick ");
    adapte_print_double(val_tick);

    printf(" vitesse ");
    adapte_print_double(vitesse);

    printf(" dist ");
    adapte_print_double(dist);

#endif
}

void grandeur_calculer()
{
    tension_batterie();
    capteur_effet_hall();
    encoder();

    puissance_bat = current_ask * Vbat;
    energie_bat += (puissance_bat * Te) / 3600;
    conso_energie = energie_bat / dist;
#ifdef Power_Joule_observation
    // printf(" puissance_bat %d  mW", (int)(puissance_bat * 1000));
    // printf(" energie_bat %d ", (int)(energie_bat*1000));
    // printf(" conso_energie %d  ", (int)(conso_energie));
    printf(" puissance_bat ");
    adapte_print_double(puissance_bat);
    printf(" energie_bat ");
    adapte_print_double(energie_bat);
    printf(" conso_energie ");
    adapte_print_double(conso_energie);

#endif
}

void delay(float time)
{
    ThisThread::sleep_for(time);
} 
/*
 void adapte_print_double(double nombre)
 {
     int32_t partie_gauche = (int32_t)nombre;

     int32_t partie_droite = (int32_t)round((nombre - partie_gauche) * 10000.0);

     printf("%d.%d", partie_gauche, partie_droite);
 }
 */
void adapte_print_double(double nombre)
{
    float coeff = 1000.0;
    int32_t partie_gauche = (int32_t)nombre;
    int16_t partie_droite = (int16_t)((nombre - partie_gauche) * coeff);

    printf("%d.", partie_gauche);

    if (partie_droite < (coeff / 10.0))
    {
        printf("0");
    }
    printf("%d", partie_droite);
}
