#include "stdafx.h"
#include "common_driver.h"

using namespace std;

int search_insert(vector<int> nums, int target)
{
	if (nums.empty())
	{
		return 0;
	}
	int start = 0, end = nums.size() - 1;

	if (target > nums[nums.size() - 1])
	{
		return nums.size();
	}
	if (target < nums[0])
	{
		return 0;
	}

	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		if (target == nums[mid])
		{
			return mid;
		}
		else if (start == end)
		{
			return start;
		}
		else if (target < nums[mid])
		{
			end = mid;
		}
		else if(target > nums[mid])
		{
			start = mid + 1;
		}
	}
}

int search_insert2(vector<int> nums, int target)
{
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (target > nums[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
void test_problem_35()
{
	vector<int> test = {1, 3, 5, 6};
	int res = search_insert2(test, 7);
	cout << res << endl;
}