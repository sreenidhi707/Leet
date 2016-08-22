#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"
//
//int min_in_rotated_array(vector<int>& arr, int start, int end)
//{
//	//Stopping Condition
//	if (true)
//	{
//
//	}
//
//
//	int mid = (start + end) / 2;
//	int min = 0;
//	if (arr[mid - 1] > arr[mid] && arr[mid + 1] > arr[mid])
//	{
//		min = arr[mid];
//	}
//	else if (arr[mid - 1] < arr[mid] && arr[mid + 1] > arr[mid])
//	{
//		if (arr[end] > arr[mid])
//		{
//			min = min_in_rotated_array(arr, start, mid);
//		}
//		else
//		{
//			min = min_in_rotated_array(arr, mid, end);
//		}
//	}
//
//}
//
void test_problem_153()
{
	int size = 0, k = 0;
	cout << endl << endl << endl;
	cout << "****************************************************" << endl;
	while (size > -1)
	{
		cout << "Enter size of the array (Enter negative number to Exit):";
		cin >> size;
		if (size < 0)
		{
			break;
		}
		cout << "Enter how much to rotate:";
		cin >> k;

		vector<int> arr = get_sorted_array(size);
		array_rotate_modulo(arr, k);

		cout << "Given array:";
		print_array(arr);
		//int min = min_in_rotated_array(arr, 0, arr.size() - 1);
		//cout << "Minimum value is:" << min;
		cout << "****************************************************" << endl;


	}
}