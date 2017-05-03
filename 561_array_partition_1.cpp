#include "stdafx.h"
#include "common_driver.h"

using namespace std;

int array_partition(vector<int>& nums)
{
	sort(nums.rbegin(), nums.rend());

	int sum_of_mins = 0;
	for (int i = 0; i < nums.size(); i+=2)
	{
		sum_of_mins += min(nums[i], nums[i + 1]);
	}
	return sum_of_mins;
}

void test_problem_561()
{
	vector<int> test = {-5, -2, 0, 1, 6, -13, 4, -15};
	int result = array_partition(test);
}