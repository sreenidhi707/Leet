#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"


void deleteNode(ListNode* node) 
{
	if (node == NULL || node->next == NULL)
	{
		return;
	}

	ListNode*  prev = node;
	ListNode* walker = node;

	while (walker->next != NULL)
	{
		prev = walker;
		walker->val = walker->next->val;
		walker = walker->next;
	}

	delete walker;
	prev->next = NULL;
}

void test_problem_237()
{


}