/** \file structs.h
	\brief defines the structs 
	\author Alessio Marrazzo

	Details.
*/

#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * \struct Poly
 * \brief strores the coefficients of a polynomial
 * 
 * coeff[0] + coeff[1]x + coeff[2]x^2 + ...
 */

typedef struct Poly {
    float *coeffs;
    int degree;
} poly_s;

#endif /* STRUCTS_H */
