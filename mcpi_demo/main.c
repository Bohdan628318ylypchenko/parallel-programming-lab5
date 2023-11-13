#include "mcpi.h"

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

#define USAGE "Usage: [s]ingle-thread v_count:int | [m]ulti-thread v_count:int thread_count:int"
#define RUN_COUNT 5

int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		puts(USAGE);
		return EXIT_FAILURE;
	}

	mcpi_init(time(NULL));

	unsigned long v_count;
	double s_time, e_time, c_time, min_time = DBL_MAX;
	double pi;
	switch (argv[1][0])
	{
		case 's':
			
			v_count = atol(argv[2]);
			if (v_count <= 0)
			{
				printf("Invalid v_count: %s\n", argv[2]);
				return EXIT_FAILURE;
			}

			for (int i = 0; i < RUN_COUNT; i++)
			{
				s_time = omp_get_wtime();
				pi = mcpi_1t(v_count);
				e_time = omp_get_wtime();

				c_time = e_time - s_time;
				printf("Run %d | pi = %.15lf; time = %lf\n", i, pi, c_time);

				if (min_time > c_time)
					min_time = c_time;
			}
			printf("Min time = %lf\n", min_time);

			break;

		case 'm':

			v_count = atol(argv[2]);
			if (v_count <= 0)
			{
				printf("Invalid v_count: %s\n", argv[2]);
				return EXIT_FAILURE;
			}

			int thread_count = atoi(argv[3]);
			if (thread_count <= 0)
			{
				printf("Invalid thread_count: %s\n", argv[3]);
				return EXIT_FAILURE;
			}

			omp_set_num_threads(thread_count);
			for (int i = 0; i < RUN_COUNT; i++)
			{
				s_time = omp_get_wtime();
				pi = mcpi_mt(v_count);
				e_time = omp_get_wtime();

				c_time = e_time - s_time;
				printf("Run %d | pi = %.15lf; time = %lf\n", i, pi, c_time);

				if (min_time > c_time)
					min_time = c_time;
			}
			printf("Min time = %lf\n", min_time);

			break;

		default:

			puts(USAGE);
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
