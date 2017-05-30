#include "stdafx.h"
#include "common_driver.h"

using namespace std;

int binary_search(vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1;
	
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		if (nums[mid] == target)
		{
			return mid;
		}
		
		if (target > nums[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}

int search_for_end(vector<int>& nums, int start_index, int target)
{
	int start = start_index;
	int end = nums.size() - 1;

	while (start < end)
	{
		int mid = (end - start) / 2 + start;

		if (nums[mid] == target && nums[mid + 1] != target)
		{
			return mid;
		}

		if (nums[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	assert(0);
}

int search_for_start(vector<int>& nums, int end_index, int target)
{
	int start = 0;
	int end = end_index;

	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		if (nums[mid - 1] != target && nums[mid] == target)
		{
			return mid;
		}

		if (nums[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	assert(0);
}

vector<int> search_for_range(vector<int>& nums, int target)
{
	vector<int> res;
	int index = binary_search(nums, target);

	if (index == -1)
	{
		res = { -1, -1 };
		return res;
	}

	int end = -1;
	if ((index < (nums.size() - 1)) 
		&& (nums[index + 1] == nums[index]))
	{
		end = search_for_end(nums, index + 1, target);
	}
	else
	{
		end = index;
	}

	int start = -1;
	if ((index > 0)
		&& (nums[index - 1] == nums[index]))
	{
		start = search_for_start(nums, index - 1, target);
	}
	else 
	{
		start = index;
	}

	res = { start, end};
	return res;
}

int lower_bound(vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1;

	int mid = 0;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		if (target > nums[mid])
		{
			start = mid + 1;
		}
		else 
		{
			end = mid - 1;
		}
	}

	return start;
}

int upper_bound(vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1;

	int mid = 0;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;

		if (target >= nums[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return start - 1;
}

vector<int> solve(vector<int>& nums, int target)
{
	vector<int> result;
	
	int low = lower_bound(nums, target);
	low = (nums[low] == target) ? low : -1;

	int high = upper_bound(nums, target);
	high = (nums[high] == target) ? high : -1;

	if (low == -1 || high == -1)
	{
		result = { -1, -1 };
	}
	else
	{
		result = {low , high};
	}

	return result;
}

void test_problem_34()
{
	vector<int> test = { 5, 6, 7, 8, 8, 20 };
	int target = 9;

	vector<int> result = solve(test, target);

	cout << "Done" << endl;
}