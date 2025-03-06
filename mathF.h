/** \file mathF.h
	\brief Prototype of function Numerical integration of a polynomial
	\author Alessio Marrazzo
*/

#ifndef  MATHF_H
#define MATHF_H

#include <stdio.h>
#include <stdlib.h>

float Polynomial(float* coeff, int size, float in);
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2);
float Trapezoidal(float* values, int size, float stepsize);

#endif
