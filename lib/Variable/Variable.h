#include <mbed.h>

#ifndef Variable_H
#define Variable_H

// #define Vbat_observation
// #define Current_observation
// #define encoder_observation
// #define Power_Joule_observation

// Déclaration dees pins
extern AnalogIn analog_alim; // Déclaration de la variable analogique
extern AnalogIn analog_hall_effect;
extern DigitalIn digital_encoder;

// Parametre interruption
#define Te 1
extern double coefficient_milli;

//*********Consommation electrique */

// Tension des batteries
extern double Vbat;
// HASS 50 600
extern double current_ask;
extern double voltage_offset_hall_effect;

extern double puissance_bat;
extern double energie_bat;
extern double conso_energie;

//*********Mesure de la vitesse et de la distance */

// Encoder
#define SIZE_WHEEL_DIAMETER_mm 50
#define TIC_PER_TOUR 1

extern double vitesse;
extern double dist;
extern double dist_prec;
extern long double val_tick;
//*********Interruption */
// Interruption de l'instrumentation
extern volatile bool flag_interruption;

extern volatile bool flag_interrupt_1;
#endif
