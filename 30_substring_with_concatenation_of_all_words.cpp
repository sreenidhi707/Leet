#include "stdafx.h"
#include "common_driver.h"

using namespace std;

bool allWordsPresent(string s, vector<string>& words, int& min_pos)
{
	min_pos = INT32_MAX;
	for (auto word : words)
	{
		string::size_type pos = s.find(word);
		min_pos = (pos < min_pos) ? pos : min_pos;
		if (pos == string::npos)
		{
			return false;
		}
	}
	return true;
}

vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> original_map(256, 0);
	vector<int> result;
	int original_counter = 0;

	for (auto word : words)
	{
		original_counter += word.size();
		for (auto c : word)
		{
			original_map[c]++;
		}
	}

	int start = 0, end = 0;
	int temp_counter = original_counter;
	vector<int> temp_map(original_map);
	
	while (end < s.size())
	{
		if (temp_map[s[end]] > 0)
		{
			temp_map[s[end]]--;
			temp_counter--;
		}

		if (temp_counter == 0)
		{
			string sub_string = s.substr(start, end - start + 1);
			int start_pos = 0;
			if (allWordsPresent(sub_string, words, start_pos))
			{
				result.push_back(start_pos + start);
			}
			end++;
			start = end;
			temp_counter = original_counter;
			temp_map = original_map;
		}
		else
		{
			end++;
		}
	}

	return result;
}

//vector<int> findSubstring2(string S, vector<string> &L)
//{
//	vector<int> ans;
//	int n = S.size(), cnt = L.size();
//	if (n <= 0 || cnt <= 0)
//		return ans;
//
//	// init word occurence
//	unordered_map<string, int> dict;
//	for (int i = 0; i < cnt; ++i)
//	{
//		dict[L[i]]++;
//	}		
//
//	// travel all sub string combinations
//	int wl = L[0].size();
//
//	for (int i = 0; i < wl; ++i)
//	{
//		int left = i, count = 0;
//		unordered_map<string, int> tdict;
//		for (int j = i; j <= n - wl; j += wl)
//		{
//			string str = S.substr(j, wl);
//			// a valid word, accumulate results
//			if (dict.count(str))
//			{
//				tdict[str]++;
//				if (tdict[str] <= dict[str])
//				{
//					count++;
//				}
//				else
//				{
//					// a more word, advance the window left side possiablly
//					while (tdict[str] > dict[str])
//					{
//						string str1 = S.substr(left, wl);
//						tdict[str1]--;
//						if (tdict[str1] < dict[str1])
//						{
//							count--;
//						}
//						left += wl;
//					}
//				}
//				// come to a result
//				if (count == cnt)
//				{
//					ans.push_back(left);
//					// advance one word
//					tdict[S.substr(left, wl)]--;
//					count--;
//					left += wl;
//				}
//			}
//			// not a valid word, reset all vars
//			else
//			{
//				tdict.clear();
//				count = 0;
//				left = j + wl;
//			}
//		}
//	}
//
//	return ans;
//}

void test_problem_30() 
{
	/*vector<string> words = {"foo", "bar"};
	vector<int> idx = findSubstring2("barfoothefoobarman", words);
	cout << "The indices are:";
	for (auto i : idx)
	{
		cout << i << ",";
	}
	return;*/
}