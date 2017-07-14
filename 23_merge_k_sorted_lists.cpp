#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"
#include <functional>

class heap_node
{
public:
	int val;
	int list_idx;
	ListNode* next_node;

	heap_node(int v, int id, ListNode* next)
	{
		val = v;
		list_idx = id;
		next_node = next;
	}
};

bool heap_compare(const heap_node* a, const heap_node* b)
{
	return a->val > b->val;
}

ListNode* merge_k_lists(vector<ListNode*>& lists)
{
	if (lists.empty())
	{
		return NULL;
	}

	vector<heap_node*> min_array;
	int non_empty_lists = lists.size();
	for (size_t i = 0; i < lists.size(); i++)
	{
		if (lists[i] == NULL)
		{
			non_empty_lists--;
			continue;
		}
		heap_node* n = new heap_node(lists[i]->val, i, lists[i]->next);
		min_array.push_back(n);
	}
	make_heap(min_array.begin(), min_array.end(), heap_compare);

	ListNode* phead = new ListNode(0);
	ListNode* pwalker = phead;

	while (non_empty_lists)
	{
		pop_heap(min_array.begin(), min_array.end(), heap_compare);

		heap_node* min_node = min_array[min_array.size() - 1];
		ListNode* temp = new ListNode(min_node->val);
		pwalker->next = temp;
		pwalker = temp;
		
		if (min_node->next_node == NULL)
		{
			non_empty_lists--;

			//insert INF
			heap_node* n = new heap_node(INT32_MAX, -1, NULL);

			min_array.pop_back();
			min_array.push_back(n);
			push_heap(min_array.begin(), min_array.end(), heap_compare);
		}
		else
		{
			ListNode* next_min = min_node->next_node;
			heap_node* n = new heap_node(next_min->val, min_node->list_idx, next_min->next);

			min_array.pop_back();
			min_array.push_back(n);
			push_heap(min_array.begin(), min_array.end(), heap_compare);
		}
		for (auto i : min_array)
		{
			cout << i->val << ",";
		}
		cout << endl;
	}

	//Remove dummy node
	ListNode* presult = phead->next;
	delete phead;

	return presult;

}

void test_problem_23()
{
	vector<ListNode*> temp;

	ListNode* l1 = get_sorted_ll(0, 2); print_ll(l1);
	ListNode* l2 = get_sorted_ll(4, 5); print_ll(l2);
	ListNode* l3 = get_sorted_ll(6, 6); print_ll(l3);
	ListNode* l4 = get_sorted_ll(7, 10); print_ll(l4);

	temp.push_back(l1);
	temp.push_back(l2);
	temp.push_back(l3);
	temp.push_back(l4);

	ListNode* res = merge_k_lists(temp);
	print_ll(res);

}