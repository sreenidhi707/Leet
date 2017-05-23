#include "stdafx.h"
#include "common_driver.h"

using namespace std;

bool match_hist(vector<int>& windows_hist, vector<int>& t_hist)
{
	for (size_t i = 0; i < 256; i++)
	{
		if (t_hist[i] > 0 && (windows_hist[i] < t_hist[i]))
		{
			return false;
		}
	}
	return true;
}

vector<int> get_hist(string s)
{
	vector<int> hist(256, 0);
	for (size_t i = 0; i < s.size(); i++)
	{
		hist[s[i]]++;
	}
	return hist;
}

string minumum_window_substring(string s, string t)
{
	if (s.size() == 0 || t.size() == 0)
	{
		return "";
	}

	vector<int> t_hist = get_hist(t);
	int start = 0, end = 0;
	vector<int> windows_hist(256, 0);
	
	string min_substring = "";
	int min_substring_length = INT32_MAX;
	int min_substring_start = 0;
	bool minimum_substring_exists = false;

	while (end < s.size())
	{
		windows_hist[s[end]]++;
		if (match_hist(windows_hist, t_hist))
		{
			minimum_substring_exists = true;
			while (start <= end && match_hist(windows_hist, t_hist))
			{
				windows_hist[s[start]]--;
				start++;
			}
			start--;
			windows_hist[s[start]]++;

			int new_substring_length = end - start + 1;
			if (new_substring_length < min_substring_length)
			{
				min_substring_start = start;
				min_substring_length = new_substring_length;
			}
		}
		end++;
	}

	if (minimum_substring_exists)
	{
		min_substring = s.substr(min_substring_start, min_substring_length);
	}	
	return min_substring;
}

string minumum_window_substring2(string s, string t)
{
	if (s.size() == 0 || t.size() == 0)
	{
		return "";
	}

	vector<int> want_count(256, 0);
	vector<int> have_count(256, 0);
	int remaining_count = 0;
	for (auto ch : t)
	{
		want_count[ch]++;
		remaining_count++;
	}

	int start = 0, end = 0;
	int min_start = 0;
	int min_length = INT32_MAX;

	while (end < s.size())
	{
		have_count[s[end]]++;
		if (have_count[s[end]] <= want_count[s[end]])
		{
			remaining_count--;
		}

		while (remaining_count == 0)
		{
			if (end - start + 1 < min_length)
			{
				min_length = end - start + 1;
				min_start = start;
			}

			have_count[s[start]]--;
			if (have_count[s[start]] < want_count[s[start]])
			{
				remaining_count++;
			}
			start++;
		}
		end++;
	}

	if (min_length != INT32_MAX)
	{
		return s.substr(min_start, min_length);
	}

	return "";
}

void test_problem_76()
{
	
	//string min_substring = minumum_window_substring("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country", "ask_country");
	string min_substring = minumum_window_substring2("adobecodebanc", "abc");
	//string min_substring = minumum_window_substring("bdab", "ab");
	cout << "Minimum Substring is " << min_substring << endl;


}