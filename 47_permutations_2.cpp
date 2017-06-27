#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;


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

void recursion(vector<int> num, int begin, vector<vector<int> > &result) 
{
	if (begin == num.size() - 1)
	{
		result.push_back(num);
		return;
	}
	
	for (int i = begin; i < num.size(); i++)
	{
		if (i != begin && num[i] == num[begin])
		{
			continue;
		}

		swap(num[begin], num[i]);
		recursion(num, begin + 1, result);
	}
}

void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
{
	if (n <= 0)
	{
		v.push_back(r);
		return;
	}
	for (auto &p : map)
	{
		if (p.second <= 0) 
			continue;

		p.second--;
		r.push_back(p.first);
		permuteUnique(v, r, map, n - 1);
		r.pop_back();
		p.second++;
	}
}

void solution2()
{
	vector<int> test = { 1, 2, 1 };

	vector<vector<int> >res;
	vector<int> r;
	map<int, int> map;

	for (int i : test)
	{
		if (map.find(i) == map.end()) 
			map[i] = 0;
		map[i]++;
	}

	permuteUnique(res, r, map, test.size());

	for (auto row : res)
	{
		for (auto col : row)
		{
			cout << col;
		}
		cout << endl;
	}
	cout << "Done" << endl;
}

void solution3()
{
	vector<int> test = { 1, 2, 1 };

	solution3();
	vector<vector<int> >res;
	recursion(test, 0, res);

	for (auto row : res)
	{
		for (auto col : row)
		{
			cout << col;
		}
		cout << endl;
	}
	cout << "Done" << endl;
}

void test_problem_47()
{
	solution2();
	//solution3();
}