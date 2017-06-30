#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;



vector<vector<int>> subsets(vector<int>& nums)
{
	int num_elements = nums.size();
	int num_subsets = pow(2, num_elements);
	vector<vector<int>> list_subsets(num_subsets, vector<int>());
	
	for (size_t elem = 0; elem < num_elements; elem++)
	{
		for (size_t subset = 0; subset < num_subsets; subset++)
		{
			if (((subset >> elem) & 0x01) == 1)
			{
				list_subsets[subset].push_back(nums[elem]);
			}
		}
	}
	return list_subsets;	
}

void solution1()
{
	vector<int> test = { 1, 2, 3 };
	vector<vector<int>> result = subsets(test);

}

//vector<vector<int>> backtrack2(vector<int>& nums, int start)
//{
//	for (int i = start; i < nums.size(); i++) 
//	{
//		tempList.add(nums[i]);
//		backtrack(list, tempList, nums, i + 1);
//		tempList.remove(tempList.size() - 1);
//	}
//}

static void solution2()
{
	vector<int> test = { 1, 2, 3 };
	vector<vector<int>> tresult;
	//vector<vector<int>> result = backtrack2(test, 0);

	
}

void backtrack3(vector<int>& nums, int start, vector<vector<int>>& result)
{
	if (start == nums.size() - 1)
	{
		vector<int> t{ nums[start] };
		vector<int> null{};
		result.push_back(null);
		result.push_back(t);
		return;
	}

	backtrack3(nums, start + 1, result);

	vector<vector<int>> t;
	for (size_t j = 0; j < result.size(); j++)
	{
		t.push_back(result[j]);
		t[t.size() - 1].push_back(nums[start]);
	}

	for (size_t j = 0; j < t.size(); j++)
	{
		result.push_back(t[j]);
	}

}

static void solution3()
{
	vector<int> test = { 1, 2, 3 };
	vector<vector<int>> result;
	backtrack3(test, 0, result);
}

static void solution4()
{
	vector<int> test = { 1, 2, 3 };
	vector<vector<int>> result;
	backtrack3(test, 0, result);
}

void test_problem_78()
{
	//solution1();
	//solution2();
	solution3();
	

}