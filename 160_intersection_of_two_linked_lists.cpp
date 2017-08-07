#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

int get_length(ListNode* pnode)
{
	int l = 0;
	while (pnode != NULL)
	{
		l++;
		pnode = pnode->next;
	}
	return l;
}

ListNode* get_n(ListNode* pnode, int n)
{
	while (n-- && pnode != NULL)
	{
		pnode = pnode->next;
	}
	return pnode;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL) return NULL;

	int lA = get_length(headA);
	int lB = get_length(headB);

	ListNode* newheadA = headA;
	ListNode* newheadB = headB;
	if (lA != lB)
	{
		if (lA > lB)
		{
			newheadA = get_n(headA, lA - lB);
		}
		else
		{
			newheadB = get_n(headB, lB - lA);
		}
	}

	while (newheadA != NULL && newheadB != NULL)
	{
		if (newheadA->val == newheadB->val)
		{
			return newheadA;
		}
		newheadA = newheadA->next;
		newheadB = newheadB->next;
	}

	return NULL;
}

void test_problem_160()
{
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	
	ListNode m1(6), m2(7);
	m1.next = &m2;

	ListNode* intersect = getIntersectionNode(&n1, &m1);
}