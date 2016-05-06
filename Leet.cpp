// Leet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cassert>
#include <algorithm> //sort
#include <limits.h>
#include <map>
#include <unordered_map>

#include "LinkedList.h"

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution
{
public:
	

	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> indices;
		bool found_target = false;
		

		std::unordered_multimap<int, int> hash_of_nums;
		for (size_t i = 0; i < nums.size(); i++)
		{
			std::pair<int, int> hash_item(nums.at(i), i); //key, value
			hash_of_nums.insert(hash_item);
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
		
			int new_target = target - nums.at(i);

			std::unordered_multimap<int, int>::const_iterator got = hash_of_nums.find(new_target);

			if (got != hash_of_nums.end())
			{
				if (hash_of_nums.count(new_target) > 1)
				{
					if (got->second == i)
					{
						got++;
						indices.push_back(i + 1); //First Index
						indices.push_back(got->second + 1); //Second Index
					}
					else
					{
						indices.push_back(i + 1); //First Index
						indices.push_back(got->second + 1); //Second Index
					}
					break;
				}
				else //only one instance
				{
					if (got->second != i)
					{
						indices.push_back(i + 1); //First Index
						indices.push_back(got->second + 1); //Second Index
						break;
					}
				}
				
			}				
				
		}
		return(indices);
	}
	/****************************************************************/
	/****************************************************************/
	string problem_6(string s, int numRows)
	{
		string zig_zag_string("");
		int* vector_indices;
		int index_count = 2 * (numRows - 1);
		vector_indices = new int[index_count];

		for (size_t i = 0; i <= index_count/2; i++)
		{
			vector_indices[i] = i;
			vector_indices[index_count - i] = i;
		}

		vector< vector<char> > data_list;

		for (size_t i = 0; i < s.length(); i++)
		{
			vector<char> temp;
			temp.push_back(s[i]);

			if (i < numRows)
			{
				data_list.push_back(temp);
			}
			else
			{
				int index_in_vector_indices = i % index_count;
				int index_of_data_list = vector_indices[index_in_vector_indices];
				data_list[index_of_data_list].push_back(s[i]);
			}
		}

		for (size_t i = 0; i < data_list.size(); i++)
		{
			for (size_t j = 0; j < data_list[i].size(); j++)
			{
				zig_zag_string += data_list[i].at(j);
			}
		}

		return(zig_zag_string);

	}

	/****************************************************************/
	/****************************************************************/

	int problem_7(int x)
	{
		int given_number = x > 0 ? x : -x;
		vector<int> digit_list;
		
		while (given_number > 0)
		{
			int digit = given_number % 10;
			digit_list.push_back(digit);
			given_number -= digit;
			given_number /= 10;
		}

		int no_of_zeros = digit_list.size() - 1;
		int largest_multiplier = 1;
		bool overflow = false;
		while (no_of_zeros > 0)
		{
			if (largest_multiplier > INT_MAX/10)
			{
				overflow = true;
				break;
			}
			largest_multiplier *= 10;
			no_of_zeros--;
		}
		
		int reversed_number = 0;
		if (!overflow)
		{
			for (size_t i = 0; i < digit_list.size(); i++)
			{
				if (digit_list.at(i) != 0)
				{
					if (largest_multiplier > INT_MAX / digit_list.at(i))
					{
						overflow = true;
						break;
					}
				}
				
				int number_tobe_added = digit_list.at(i) * largest_multiplier;
				
				if (reversed_number > INT_MAX - number_tobe_added)
				{
					overflow = true;
					break;
				}
				reversed_number += number_tobe_added;
				largest_multiplier /= 10;
			}
		}

		if (overflow)
		{
			return 0;
		}
		else
		{
			reversed_number = x > 0 ? reversed_number : -reversed_number;
			return(reversed_number);
		}
		

	}

	/****************************************************************/
	/****************************************************************/

	bool problem_9(int x)
	{
		int reversed_num = 0, digit = 0, given_num = x;

		if (x == INT_MIN)
		{
			return false;
		}

		//Make number positive, for palindrome purposes, negative sign is irrelavant(except for INT_MIN)
		x = (x < 0) ? -x : x;
		
		while (x > 0)
		{
			digit = x % 10;
			reversed_num = reversed_num * 10 + digit;
			x /= 10;
		}

		if (reversed_num == given_num)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/****************************************************************/
	/****************************************************************/
	vector<string> level_char_map;

	vector<string> dfs(int level, string seq)
	{
		string chars_this_level;
		if (level >= level_char_map.size())
		{
			vector<string> temp;
			temp.push_back(seq);
			return (temp);
		}
		else
		{
			chars_this_level = level_char_map.at(level);
		}	

		vector<string> list_chars_this_level;
		for (size_t i = 0; i < chars_this_level.size(); i++)
		{
			vector<string> temp;
			temp = dfs(level + 1, seq + chars_this_level[i]);
			list_chars_this_level.insert(list_chars_this_level.begin(), temp.begin(), temp.end());
		}

		return(list_chars_this_level);
	}
	
	vector<string> problem_17_dfs(string digits)
	{
		vector<string> all_combinations;
		bool return_empty = false;
		if (digits.size() == 0)
		{
			return_empty = true;
		}

		//First validate the input
		for (size_t i = 0; i < digits.size(); i++)
		{
			char c = digits[i];
			int num = atoi(&c);
			if (num == 1 || num == 0)
			{
				return_empty = true;
				break;
			}
		}

		if (return_empty)
		{
			return(all_combinations);
		}

		//At this point we can be sure that the input is correct
		map<int, string> keypad_map;
		keypad_map[2] = "abc";
		keypad_map[3] = "def";
		keypad_map[4] = "ghi";
		keypad_map[5] = "jkl";
		keypad_map[6] = "mno";
		keypad_map[7] = "pqrs";
		keypad_map[8] = "tuv";
		keypad_map[9] = "wxyz";

		
		for (size_t i = 0; i < digits.size(); i++)
		{
			char c = digits[i];
			int num = atoi(&c);
			level_char_map.push_back(keypad_map[num]);
		}

		all_combinations = dfs(0, "");
		reverse(all_combinations.begin(), all_combinations.end());
		return(all_combinations);
	}
	
	/****************************************************************/
	/****************************************************************/
	struct counter
	{
	public:
		vector<char> m_counter_values;
		int m_id_current_value;
	
		bool m_cycle_complete;

		counter(string sequence)
		{
			for (size_t i = 0; i < sequence.size(); i++)
			{
				m_counter_values.push_back(sequence[i]);
			}
			m_id_current_value = 0;
			m_cycle_complete = false;
		}

		void turn()
		{
			m_id_current_value++;
			m_cycle_complete = (m_id_current_value == m_counter_values.size()) ? true : false;
			m_id_current_value %= m_counter_values.size();
		}

		char get_current()
		{
			return(m_counter_values.at(m_id_current_value));
		}
	};

	struct keypad_map
	{
		string mapping[8];
	public:
		keypad_map()
		{
			mapping[0] = "abc";
			mapping[1] = "def";
			mapping[2] = "ghi";
			mapping[3] = "jkl";
			mapping[4] = "mno";
			mapping[5] = "pqrs";
			mapping[6] = "tuv";
			mapping[7] = "wxyz";
		};

		string get_string(char n)
		{
			int digit = atoi(&n);
			assert(digit >= 2 || digit <= 9);
			return(mapping[digit - 2]);
		}
	}keypad_map;

	vector<string> problem_17(string digits)
	{		
		vector<string> all_combinations;
		bool return_empty = false;
		if (digits.size() == 0)
		{
			return_empty = true;
		}

		//First validate the input
		for (size_t i = 0; i < digits.size(); i++)
		{
			char c = digits[i];
			int num = atoi(&c);
			if (num == 1 || num == 0)
			{
				return_empty = true;
				break;
			}
		}

		if (return_empty)
		{
			return(all_combinations);
		}

		//At this point we can be sure that the input is correct
		vector<counter> counters;
		int total_combinations = 1;

		for (size_t i = 0; i < digits.size(); i++)
		{
			char c = digits[i];
			string keypad_string = keypad_map.get_string(c);
			counter temp_counter(keypad_string);
			counters.push_back(temp_counter);
			total_combinations *= keypad_string.size();
		}
		
		for (size_t i = 0; i < total_combinations; i++)
		{
			string str = "";
			for (size_t j = 0; j < counters.size(); j++)
			{
				str += counters[j].get_current();
			}
			all_combinations.push_back(str);

			counters[0].turn();
			for (size_t j = 0; j < counters.size() - 1; j++)
			{
				if (counters[j].m_cycle_complete)
				{
					counters[j + 1].turn();
					counters[j].m_cycle_complete = false;
				}
			}
		}
		return(all_combinations);
	}
	
	/****************************************************************/
	/****************************************************************/

	ListNode* problem_19(ListNode* head, int n)
	{
		if (head->next == NULL)
		{
			delete head;
			return(NULL);
		}

		ListNode* pfront = head;
		ListNode* pmid = head;
		ListNode* plast = head;

		int node_count = 0;
		while (pfront->next != NULL)
		{
			pfront = pfront->next;
			node_count++;

			if (node_count > n - 1)
			{
				pmid = pmid->next;
				if (node_count > n)
				{
					plast = plast->next;
				}
			}
			
		}

		ListNode* newHead = head;
		//If head has to be deleted
		if (head == pmid)
		{
			newHead = pmid->next;
		}
		plast->next = pmid->next;
		delete pmid;

		return(newHead);
	}

	/****************************************************************/
	/****************************************************************/

	bool problem_20(string s)
	{
		stack<char> string_stack;

		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				string_stack.push(s[i]);
			}
			else
			{
				if (string_stack.size() == 0)
				{
					return false;
				}
				else
				{
					switch (s[i])
					{
					case ')':
						if (string_stack.top() != '(')
						{
							return false;
						}
						else
						{
							string_stack.pop();
						}
						break;
					case ']':
						if (string_stack.top() != '[')
						{
							return false;
						}
						else
						{
							string_stack.pop();
						}
						break;
					case '}':
						if (string_stack.top() != '{')
						{
							return false;
						}
						else
						{
							string_stack.pop();
						}
						break;
					default:
						cout << "Invalid character found, halting further check" << endl;
						return false;
					}
				}
			}
		}
		if (string_stack.size() > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}

	/****************************************************************/
	/****************************************************************/


	ListNode* problem_21(ListNode* l1, ListNode* l2)
	{
		ListNode* pL1 = l1;
		ListNode* pL2 = l2;
		ListNode* presult_head = new ListNode(0);
		ListNode* presult = presult_head;

		if (pL1 == NULL && pL2 == NULL)
		{
			return(NULL);
		}

		while (pL1 != NULL && pL2 != NULL)
		{
			if (pL1->val < pL2->val)
			{
				presult->next = new ListNode(pL1->val);
				pL1 = pL1->next;
				presult = presult->next;
			}
			else
			{
				presult->next = new ListNode(pL2->val);
				pL2 = pL2->next;
				presult = presult->next;
			}
		}

		if (pL1 == NULL && pL2 != NULL)
		{
			presult->next = pL2;
		}

		if (pL1 != NULL && pL2 == NULL)
		{
			presult->next = pL1;
		}

		ListNode* pnew_result_head = presult_head->next;
		delete presult_head;

		return(pnew_result_head);
	}

	/****************************************************************/
	/****************************************************************/
	bool is_valid_prefix(string s, int max_count)
	{
		stack<char> braces;
		int open_count = 0, close_count = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				braces.push(s[i]);
				open_count++;
			}
			else
			{
				if (braces.size() > 0)
				{
					braces.pop();
					close_count++;
				}
				else
				{
					return false;
				}				
			}
		}
		if (open_count > max_count || close_count > max_count)
		{
			return false;
		}
		return true;
	}

	bool all_braces_are_long_enough(vector<string>& v, int length)
	{
		bool braces_long_enough = true;
		for (size_t i = 0; i < v.size(); i++)
		{
			braces_long_enough &= (v[i].size() == length ? true : false);
		}
		return(braces_long_enough);
	}

	vector<string> problem_22(int n)
	{
		if (n <= 0)
		{
			vector<string> dummy;
			dummy.push_back("");
			return dummy;
		}
		vector<string> valid_prefix_braces;
		int max_count_of_braces = 2*n;
		
		valid_prefix_braces.push_back("(");

		while(!all_braces_are_long_enough(valid_prefix_braces, max_count_of_braces))
		{
			string current_brace = valid_prefix_braces.front();
			valid_prefix_braces.erase(valid_prefix_braces.begin());

			//Append ( and test
			string new_brace = current_brace + "(";
			if (is_valid_prefix(new_brace, n) && new_brace.size() <= max_count_of_braces)
			{
				valid_prefix_braces.push_back(new_brace);
			}

			//Append ) and test
			new_brace = current_brace + ")";
			if (is_valid_prefix(new_brace, n) && new_brace.size() <= max_count_of_braces)
			{
				valid_prefix_braces.push_back(new_brace);
			}
		}

		return (valid_prefix_braces);
	}

	/****************************************************************/
	/****************************************************************/

	ListNode* problem_24(ListNode* pHead)
	{
		if (pHead == NULL)
		{
			return NULL;
		}

		ListNode *pFirst = NULL, *pSecond = NULL, *pPrev = NULL, *pNext = NULL;
		pFirst = pHead;
		pSecond = pFirst->next;
		if (pSecond!= NULL)
		{
			if (pSecond->next != NULL)
			{
				pNext = pSecond->next;
			}

			if (pPrev != NULL)
			{
				pPrev->next = pSecond;
				pFirst->next = pNext;
				pSecond->next = pFirst;
			}

			//Update pointers

		}
		
	}
	
	/****************************************************************/
	/****************************************************************/


	int problem_26(vector<int>& nums)
	{
		if (nums.size() < 2)
		{
			return(nums.size());
		}

		int i = 0, j = 1;
		while (j < nums.size())
		{
			if (nums.at(i) == nums.at(j))
			{
				j++;
			}
			else
			{
				i++;
				nums.at(i) = nums.at(j);
				j++;
			}
		}
		return(i + 1);
	}

	/****************************************************************/
	/****************************************************************/
	
	int problem_27(vector<int>& nums, int val)
	{
		int i = 0, j = 0;
		while (j < nums.size())
		{
			if (nums.at(j) != val)
			{
				nums.at(i) = nums.at(j);
				i++;
			}
			j++;
		}
		return(i);
	}
	/****************************************************************/
	/****************************************************************/
	string get_next_count_and_say(string n)
	{
		bool new_run = true;
		int length = 0;
		char payload;

		char curr_char = n[0];
		string next_count_and_say;

		for (size_t i = 0; i < n.size(); i++)
		{
			if (new_run)
			{
				payload = n[i];
				length = 0;
				new_run = false;
			}
			
			curr_char = n[i];
			char next_char = '\0';
			if (i != (n.size() - 1))
			{
				next_char = n[i + 1];
			}

			if (next_char == curr_char)
			{
				length++;
			}
			else //End of Run
			{
				length += 1;

				next_count_and_say += to_string(length);
				next_count_and_say += payload;
				
				payload = '\0';
				length = 0;
				new_run = true;
			}
		}
		return(next_count_and_say);
	}

	string problem_38(int n)
	{
		string count_and_say = "1";
		for (size_t i = 2; i <= n; i++)
		{
			count_and_say = get_next_count_and_say(count_and_say);
			cout << i << "th count and say number is " << count_and_say << endl;
		}
		return(count_and_say);
	}

	/****************************************************************/
	/****************************************************************/

	bool check_bst(TreeNode* pNode, int minVal, int maxVal)
	{
		if (pNode == NULL)
		{
			return true;
		}

		int nodeVal_minus_one = (pNode->val < INT_MIN + 1) ? INT_MIN : pNode->val - 1;
		int nodeVal_plus_one = (pNode->val > INT_MAX - 1) ? INT_MAX : pNode->val + 1;

		bool left_bst = check_bst(pNode->left, minVal, nodeVal_minus_one);
		bool right_bst = check_bst(pNode->right, nodeVal_plus_one, maxVal);

		if (pNode->left != NULL && pNode->val == pNode->left->val ||
			pNode->right != NULL && pNode->val == pNode->right->val)
		{
			return false;
		}

		if (left_bst && right_bst && pNode->val >= minVal && pNode->val <= maxVal)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/****************************************************************/
	/****************************************************************/

	bool problem_98(TreeNode* pRoot)
	{
		bool isBst = check_bst(pRoot, INT_MIN, INT_MAX);
		return(isBst);		
	}

	/****************************************************************/
	/****************************************************************/

	int problem_215(vector<int>& nums, int k)
	{
		std::sort(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.end());
		return (nums.at(k-1));
	}

	/****************************************************************/
	/****************************************************************/

	void problem_283(vector<int>& nums)
	{
		bool zero_encountered = false;
		int non_zero_end_loc = 0;
		
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums.at(i) == 0)
			{
				if (!zero_encountered)
				{
					non_zero_end_loc = i;
					zero_encountered = true;
					continue;
				}
			}
			else
			{
				if (zero_encountered)
				{
					nums.at(non_zero_end_loc) = nums.at(i);
					non_zero_end_loc++;
				}
			}
		}

		//Now copy the extra zeros at the end
		if (zero_encountered)
		{
			for (size_t i = non_zero_end_loc; i < nums.size(); i++)
			{
				nums.at(i) = 0;
			}
		}
		
	}
	
	/****************************************************************/
	/****************************************************************/

	string problem_344(string s)
	{
		for (int i = 0; i < s.size()/2; i++)
		{
			char temp = s[i];
			s[i] = s[s.size() - 1 - i];
			s[s.size() - 1 - i] = temp;
		}
		return(s);
	}

	/****************************************************************/
	/****************************************************************/

	bool is_vowel(char c)
	{
		return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	}

	string problem_345(string s)
	{
		int left = 0;
		int right = s.size() - 1;

		while (left <= right)
		{
			//If left and right are vowels, then swap
			if (is_vowel(s[left]) && is_vowel(s[right]))
			{
				char temp = s[left];
				s[left] = s[right];
				s[right] = temp;
				left++;
				right--;
			}

			//Increment only left, if it is not vowel
			if (!is_vowel(s[left]))
			{
				left++;
			}

			//Increment only right, it is not vowel
			if (!is_vowel(s[right]))
			{
				right--;
			}
		}
		return(s);
	}

	/****************************************************************/
	/****************************************************************/
};

