#include "stdafx.h"
#include "common_driver.h"

using namespace std;

string sort_in_string(string s)
{
	string res = "";

	if (s.size() == 0)
	{
		return res;
	}

	uint32_t string_histogram[26];
	memset(string_histogram, 0, 26*sizeof(uint32_t));

	for (size_t i = 0; i < s.size(); i++)
	{
		string_histogram[s[i] - 'a']++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		while (string_histogram[i])
		{
			char c = 'a' + i;
			res += c;
			string_histogram[i]--;
		}
	}

	return res;
}

bool valid_anagram(string a, string b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	else if (a.size() == 0 && b.size() == 0)
	{
		return true;
	}
	else if ((a.size() == 0 && b.size() > 0) ||
		(a.size() > 0 && b.size() == 0))
	{
		return false;
	}

	if (sort_in_string(a) == sort_in_string(b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test_problem_242()
{
	bool anagram = valid_anagram("abc", "cba");
	return;
}