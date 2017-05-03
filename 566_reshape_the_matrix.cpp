#include "stdafx.h"
#include "common_driver.h"

using namespace std;

vector< vector<int> > reshape(vector< vector<int> >& nums, int r, int c)
{
	int result_size = nums.size() * nums[0].size();

	if (result_size != r*c)
	{
		return nums;
	}
	vector<int> linearized;

	for (size_t i = 0; i < nums.size(); i++)
	{
		linearized.insert(linearized.end(), nums[i].begin(), nums[i].end());
	}
	vector< vector<int> > reshaped;

	for (size_t i = 0; i < r; i++)
	{
		vector<int> row;
		for (size_t j = 0; j < c; j++)
		{
			row.push_back(linearized[i*c + j]);
		}
		reshaped.push_back(row);
	}
	return reshaped;
}

void test_problem_566()
{
	//vector< vector<int> > test = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	vector< vector<int> > test = { {1} };
	vector< vector<int> > result = reshape(test, 1, 1);
}