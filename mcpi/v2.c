#include "pch.h"

#include "v2.h"
#include "mtwister.h"

#include <stdlib.h>

void v2_init(v2 * vector, MTRand * mtRand)
{
	vector->xcdr = genRand(mtRand);
	vector->ycdr = genRand(mtRand);
}

double v2_module2(v2 * vector)
{
	double xcdr = vector->xcdr;
	double ycdr = vector->ycdr;

	return xcdr * xcdr + ycdr * ycdr;
}