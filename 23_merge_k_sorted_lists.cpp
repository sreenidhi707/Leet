#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

bool all_nodes_null(vector<ListNode*>& node_list)
{
	for (size_t i = 0; i < node_list.size(); i++)
	{
		if (node_list[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

ListNode* get_next_min(vector<ListNode*>& node_list)
{
	ListNode* node = new ListNode(INT_MAX);
	int min_id = -1;
	for (size_t i = 0; i < node_list.size(); i++)
	{
		if (node_list[i] != NULL)
		{
			if (node_list[i]->val < node->val)
			{
				node = node_list[i];
				min_id = i;
			}
		}
	}
	node_list[min_id] = node_list[min_id]->next;
	return node;
}

ListNode* merge_k_lists(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
	{
		return NULL;
	}

	vector<ListNode*> current_nodes(lists.size());

	//Initialize 
	bool all_null = true;
	for (size_t i = 0; i < lists.size(); i++)
	{
		current_nodes[i] = lists[i];
		all_null = all_null & (current_nodes[i] == NULL);
	}

	if (all_null)
	{
		return NULL;
	}

	ListNode* head = new ListNode(-1);

	ListNode* node = head;
	while (!all_nodes_null(current_nodes))
	{
		node->next = get_next_min(current_nodes);
		cout << "Current min value is:" << node->next->val << endl;
		node = node->next;
	}

	return head->next;
}

void test_problem_23()
{
	vector<ListNode*> temp;

	ListNode* l1 = get_sorted_ll(0, 5); print_ll(l1);
	ListNode* l2 = get_sorted_ll(2, 7); print_ll(l2);
	ListNode* l3 = get_sorted_ll(7, 11); print_ll(l3);
	ListNode* l4 = get_sorted_ll(5, 15); print_ll(l4);

	temp.push_back(l1);
	temp.push_back(l2);
	temp.push_back(l3);
	temp.push_back(l4);

	ListNode* res = merge_k_lists(temp);
	print_ll(res);

}