#include "stdafx.h"
#include "common_driver.h"

using namespace std;

vector<uint32_t> string_histogram(string s)
{
	vector<uint32_t> character_histogram(26, 0);
	
	for (uint32_t i = 0; i < s.size(); i++)
	{
		character_histogram[s[i] - 'a']++;
	}

	return character_histogram;
}

bool histograms_equal(vector<uint32_t>&a, vector<uint32_t>&b)
{
	for (size_t i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

vector<uint32_t> findAnagrams(string s, string p) 
{
	vector<uint32_t> start_indices;

	if (s.size() == 0 || p.size() == 0 || p.size() > s.size())
		return start_indices;

	vector<uint32_t> p_hist = string_histogram(p);
	vector<uint32_t> s_hist = string_histogram(s.substr(0, p.size()));

	if (s.size() == p.size())
	{
		if (histograms_equal(p_hist, s_hist))
		{
			start_indices.push_back(0);
		}
		return start_indices;
	}

	uint32_t idx = 0;
	while (idx + p.size() < s.size())
	{
		if (histograms_equal(p_hist, s_hist))
		{
			start_indices.push_back(idx);
		}
		
		s_hist[s[idx] - 'a']--;
		s_hist[s[idx + p.size()] - 'a']++;

		idx++;
	}

	if (histograms_equal(p_hist, s_hist))
	{
		start_indices.push_back(idx);
	}

	return start_indices;
}

void test_problem_438()
{
	vector<uint32_t> indices = findAnagrams("baa", "aa");
	return;
}