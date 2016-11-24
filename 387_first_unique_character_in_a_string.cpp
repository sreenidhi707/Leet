#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"


uint32_t get_unique_character(string s)
{
	uint32_t count[26];
	memset(count, 0, 26 * sizeof(uint32_t));

	for (size_t i = 0; i < s.size(); i++)
	{
		count[s[i] - 'a']++;
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		if (count[s[i] - 'a'] == 1)
		{
			return i;
		}
	}

	return -1;
}

void test_problem_387()
{
	string s;

	cout << "Enter a string:" << endl;
	cin >> s;
	uint32_t id = get_unique_character(s);

}