#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;



string longest_palindrome_substring(string s)
{
	if (s.empty())
	{
		return "";
	}

	int num_centers = 2*s.size() - 1;
	
	int max_length = 0;
	int max_length_sid = 0, max_length_eid = 0;
	for (int i = 0; i < num_centers; i++)
	{
		int curr_max_length = 0;
		int l, r;
		l = (i - 1) / 2;
		r = (i + 2) / 2;

		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			curr_max_length = r - l + 1;
			if (curr_max_length > max_length)
			{
				max_length = curr_max_length;
				max_length_sid = l;
				max_length_eid = r;
			}
			l -= 1;
			r += 1;
			
		}
	}
	return s.substr(max_length_sid, max_length_eid - max_length_sid + 1);
}


void test_problem_5()
{
	string test = "banana";
	string res = longest_palindrome_substring(test);
	cout << res;
}