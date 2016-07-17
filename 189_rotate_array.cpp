#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

void array_rotate1(vector<int>& arr, int k)
{
	array_rotate_modulo(arr, k);
}

void test_problem_189()
{
	vector<int> arr = get_sorted_array(10);

	cout << "Array before rotation:";
	print_array(arr);
	array_rotate1(arr, 3);
	cout << "Array after rotation:";
	print_array(arr);
}