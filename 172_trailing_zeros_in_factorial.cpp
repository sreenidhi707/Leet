#include "stdafx.h"
#include "common_driver.h"

int get_trailing_zeros(int n)
{
	int num_zeros = 0;
	while (n)
	{
		n /= 5;
		num_zeros += n;
	}
	return num_zeros;
}

void test_problem_172()
{
	int n = 0;
	while (n >= 0)
	{
		cout << "Enter a number:";
		cin >> n;
		cout << " Number of trailing zeros are:" << get_trailing_zeros(n) << endl;
	}
}
