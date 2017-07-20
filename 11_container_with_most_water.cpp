#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

int max_area_spanning_center(vector<int>& nums, int left, int mid, int right)
{
	int lmax = 0, rmax = 0;
	int lmaxID = 0, rmaxID = 0;

	//traverse right
	for (size_t i = mid + 1; i <= right; i++)
	{
		if (nums[i] > rmax)
		{
			rmax = nums[i];
			rmaxID = i;
		}
	}

	//traverse left
	for (size_t i = mid - 1; i >= left; i--)
	{
		if (nums[i] > lmax)
		{
			lmax = nums[i];
			lmaxID = i;
		}
	}

	if (rmax > 0 && lmax > 0)
	{
		return min(lmax, rmax) * (rmaxID - lmaxID);
	}
	else
	{
		return 0;
	}
	

}

int max_area(vector<int>& nums, int start, int end)
{
	if (nums.empty())
	{
		return 0;
	}

	//Base case of recursion
	if (end - start == 1)
	{
		return min(nums[start], nums[end]);
	}

	//Non base case, divide into two parts
	int lstart = start;
	int lend = lstart + (end - start) / 2;
	int rstart = lend;
	int rend = end;
	int mid = lend;

	int lmax = max_area(nums, lstart, lend);
	int rmax = max_area(nums, rstart, rend);
	int mmax = max_area_spanning_center(nums, lmax, mid, rmax);

	return max(max(lmax, rmax), mmax);
}

int max_area2(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;

	int max_area = 0;

	while (start < end)
	{
		max_area = max(max_area, (end - start) * min(nums[start], nums[end]));
		if (nums[start] < nums[end])
		{
			start++;
		}
		else 
		{
			end--;
		}
	}
	return max_area;
}

void test_problem_11()
{
	vector<int> data = {1,1};
	int max = max_area2(data);
	cout << max;
}