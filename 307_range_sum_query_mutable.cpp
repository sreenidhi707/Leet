#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

/* https://github.com/sreenidhi707/datastructures/tree/master/segment_trees for more details */

int mid(int s, int e)
{
	return(s + (e - s) / 2);
}

class NumArray {
public:
	vector<int> seg_tree;
	uint32_t data_size;
	int construct_seg_tree(int current_idx, vector<int>& arr, int start_idx, int end_idx);
	int get_sum(int query_start_idx, int query_end_idx, int arr_start_idx, int arr_end_idx, int current_idx);
	int update_r(int arr_start_idx, int arr_end_idx, int current_idx, int index, int value);

	NumArray(vector<int> &nums) {
		data_size = nums.size();
		if (data_size == 0)
		{
			return;
		}
		//Initialize segment tree with zeros

		int tree_size = int(ceil(log2(data_size)));
		tree_size = 2 * pow(2, tree_size) - 1;
		for (size_t i = 0; i < tree_size; i++)
		{
			seg_tree.push_back(0);
		}

		construct_seg_tree(0, nums, 0, nums.size() - 1);
	}

	void update(int i, int val) {
		if (data_size == 0)
		{
			return;
		}
		update_r(0, data_size - 1, 0, i, val);
	}

	int sumRange(int i, int j) {
		if (data_size == 0)
		{
			return 0;
		}
		return(get_sum(i, j, 0, data_size - 1, 0));
	}
};

int NumArray::construct_seg_tree(int current_idx, vector<int>& arr, int start_idx, int end_idx)
{
	if (start_idx == end_idx)
	{
		seg_tree[current_idx] = arr[start_idx];
		return seg_tree[current_idx];
	}
	else
	{
		int middle = mid(start_idx, end_idx);
		int left_sum = construct_seg_tree(2 * current_idx + 1, arr, start_idx, middle);
		int right_sum = construct_seg_tree(2 * current_idx + 2, arr, middle + 1, end_idx);
		seg_tree[current_idx] = left_sum + right_sum;
		return seg_tree[current_idx];
	}
}

int NumArray::get_sum(int query_start_idx, int query_end_idx, int arr_start_idx, int arr_end_idx, int current_idx)
{
	int arr_mid_idx = mid(arr_start_idx, arr_end_idx);
	int query_mid_idx = mid(query_start_idx, query_end_idx);

	if (query_start_idx == arr_start_idx  && query_end_idx == arr_end_idx)
	{
		return seg_tree[current_idx];
	}
	else if (query_start_idx >= arr_mid_idx + 1)
	{
		//divide array and query
		int right_sum = get_sum(query_start_idx, query_end_idx, arr_mid_idx + 1, arr_end_idx, 2 * current_idx + 2);
		return(right_sum);
	}
	else if (query_end_idx <= arr_mid_idx)
	{
		int left_sum = get_sum(query_start_idx, query_end_idx, arr_start_idx, arr_mid_idx, 2 * current_idx + 1);
		return(left_sum);
	}
	else
	{
		int new_query_start_right = arr_mid_idx + 1;
		int new_query_end_left = arr_mid_idx;
		int left_sum = get_sum(query_start_idx, new_query_end_left, arr_start_idx, arr_mid_idx, 2 * current_idx + 1);
		int right_sum = get_sum(new_query_start_right, query_end_idx, arr_mid_idx + 1, arr_end_idx, 2 * current_idx + 2);
		return(left_sum + right_sum);
	}
}

int NumArray::update_r(int arr_start_idx, int arr_end_idx, int current_idx, int index, int value)
{
	int middle = mid(arr_start_idx, arr_end_idx);

	if (arr_start_idx == arr_end_idx) //update index is the current index
	{
		assert(arr_start_idx == index);

		int diff = value - seg_tree[current_idx];
		seg_tree[current_idx] = value;
		return diff;
	}
	else if (index <= middle) //update index falls on the left tree
	{
		int diff = update_r(arr_start_idx, middle, 2 * current_idx + 1, index, value);
		seg_tree[current_idx] += diff;
		return diff;
	}
	else if (index > middle) //update index falls on the right tree
	{
		int diff = update_r(middle + 1, arr_end_idx, 2 * current_idx + 2, index, value);
		seg_tree[current_idx] += diff;
		return diff;
	}
	return 0;
}

void test_problem_307()
{
	vector<int> nums;

	 NumArray numArray(nums);
	 numArray.sumRange(0, 1);
	 numArray.update(1, 10);
	 numArray.sumRange(1, 2);
}