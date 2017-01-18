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

void test_problem_3()
{
	string test = "dvdf";
	uint32_t res = longest_substring(test);
	cout << res;
}