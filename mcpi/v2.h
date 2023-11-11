#pragma once

#include "mtwister.h"

typedef struct
{
	double xcdr;
	double ycdr;
} v2;

void v2_init(v2 * vector, MTRand * mtRand);

double v2_module2(v2 * vector);
