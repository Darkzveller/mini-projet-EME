#include "Variable.h"
#include "Fonction.h"

void tension_batterie()
{
    Vbat = analog_alim.read();
    Vbat = Vbat * 3.3 / 1.0;
    Vbat = Vbat * 57.6 / 3.34;
    Vbat = Vbat; // Pour l'avoir en mV
#ifdef Vbat_observation
    printf(" Vbat %.5d V ", (int)Vbat);
#endif
}

void capteur_effet_hall()
{
    double Voutput = analog_hall_effect.read() * 3.3 / 1.0;
    Voutput = Voutput;
    double coeff = 0.625;
    double IPN = 50;
    double Vref = 2.5;

    current_ask = (Voutput * IPN) / (coeff * Vref);
#ifdef Current_observation
    printf("Voutput = %.5d mV ", (int)Voutput * 10);
    printf("Voutput = %.5d mV ", (int)Voutput);
    printf("current ask %.5d mA ", (int)current_ask);
#endif
}

void encoder()
{

    val_tick = digital_encoder.read() + val_tick;
    dist = (2.0 * M_PI * (SIZE_WHEEL_DIAMETER_mm / 2.0) / TIC_PER_TOUR) * val_tick;

    vitesse = (dist - dist_prec) / Te;
    dist_prec = dist;
#ifdef encoder_observation

    printf("val tick %d ", (int)val_tick);
printf("vitesse %d ", (int)vitesse);printf("dist %d ", (int)dist);

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
    printf("puissance_bat %d mW ", (int)(puissance_bat));
    printf("energie_bat %d mWh ", (int)energie_bat);
    printf("conso_energie %d  ", (int)conso_energie);

#endif
}

