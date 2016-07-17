#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

void test_problem_61()
{
	int size_ll = 0, k = 0;
	cout << endl << endl << endl;
	cout << "****************************************************" << endl;
	while (size_ll > -1)
	{
		cout << "Enter size of Linked List (Enter negative number to Exit):";
		cin >> size_ll;
		if (size_ll < 0)
		{
			break;
		}
		cout << "Enter how much to rotate:";
		cin >> k;

		ListNode* head = get_random_ll(size_ll);
		cout << "Linked List before rotation:";
		print_ll(head);
		ListNode* new_head = rotate_right_ll(head, k);
		cout << "Linked List after rotation:";
		print_ll(new_head);
		cout << "****************************************************" << endl;

		
	}
	
}