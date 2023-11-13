#include "pch.h"

#include "mcpi.h"
#include "v2.h"

#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define SEED_SHIFT 4450
#define PI(in_count, v_count) 4.0 * (double)in_count / v_count;

static int gen_count_ucircle_1t(int v_count);
static int gen_count_ucircle_mt(int v_count);

/// <summary>
/// Initializes seed for parent thread (e.g. thread - mcpi function caller).
/// </summary>
/// <param name="seed"> Sequence seed. </param>
void mcpi_init(int seed)
{
	srand(seed);
}

/// <summary>
/// Single thread implementation of
/// Monte Carlo PI calculation method.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> PI value. </returns>
double mcpi_1t(int v_count)
{
	int in_count = gen_count_ucircle_1t(v_count);

	return PI(in_count, v_count);
}

/// <summary>
/// Multi thread implementation of
/// Monte Carlo PI calculation method.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> PI value. </returns>
double mcpi_mt(int v_count)
{
	int in_count = gen_count_ucircle_mt(v_count);

	return PI(in_count, v_count);
}

/// <summary>
/// Single thread vector generator.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> Count of generated vectors in quarter ucircle. </returns>
static int gen_count_ucircle_1t(int v_count)
{
	int in_count = 0;

	v2 current;
	for (int i = 0; i < v_count; i++)
	{
		v2_init(&current);
		if (v2_module2(&current) < 1.0) in_count++;
	}

	return in_count;
}

/// <summary>
/// Multi thread vector generator.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> Count of generated vectors in quarter ucircle. </returns>
static int gen_count_ucircle_mt(int v_count)
{
	int base_seed = rand();
	int in_count = 0;

	#pragma omp parallel reduction(+:in_count)
	{
		srand(base_seed + omp_get_thread_num() * SEED_SHIFT);

		int i;
		#pragma omp for schedule(static)
		for (i = 0; i < v_count; i++)
		{
			v2 current;
			v2_init(&current);
			if (v2_module2(&current) < 1.0) in_count++;
		}
	}

	return in_count;
}
