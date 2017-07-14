#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

static void merge_array(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> temp;

	int i = 0, j = 0;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
		{
			temp.push_back(nums1[i]);
			i++;
		}
		else
		{
			temp.push_back(nums2[j]);
			j++;
		}
	}

	while (i < nums1.size())
	{
		temp.push_back(nums1[i]);
		i++;
	}
	
	while (j < nums2.size())
	{
		temp.push_back(nums2[j]);
		j++;
	}
	nums1 = temp;
}

void test_problem_88()
{

}