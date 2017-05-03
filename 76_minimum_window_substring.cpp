#include "stdafx.h"
#include "common_driver.h"

using namespace std;

bool match_hist(vector<int>& windows_hist, vector<int>& t_hist)
{
	for (size_t i = 0; i < 26; i++)
	{
		if (t_hist[i] > 0 && windows_hist[i] == 0)
		{
			return false;
		}
	}
	return true;
}

vector<int> get_hist(string s)
{
	vector<int> hist(26, 0);
	for (size_t i = 0; i < s.size(); i++)
	{
		hist[s[i] - 'a']++;
	}
	return hist;
}

string minumum_window_substring(string s, string t)
{
	if (s.size() == 0 || t.size() == 0)
	{
		return "";
	}

	transform(s.begin(), s.end(), s.begin(), std::tolower);

	vector<int> t_hist = get_hist(t);
	int start = 0, end = 0;
	vector<int> windows_hist(26, 0);
	string min_substring = "";
	int min_substring_length = INT32_MAX;

	while (end < s.size())
	{
		windows_hist[s[end] - 'a']++;
		if (match_hist(windows_hist, t_hist))
		{
			string new_substring = s.substr(start, end - start + 1);
			int new_substring_length = new_substring.size();

			if (new_substring_length < min_substring_length)
			{
				min_substring = new_substring;
				min_substring_length = new_substring_length;
			}

			while (start <= end && match_hist(windows_hist, t_hist))
			{
				windows_hist[s[start] - 'a']--;
				start++;
			}
			start--;
			windows_hist[s[start] - 'a']++;
			
		}
		end++;
	}

	string new_substring = s.substr(start, end - start + 1);
	int new_substring_length = new_substring.size();

	if (new_substring_length < min_substring_length)
	{
		min_substring = new_substring;
		min_substring_length = new_substring_length;
	}

	return min_substring;
}

void test_problem_76()
{
	
	string min_substring = minumum_window_substring("adobecodebanc", "abc");
	cout << "Minimum Substring is " << min_substring << endl;


}