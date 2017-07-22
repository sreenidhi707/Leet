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

string longest_palindrome_substring2(string s)
{
	if (s.empty())
	{
		return "";
	}
	
	//The code doesn't handle 1 character strings well, simply return the character instead
	size_t N = s.size();
	if (s.size() == 1)
	{
		return s;
	}

	//Construct a table of size NxN

	vector<vector<bool>> table(N, vector<bool>(N, false));
	int max_length = 0;
	int max_length_sid = 0, max_length_eid = 0;

	//initialize the table
	//palindromes of length 1
	for (size_t row = 0; row < N; row++)
	{
		table[row][row] = true;
	}

	//palindromes of length 2
	for (size_t i = 0; i < N - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			table[i][i + 1] = true;
			
			//In case we found a palindrome of length 2, we need to store the start and end ids
			//because it could happen that the longest palindrome is of length 2
			max_length = 2;
			max_length_sid = i;
			max_length_eid = i + 1;
		}
	}

	int row_start = 0;
	int row_end = N - 2;
	int col_start = 2;
	int col_end = N;
	int rows_left = N - 2;
	while (rows_left)
	{
		int row = row_start;
		int col = col_start;
		while (row < row_end && col < col_end)
		{
			if (table[row + 1][col - 1] && s[row] == s[col])
			{
				table[row][col] = true;
				if (col - row + 1 > max_length)
				{
					max_length = col - row + 1;
					max_length_sid = row;
					max_length_eid = col;
				}
			}
			row++;
			col++;
		}
		row_end--;
		col_start++;
		rows_left--;
	}
	return s.substr(max_length_sid, max_length_eid - max_length_sid + 1);
}


void test_problem_5()
{
	string test = "cbbd";
	//string res = longest_palindrome_substring(test);
	string res = longest_palindrome_substring2(test);
	cout << res;
}