#include "pch.h"

#include "mcpi.h"
#include "mtwister.h"
#include "v2.h"

static int gen_count_ucircle(int v_count, MTRand * mtRand);

double mcpi_1t(int v_count, MTRand * mtRand)
{
	int in_count = gen_count_ucircle(v_count, mtRand);

	return (double)in_count / v_count * 4.0;
}

static int gen_count_ucircle(int v_count, MTRand * mtRand)
{
	int in_count = 0;

	v2 current;
	for (int i = 0; i < v_count; i++)
	{
		v2_init(&current, mtRand);
		if (v2_module2(&current) < 1.0) in_count++;
	}

	return in_count;
}
