#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

static bool is_palindrome(string s)
{
	if (s.size() == 0)
	{
		return true;
	}

	int start = 0;
	int end = s.size() - 1;

	while (start < end)
	{
		if (!is_char_alpha_numeric(s[start]))
		{ 
			start++;
			continue;
		}

		if (!is_char_alpha_numeric(s[end]))
		{
			end--;
			continue;
		}

		if (tolower(s[start]) != tolower(s[end]))
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void test_problem_125()
{
	string s;

	while (s != "exit")
	{
		cout << "Enter a string " << endl;
		getline(cin, s); 
		//s = "a234a";
		if (is_palindrome(s))
		{
			cout << "Your string is a palindrome" << endl;
		}
		else
		{
			cout << "Your string is NOT a palindrome" << endl;
		}
	}
	
}