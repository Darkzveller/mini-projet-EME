#include "Variable.h"

// Initialisation des PIN
AnalogIn analog_alim(PB_1);

AnalogIn analog_hall_effect(PA_1);

DigitalIn digital_encoder(PF_1);
 

double coefficient_milli = 1;
//*********Consommation electrique */
// Pont diviseur de tension
double Vbat = 0;
// HASS 50 600
double current_ask;
double voltage_offset_hall_effect = 0;


double puissance_bat = 0;
double energie_bat = 0;
double conso_energie = 0;

//*********Mesure de la vitesse et de la distance */

// Encoder
double vitesse = 0;
double dist = 0;
double dist_prec = 0;
long double val_tick = 0;


//*********Interruption */
//Interruption de l'instrumentation
volatile bool flag_interruption = false;

