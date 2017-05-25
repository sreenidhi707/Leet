#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

uint32_t get_longest_from_index(string s, uint32_t index)
{
	uint32_t longest = 0;
	set<char> chars;

	for (size_t i = index; i < s.size(); i++)
	{
		if (chars.find(s[i]) == chars.end())
		{
			longest += 1;
			chars.insert(s[i]);
		}
		else
		{
			return longest;
		}
	}
	return longest;
}

uint32_t longest_substring(string s)
{
	uint32_t longest_string_length = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		uint32_t temp = get_longest_from_index(s, i);
		if (temp> longest_string_length)
		{
			longest_string_length = temp;
		}
	}
	return longest_string_length;
}

uint32_t longest_substring2(string s)
{
	if (s.empty())
	{
		return 0;
	}
	int start = 0, end = 0;
	int max_length = INT32_MIN;
	int length = 0;
	vector<int> map(256, 0);

	while (end < s.size())
	{
		map[s[end]]++;
		length++;
		if (map[s[end]] == 2)
		{
			while (map[s[start]] != 2)
			{
				map[s[start++]]--;
			}
			map[s[start++]]--;
			length = end - start + 1;
		}
		else
		{
			max_length = (length > max_length) ? length : max_length;
		}
		end++;
	}

	return max_length;
}

void test_problem_3()
{
	string test = "pwwkew";
	uint32_t res = longest_substring2(test);
	cout << res;
}