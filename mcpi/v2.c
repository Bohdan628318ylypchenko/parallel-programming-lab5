#include "pch.h"

#include "v2.h"

#include <stdlib.h>

/// <summary>
/// Initializes coords of vector with random values in [0, 1].
/// </summary>
/// <param name="vector"> Pointer to vector struct to initialize coords of. </param>
void v2_init(v2 * vector)
{
	vector->xcdr = (long double)(rand()) / (long double)RAND_MAX;
	vector->ycdr = (long double)(rand()) / (long double)RAND_MAX;
}

/// <summary>
/// Calculates square of vector module.
/// </summary>
/// <param name="vector"> Pointer to vector struct. </param>
/// <returns> square of given vector module. </returns>
double v2_module2(v2 * vector)
{
	double xcdr = vector->xcdr;
	double ycdr = vector->ycdr;

	return xcdr * xcdr + ycdr * ycdr;
}