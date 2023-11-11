/// <summary>
/// An implementation of the MT19937 Algorithm for the Mersenne Twister
/// by Evan Sultanik.  Based upon the pseudocode in: M. Matsumoto and
/// T. Nishimura, "Mersenne Twister: A 623-dimensionally
/// equidistributed uniform pseudorandom number generator," ACM
/// Transactions on Modeling and Computer Simulation Vol. 8, No. 1,
/// January pp.3-30 1998.
///
/// http://www.sultanik.com/Mersenne_twister
/// </summary>

#pragma once

#define STATE_VECTOR_LENGTH 624
#define STATE_VECTOR_M      397 // changes to STATE_VECTOR_LENGTH also require changes to this

typedef struct tagMTRand
{
	unsigned long mt[STATE_VECTOR_LENGTH];
	int index;
} MTRand;

/// <summary>
/// Creates a new random number generator from a given seed.
/// </summary>
/// <param name="seed"> Seed to grow sequence from. </param>
/// <returns> Initialized MTRand structure. </returns>
MTRand seedRand(unsigned long seed);

/// <summary>
/// Generates a pseudo-randomly generated long.
/// </summary>
/// <param name="rand"> Pointer to initialized MTRand struct. </param>
/// <returns> Random unsigned long. </returns>
unsigned long genRandLong(MTRand * rand);

/// <summary>
/// Generates a pseudo-randomly generated double in the range [0..1].
/// </summary>
/// <param name="rand"> Pointer to initialized MTRand struct. </param>
/// <returns> Random double [0..1]. </returns>
double genRand(MTRand * rand);
