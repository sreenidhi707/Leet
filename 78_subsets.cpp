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

void test_problem_78()
{
	vector<int> test = { 1, 2, 3 };
	vector<vector<int>> result = subsets(test);

	

}