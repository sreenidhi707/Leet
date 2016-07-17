#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

#include <ctime>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

vector<int> get_sorted_array(int n)
{
	vector<int> temp;

	for (size_t i = 1; i <= n; i++)
	{
		temp.push_back(i);
	}

	return temp;
}

vector<int> get_random_array(int n)
{
	vector<int> temp;

	for (size_t i = 1; i <= n; i++)
	{
		temp.push_back(i);
	}

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));

	return temp;
}

void print_array(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void array_rotate_modulo(vector<int>& arr, int k)
{
	int size = arr.size();
	vector<int> temp(size);

	for (size_t i = 0; i < arr.size(); i++)
	{
		temp[(i + k) % size] = arr[i];
	}

	arr = temp;
}