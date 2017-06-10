#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

vector<int> remove_n(vector<int> nums, int index)
{
	vector<int> temp;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (i != index)
		{
			temp.push_back(nums[i]);
		}
	}
	return temp;
}

vector< vector<int> > permute(vector<int> nums)
{
	if (nums.size() == 1)
	{
		vector< vector<int> > t1;
		t1.push_back(nums);
		return t1;
	}

	vector< vector<int> > result;
	for (size_t i = 0; i < nums.size(); i++)
	{
		vector<int> temp = remove_n(nums, i);

		vector< vector<int> > result_i = permute(temp);

		for (size_t j = 0; j < result_i.size(); j++)
		{
			result_i[j].push_back(nums[i]);
			result.push_back(result_i[j]);
		}
	}
	return result;
}

void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) 
{
	if (begin >= num.size()) 
	{
		// one permutation instance
		result.push_back(num);
		return;
	}

	for (int i = begin; i < num.size(); i++) 
	{
		swap(num[begin], num[i]);
		permuteRecursive(num, begin + 1, result);
		// reset
		swap(num[begin], num[i]);
	}
}

void test_problem_46()
{
	vector<int> test = { 1, 1, 3 };

	//vector< vector<int> > result = permute(test);
	vector<vector<int> > result;

	permuteRecursive(test, 0, result);

	for (auto row : result)
	{
		for (auto col : row)
		{
			cout << col;
		}
		cout << endl;
	}
	cout << "Done" << endl;
}