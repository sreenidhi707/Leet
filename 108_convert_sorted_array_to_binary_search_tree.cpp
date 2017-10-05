#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

TreeNode* sortedListToBST(vector<int> data, int start, int end)
{
	if (start > end) return NULL;

	int mid = start + (end - start + 1) / 2;
	
	TreeNode *root = new TreeNode(data[mid]);
	root->left = sortedListToBST(data, start, mid - 1);
	root->right = sortedListToBST(data, mid + 1, end);

	return root;
}

void test_problem_108()
{
	vector<int> data = get_sorted_array(6);

	TreeNode* root = sortedListToBST(data, 0, data.size() - 1);
	return;
}