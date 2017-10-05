#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

int getLength(ListNode* head)
{
	int length = 0;
	ListNode* walker = head;
	while (walker)
	{
		length++;
		walker = walker->next;
	}
	return length;
}

ListNode* getMid(ListNode* head, int start, int end)
{
	if (start > end) return NULL;

	int length = (end - start + 1) / 2;
	ListNode* walker = head;
	while (start--)
	{
		walker = walker->next;
	}

	while (length--)
	{
		walker = walker->next;
	}
	return walker;
}

TreeNode* sortedListToBST(ListNode* head, int start, int end)
{
	if (head == NULL) return NULL;

	ListNode* mid = getMid(head, start, end);
	TreeNode *root = NULL;
	
	if (mid)
	{
		root = new TreeNode(mid->val);

		int mid = start + (end - start + 1) / 2;
		root->left = sortedListToBST(head, start, mid - 1);
		root->right = sortedListToBST(head, mid + 1, end);
	}
	return root;
}

void test_problem_109()
{
	ListNode* head = get_sorted_ll(6);
	int length = getLength(head);

	TreeNode* root = sortedListToBST(head, 0, length - 1);
	return;
}