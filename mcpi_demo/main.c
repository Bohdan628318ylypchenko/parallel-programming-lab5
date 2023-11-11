#include "mcpi.h"
#include "mtwister.h"

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#define USAGE "Usage: [s]ingle-thread v_count:int | [m]ulti-thread v_count:int thread_count:int"
#define RUN_COUNT 5

static void run_mcpi(double(*mcpi)(int, MTRand *), int v_count, MTRand * mtRand);

int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		puts(USAGE);
		return EXIT_FAILURE;
	}

	unsigned long v_count;
	unsigned long seed = time(NULL);
	switch (argv[1][0])
	{
		case 's':
			
			v_count = atol(argv[2]);
			if (v_count <= 0)
			{
				printf("Invalid v_count: %s\n", argv[2]);
				return EXIT_FAILURE;
			}

			MTRand mtRand = seedRand(seed);
			
			run_mcpi(mcpi_1t, v_count, &mtRand);

			break;
		case 'm':
			break;
		default:
			puts(USAGE);
			return 1;
	}

	return EXIT_SUCCESS;
}

static void run_mcpi(double(*mcpi)(int, MTRand *), int v_count, MTRand * mtRand)
{
	double s_time, e_time, time, min_time = DBL_MAX;
	double pi;
	for (int i = 0; i < RUN_COUNT; i++)
	{
		s_time = omp_get_wtime();
		pi = mcpi(v_count, mtRand);
		e_time = omp_get_wtime();

		time = e_time - s_time;
		printf("Run %d | pi = %lf; time = %lf\n", i, pi, time);

		if (min_time > time)
			min_time = time;
	}
	printf("Min time = %lf\n", min_time);
}