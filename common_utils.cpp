#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

#include <ctime>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

/*******************************************/
/*******************************************/
/********BOOLEAN UTILITY FUNCTIONS**********/
/*******************************************/
/*******************************************/

bool is_char_alpha_numeric(char c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************/
/*******************************************/
/*******************ARRAYS******************/
/*******************************************/
/*******************************************/
vector<int> get_sorted_array(int n)
{
	vector<int> temp;

	for (size_t i = 1; i <= n; i++)
	{
		temp.push_back(i);
	}

	return temp;
}

vector<int> get_sorted_array(int start, int end)
{
	vector<int> temp;

	for (size_t i = start; i <= end; i++)
	{
		temp.push_back(i);
	}

	return temp;
}

vector<int> get_random_array(int n)
{
	vector<int> temp;

	for (size_t i = 1; i <= n; i++)
	{
		temp.push_back(i);
	}

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));

	return temp;
}

void print_array(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void array_rotate_modulo(vector<int>& arr, int k)
{
	int size = arr.size();
	vector<int> temp(size);

	for (size_t i = 0; i < arr.size(); i++)
	{
		temp[(i + k) % size] = arr[i];
	}

	arr = temp;
}


/*******************************************/
/*******************************************/
/***************LINKED LISTS****************/
/*******************************************/
/*******************************************/

/**************PRIVATE FUNCTIONS*************/
ListNode* convert_array_to_ll(vector<int>& arr)
{
	if (arr.size() == 0)
	{
		return NULL;
	}

	ListNode* head = new ListNode(arr[0]);

	ListNode* node = head;
	for (size_t i = 1; i < arr.size(); i++)
	{
		node->next = new ListNode(arr[i]);
		node = node->next;
	}

	return head;
}


/**************PUBLIC FUNCTIONS*************/
int get_length_ll(ListNode* head)
{
	int length = 0;
	ListNode* node = head;
	while (node != NULL)
	{
		length++;
		node = node->next;
	}

	return length;
}

ListNode* get_tail_ll(ListNode* head)
{
	ListNode* node = head;
	ListNode* prev = head;
	while (node != NULL)
	{
		prev = node;
		node = node->next;
	}
	return prev;
}

void print_ll(ListNode* head)
{
	ListNode* node = head;
	while (node != NULL)
	{
		cout << node->val << "-->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

ListNode* get_node_from_begin(ListNode* head, int n, int length)
{
	if (head == NULL || n > length)
	{
		return NULL;
	}

	int count = 1;
	ListNode* node = head;
	while (node != NULL && count < n)
	{
		count++;
		node = node->next;
	}

	return node;
}

ListNode* get_node_from_end(ListNode* head, int n, int length)
{
	int count_from_begin = length - n + 1;
	return(get_node_from_begin(head, count_from_begin, length));
}

ListNode* get_sorted_ll(int n)
{
	return(convert_array_to_ll(get_sorted_array(n)));
}

ListNode* get_sorted_ll(int start, int end)
{
	return(convert_array_to_ll(get_sorted_array(start, end)));
}

ListNode* get_random_ll(int n)
{
	return(convert_array_to_ll(get_random_array(n)));
}

ListNode* rotate_right_ll(ListNode* head, int k)
{
	if (head == NULL)
	{
		return NULL;
	}

	int length = get_length_ll(head);
	k %= length;

	if (k == 0)
	{
		return head;
	}

	

	int new_head_node = length - k + 1;

	ListNode* old_head = head;
	ListNode* old_tail = get_tail_ll(head);
	ListNode* new_head = get_node_from_begin(head, new_head_node, length);
	ListNode* new_tail = get_node_from_begin(head, new_head_node - 1, length);

	new_tail->next = NULL;
	old_tail->next = old_head;

	return new_head;

}