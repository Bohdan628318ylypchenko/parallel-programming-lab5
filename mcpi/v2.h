#pragma once

/// <summary>
/// Two dimensional vector definition
/// </summary>
typedef struct
{
	double xcdr;
	double ycdr;
} v2;

/// <summary>
/// Initializes coords of vector with random values in [0, 1].
/// </summary>
/// <param name="vector"> Pointer to vector struct to initialize coords of. </param>
void v2_init(v2 * vector);

/// <summary>
/// Calculates square of vector module.
/// </summary>
/// <param name="vector"> Pointer to vector struct. </param>
/// <returns> square of given vector module. </returns>
double v2_module2(v2 * vector);
