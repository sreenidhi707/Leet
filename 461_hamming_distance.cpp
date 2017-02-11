#include "stdafx.h"
#include "common_driver.h"

using namespace std;

uint32_t hamming_distance(int32_t a, int32_t b)
{
	uint32_t dist = 0, n = a ^ b;
	while (n) 
	{
		++dist;
		n &= n - 1;
	}

	return dist;
}

void test_problem_461()
{
	uint32_t dist = 0;
	dist = hamming_distance(1, 4);
}