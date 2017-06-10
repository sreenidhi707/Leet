#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

static vector<int> remove_n(vector<int> nums, int index)
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

int get_num(vector<int>& nums)
{
	int num = 0;
	int multiplier = 1;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		num += nums[i] * multiplier;
		multiplier *= 10;
	}
	return num;
}
unordered_map<int, vector< vector<int> >> table;

static vector< vector<int> > permute(vector<int> nums)
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
		int hash = get_num(temp);
		if (table.find(hash) != table.end()) //hash found
		{
			return table[hash];
		}

		vector< vector<int> > result_i = permute(temp);
		table[hash] = result_i;

		for (size_t j = 0; j < result_i.size(); j++)
		{
			vector<int> t = result_i[j];
			t.push_back(nums[i]);
			int thash = get_num(t);
			if (table.find(thash) == table.end())
			{
				result.push_back(t);
			}
			//result_i[j].push_back(nums[i]);
			//result.push_back(result_i[j]);
		}
	}
	return result;
}

static void permuteRecursive(vector<int> &num, int begin, 
	unordered_set<int>& table, vector< vector<int>>& result)
{
	if (begin >= num.size())
	{
		int hash = get_num(num);
		if (table.count(hash) == 0)
		{
			table.insert(hash);
			result.push_back(num);
		}
		return;
	}

	for (int i = begin; i < num.size(); i++)
	{
		swap(num[begin], num[i]);
		permuteRecursive(num, begin + 1, table, result);
		// reset
		swap(num[begin], num[i]);
	}
}

void test_problem_47()
{
	vector<int> test = { 1, 2, 1 };


	//vector< vector<int> > result = permute(test);

	unordered_set<int> table;
	vector < vector<int> > result;
	permuteRecursive(test, 0, table, result);

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