int main()
{
	int problem_id;

	cout << "Enter which Leet code problem you want to solve: ";
	cin >> problem_id;
	Solution sol;
	

	switch (problem_id)
	{
	case 6:
	{
		cout << endl << endl;
		cout << "Leet code Problem 6: ZigZag Conversion" << endl;
		cout << "Problem discription: The string \"PAYPALISHIRING\" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)" << endl;
		cout << "P   A   H   N" << endl;
		cout << "A P L S I I G" << endl;
		cout << "Y   I   R" << endl;
		cout << "And then read line by line: \"PAHNAPLSIIGYIR\"" << endl;
		cout << "Write the code that will take a string and make this conversion given a number of rows:" << endl;
		cout << "string convert(string text, int nRows);" << endl;
		cout << "convert(\"PAYPALISHIRING\", 3) should return \"PAHNAPLSIIGYIR\"." << endl;
		cout << "Link: https://leetcode.com/problems/zigzag-conversion/" << endl;

		string input_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int num_rows = 5;

		while (1)
		{
			cout << "Enter string:";
			cin >> input_string;
			cout << "Enter number of rows:";
			cin >> num_rows;
			string output_string = sol.problem_6(input_string, num_rows);
			cout << "Zig Zag converted string is: " << output_string << endl;
		}
		
		break;
	}
	case 7:
	{
		cout << endl << endl;
		cout << "Leet code Problem 7: Reverse Integer" << endl;
		cout << "Reverse digits of an integer." << endl;
		cout << "Example1: x = 123, return 321" << endl;
		cout << "Example2: x = -123, return -321" << endl;
		
		while (true)
		{
			int input_number = 0;
			cout << "Enter a number to be reversed:";
			cin >> input_number;
			int reversed_number = sol.problem_7(input_number);
			cout << "Reversed number is:" << reversed_number << endl;
		}
		break;
	}
	case 9:
	{
		cout << endl << endl;
		cout << "Leet code Problem 9: Palindrome Number" << endl;
		cout << "Determine whether an integer is a palindrome. Do this without extra space." << endl;

		while (true)
		{
			bool is_palindrome = false;
			int input_number = 0;
			cout << "Enter a number to be checked if it is a palindrom or not:";
			cin >> input_number;
			is_palindrome = sol.problem_9(input_number);
			if (is_palindrome)
			{
				cout << input_number << " is a palindrome" << endl;
			}
			else
			{
				cout << input_number << " is NOT a palindrome" << endl;
			}
		}
		break;
	}
	case 17:
	{
		cout << endl << endl;
		cout << "Leet code Problem 17: Letter Combinations of a Phone Number" << endl;
		cout << "Given a digit string, return all possible letter combinations that the number could represent." << endl;
		cout << "A mapping of digit to letters (just like on the telephone buttons) is given below." << endl;
		cout << "Input:Digit string 23" << endl;
		cout << "Output: [\"ad\", \"ae\", \"af\", \"bd\", \"be\", \"bf\", \"cd\", \"ce\", \"cf\"]." << endl;

		string s;
		cout << "Enter your string:";
		cin >> s;

		
		//vector<string> combinations = sol.problem_17(s);
		vector<string> combinations = sol.problem_17_dfs(s);
		cout << "There are totally " << combinations.size() << " combinations, they are :" << endl;

		//sort(combinations.begin(), combinations.end());
		for (size_t i = 0; i < combinations.size(); i++)
		{
			cout << combinations[i] << ",";
		}
		break;
	}
	case 19:
	{
		cout << endl << endl;
		cout << "Leet code Problem 19: Remove Nth Node From End of List" << endl;
		cout << "Given a linked list, remove the nth node from the end of list and return its head." << endl;
		cout << "For example," << endl;
		cout << "Given linked list: 1->2->3->4->5, and n = 2." << endl;
		cout << "After removing the second node from the end, the linked list becomes 1->2->3->5." << endl;
		cout << "Note:" << endl;
		cout << "Given n will always be valid, Try to do this in one pass." << endl;

		ListNode* phead = new ListNode(0);
		ListNode* pnode1 = new ListNode(1);
		phead->next = pnode1;

		/*ListNode* pnode2 = new ListNode(2);
		pnode1->next = pnode2;

		ListNode* pnode3 = new ListNode(3);
		pnode2->next = pnode3;

		ListNode* pnode4 = new ListNode(4);
		pnode3->next = pnode4;

		ListNode* pnode5 = new ListNode(5);
		pnode4->next = pnode5;

		ListNode* pnode6 = new ListNode(6);
		pnode5->next = pnode6;

		ListNode* pnode7 = new ListNode(7);
		pnode6->next = pnode7;*/

		ListNode* res = sol.problem_19(phead, 2);
		break;
	}
	case 20:
	{
		cout << endl << endl;
		cout << "Leet code Problem 20: Valid Parentheses" << endl;
		cout << "Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid." << endl;
		cout << "The brackets must close in the correct order, \"()\"and \"()[] {}\" are all valid but \"(]\" and \"([)]\" are not." << endl;
		
		while (true)
		{
			string given_string;
			cout << "Enter your string:";
			cin >> given_string;
			bool isValid = sol.problem_20(given_string);
			if (isValid)
			{
				cout << "Given string is Valid: " << endl;
			}
			else
			{
				cout << "Given string is INVALID: " << endl;
			}
			
		}
		break;
	}
	case 21:
	{
		cout << endl << endl;
		cout << "Leet code Problem 21: Merge Two Sorted Lists" << endl;
		cout << "Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists." << endl;

		ListNode* phead = new ListNode(0);
		ListNode* pnode1 = new ListNode(1);
		phead->next = pnode1;

		/*ListNode* pnode2 = new ListNode(2);
		pnode1->next = pnode2;

		ListNode* pnode3 = new ListNode(3);
		pnode2->next = pnode3;

		ListNode* pnode4 = new ListNode(4);
		pnode3->next = pnode4;

		ListNode* pnode5 = new ListNode(5);
		pnode4->next = pnode5;

		ListNode* pnode6 = new ListNode(6);
		pnode5->next = pnode6;

		ListNode* pnode7 = new ListNode(7);
		pnode6->next = pnode7;*/

		ListNode* res = sol.problem_19(phead, 2);
		break;
	}
	case 22:
	{
		cout << endl << endl;
		cout << "Leet code Problem 22: Generate Parentheses" << endl;
		cout << "Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses." << endl;
		cout << "For example, given n = 3, a solution set is:" << endl;

		cout << "Link: https://leetcode.com/problems/generate-parentheses/" << endl;

		int n = 1;
		cout << "Enter n:";
		cin >> n;

		vector<string> valid_braces = sol.problem_22(n);

		cout << "Valid braces are:" << endl;
		for (size_t i = 0; i < valid_braces.size(); i++)
		{
			cout << valid_braces[i] << endl;
		}
		break;
	}
	case 26:
	{
		cout << endl << endl;
		cout << "Leet code Problem 26: Remove Duplicates from Sorted Array" << endl;
		cout << "Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length." << endl;
		cout << "Do not allocate extra space for another array, you must do this in place with constant memory." << endl;
		cout << "For example," << endl;
		cout << "Given input array nums = [1,1,2]" << endl;
		cout << "Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length." << endl;

		cout << "Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/" << endl;

		vector<int> data;
		data.push_back(2);
		data.push_back(2);
		data.push_back(4);

		int newLength = sol.problem_26(data);

		for (size_t i = 0; i < newLength; i++)
		{
			cout << data.at(i) << ", ";
		}
		cout << "New Length is " << newLength << endl;
		break;
	}
	case 38:
	{
		cout << endl << endl;
		cout << "Leet code Problem 38: Count and Say" << endl;
		cout << "The count-and-say sequence is the sequence of integers beginning as follows:" << endl;
		cout << "1, 11, 21, 1211, 111221, ..." << endl;
		cout << "1 is read off as \"one 1\" or 11." << endl;
		cout << "11 is read off as \"two 1s\" or 21." << endl;
		cout << "21 is read off as \"one 2, then one 1\" or 1211." << endl;
		cout << "Given an integer n, generate the nth sequence." << endl;
		cout << "Note: The sequence of integers will be represented as a string." << endl;
		
		int n = 1;
		cout << "Enter n:";
		cin >> n;
		string count_and_say = sol.problem_38(n);

		cout << "The nth count and say number is:" << count_and_say;

		cout << "Link: https://leetcode.com/problems/validate-binary-search-tree/" << endl;
		break;
	}
	case 98:
	{
		cout << endl << endl;
		cout << "Leet code Problem 98: Validate Binary Search Tree" << endl;
		cout << "Assume a BST is defined as follows:" << endl;
		cout << "	~The left subtree of a node contains only nodes with keys less than the node's key." << endl;
		cout << "	~The right subtree of a node contains only nodes with keys greater than the node's key." << endl;
		cout << "	~Both the left and right subtrees must also be binary search trees." << endl;

		cout << "Link: https://leetcode.com/problems/validate-binary-search-tree/" << endl;

		TreeNode* pRoot = new TreeNode(INT_MAX);
		//TreeNode* pLeft = new TreeNode(INT_MAX+1);
		//pRoot->left = pLeft;

		bool isBst = sol.problem_98(pRoot);
		if (isBst)
		{
			cout << "The Given binary is a Valid Binary Search Tree" << endl;
		}
		else
		{
			cout << "The Given binary is a NOT a Valid Binary Search Tree" << endl;
		}
		break;
	}
	case 215:
	{
		cout << endl << endl;
		cout << "Leet code Problem 215: Kth Largest Element in an Array" << endl;
		cout << "Problem discription: Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element." << endl;
		cout << "For example, Given[3, 2, 1, 5, 6, 4] and k = 2, return 5. " << endl;
		//cout << "Note: You may assume k is always valid, 1 ≤ k ≤ array's length." << endl;
		cout << "Link: https://leetcode.com/problems/kth-largest-element-in-an-array/" << endl;

		//std::vector<int> data{ 3,2,1,5,6,4 };
		std::vector<int> data = { 3,2,1,5,6,4 };
		int kth_largest_num = sol.problem_215(data, 2);

		cout << "Kth largest number is " << kth_largest_num << endl;
		break;
	}
	case 283:
	{
		cout << endl << endl;
		cout << "Leet code Problem 283: Move Zeroes" << endl;
		cout << "Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements." << endl;
		cout << "For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]." << endl;
		cout << "Note:" << endl;
		cout << "	1. You must do this in-place without making a copy of the array." << endl;
		cout << "	2. Minimize the total number of operations:" << endl;
		cout << "Link: https://leetcode.com/problems/move-zeroes/" << endl;

		std::vector<int> data = { 0,0,0,3,12 };
		sol.problem_283(data);
		break;
	}
	case 344:
	{
		cout << endl << endl;
		cout << "Leet code Problem 344: Reverse String" << endl;
		cout << "Write a function that takes a string as input and returns the string reversed." << endl;
		cout << "Example:" << endl;
		cout << "Given s = \"hello\", return \"olleh\"." << endl;
		cout << "Link: https://leetcode.com/problems/reverse-string/" << endl;

		string s;
		cout << "Enter your string";
		cin >> s;

		s = sol.problem_344(s);
		cout << "Reversed string is " << s;
		break;
	}
	case 345:
	{
		cout << endl << endl;
		cout << "Leet code Problem 345: Reverse Vowels of a String" << endl;
		cout << "Write a function that takes a string as input and reverse only the vowels of a string." << endl;
		cout << "Example 1:" << endl;
		cout << "Given s = \"hello\", return \"holle\"." << endl;
		cout << "Example 2:" << endl;
		cout << "Given s = \"leetcode\", return \"leotcede\"." << endl;
		cout << "Link: https://leetcode.com/problems/reverse-vowels-of-a-string/" << endl;

		string s;
		cout << "Enter your string";
		cin >> s;

		s = sol.problem_345(s);
		cout << "Vowel reversed string is " << s;
		break;
	}

	default:
		vector<int> nums;
		vector<int> indices;

		nums.push_back(-1);
		nums.push_back(-2);
		nums.push_back(-3);
		nums.push_back(-4);
		nums.push_back(-5);
		
		indices = sol.twoSum(nums, -8);

		for (size_t i = 0; i < indices.size(); i++)
		{
			cout << indices.at(i) << endl;
		}
		break;
	}
	

	return 0;
}

