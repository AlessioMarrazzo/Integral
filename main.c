/** \file main.c
    \brief Numerical integration of a polynomial
    \author Alessio Marrazzo

    second version of this software; all the functions in the math.f library
*/

/*! \mainpage
 *
 * \section intro_sec Introduction
 *
 * This is a software in C language for computing numerical integration * by adopting different techniques.

   Available techniques: Riemann sum (Rectangular Rule), Trapezoidal Rule.

 *
 * \section install_sec Usage
 *
 *
 *
 * etc...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathf.h"
#include "io.h"

/*! \brief the main function

    here we define the polynomial, set the integration range and set the number of equally spaced intervals in which the range should be divided
    the points delimiting the intervals are defined and then the integration is finalized

*/
int main()
{
    poly_s pf;
    int rv;
    /* setting all the parameters */
    /* the integration range */
    float xmin;
    float xmax;
    int intervals; /* number of equally spaced intervals */                         

    // opening the configuration file
    char filePath[100] = "./config.txt";
    FILE* fptr = OpenFile(filePath);
    if (fptr == NULL)
    {
        printf("\n Main - ");
        printf("Error! Unable to open file\n");
        exit(1);
    }

    // reading the polynomial coefficients from the config file
    rv = ReadConfigFile(fptr, &pf, &xmin, &xmax, &intervals);
    if (rv != 1)
    {
        printf("\n Main - ");
        printf("Error! Unable to read config file\n");
        exit(1);
    }

    // closing the config file
    rv = CloseFile(fptr);
    if (rv != 1)
    {
        printf("\n Main - ");
        printf("Error! Unable to close file\n");
        exit(1);
    }

    float integ1, integ2;

    int i;
    float in = xmin;
    float gap = (xmax - xmin) / (float)intervals;
    float *fvalues = NULL;

    /* this array will store the (steps+1) values of the polynomial that are delimiting the equally spaced intervals*/
    fvalues = (float *)malloc(sizeof(float) * (intervals + 1));
    if (fvalues == NULL)
    {
        printf("\nERROR: cannot allocate memory\n");
        exit(-1);
    }

    /* to get the value of the polynomial at the different points that are delimiting the intervals */
    for (i = 0; i <= intervals; i++)
    {
        fvalues[i] = Polynomial(pf, in);
        in += gap;
    }

    integ1 = 0.;
    integ2 = 0.;

    /* to compute the integral according to the rectangular rule */
    Rectangular(fvalues, intervals + 1, gap, &integ1, &integ2);
    printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin, xmax, integ1, integ2);

    /* to compute the integral according to the trapezoidal rule */
    integ1 = Trapezoidal(fvalues, intervals + 1, gap);
    printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin, xmax, integ1);

    /* deallocation */
    if (fvalues != NULL)
        free(fvalues);

    return 0;
}