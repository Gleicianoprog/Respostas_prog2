#include "esfera_utils.h"
#include<math.h>
float calcula_volume (float R){
    float vol=0;
    vol=(4.0)/(3.0)*PI*pow(R,3);
    return vol;
}
float calcula_area (float R){
    float area=0;
    area=4*PI*pow(R,2);
    return area;
}