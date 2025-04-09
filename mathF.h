/** \file mathf.h
    \brief Math library function header
    \author Alessio Marrazzo
*/

#ifndef MATHF_H 
#define MATHF_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "structs.h"

float Polynomial(poly_s polyf, float in); 
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2); 
float Trapezoidal(float* values, int size, float stepsize); 

#endif
