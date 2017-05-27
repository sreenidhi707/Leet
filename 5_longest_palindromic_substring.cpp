#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

static bool is_palindrome(string s)
{
	int start = 0;
	int end = s.size() - 1;
	while (start <= end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

string longest_palindrome_substring(string s)
{
	if (s.empty())
	{
		return "";
	}

	int start = 0, end = 0;
	int max_length = 0, length = 0;

	while (end < s.size())
	{
		string substring = s.substr(start, end - start + 1);
		if (is_palindrome(substring))
		{
			length++;
		}
		else
		{
			start = end;
			length = 0;
		}
		
		max_length = (length > max_length) ? length : max_length;
		end++;
	}
	
}


void test_problem_5()
{
	string test = "babad";
	string res = longest_palindrome_substring(test);
	cout << res;
}