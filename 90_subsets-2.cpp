#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;


void backtrack1(vector<int>& nums, int start, set<vector<int>>& result)
{
	if (start == nums.size() - 1)
	{
		vector<int> t{ nums[start] };
		vector<int> null{};
		result.insert(null);
		result.insert(t);
		return;
	}

	backtrack1(nums, start + 1, result);

	vector<vector<int>> t;
	for (auto set_elem : result)
	{
		t.push_back(set_elem);
		t[t.size() - 1].push_back(nums[start]);
	}

	for (auto set_elem : t)
	{
		result.insert(set_elem);
	}

}

static void solution1()
{
	vector<int> test = { 1, 1, 2 };
	set<vector<int>> result;
	sort(test.begin(), test.end());
	backtrack1(test, 0, result);

	vector<vector<int>> final_result;
	for (auto elem : result)
	{
		final_result.push_back(elem);
	}
}


void test_problem_90()
{
	solution1();


}