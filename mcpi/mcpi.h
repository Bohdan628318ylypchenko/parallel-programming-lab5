#pragma once

/// <summary>
/// Initializes seed for parent thread (e.g. thread - mcpi function caller).
/// </summary>
/// <param name="seed"> Sequence seed. </param>
void mcpi_init(int seed);

/// <summary>
/// Single thread implementation of
/// Monte Carlo PI calculation method.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> PI value. </returns>
double mcpi_1t(int v_count);

/// <summary>
/// Multi thread implementation of
/// Monte Carlo PI calculation method.
/// </summary>
/// <param name="v_count"> Total vector count to generate. </param>
/// <returns> PI value. </returns>
double mcpi_mt(int v_count);
