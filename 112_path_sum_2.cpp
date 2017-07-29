#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

vector<vector<int>> pathSum(TreeNode* root, int sum, bool& present)
{
	if (root == NULL)
	{
		present = false;
		vector<vector<int>> tvv(0, vector<int>());
		return tvv;
	}

	if (root->left == NULL && root->right == NULL && root->val == sum)
	{
		present = true;
		vector<int> tv(1, root->val);
		vector<vector<int>> tvv(1, tv);
		return tvv;
	}

	bool lpresent = false, rpresent = false;
	vector<vector<int>> lpaths = pathSum(root->left, sum - root->val, lpresent);
	vector<vector<int>> rpaths = pathSum(root->right, sum - root->val, rpresent);

	vector<vector<int>> tvv(0, vector<int>());
	present = false;
	if (lpresent)
	{
		for (size_t i = 0; i < lpaths.size(); i++)
		{
			lpaths[i].push_back(root->val);
			tvv.push_back(lpaths[i]);
		}
		present = true;
	}
	if (rpresent)
	{
		for (size_t i = 0; i < rpaths.size(); i++)
		{
			rpaths[i].push_back(root->val);
			tvv.push_back(rpaths[i]);
		}
		present = true;
	}
	return tvv;
}

void test_problem_112()
{


									  TreeNode n0(5);
					TreeNode n1(4);                 TreeNode n2(8);
		TreeNode n3(11);                 TreeNode n4(13);          TreeNode n5(4);
	TreeNode n6(7); TreeNode n7(2);                        TreeNode n8(5);    TreeNode n9(1);

	n0.left = &n1; n0.right = &n2;
	n1.left = &n3;
	n2.left = &n4; n2.right = &n5;
	n3.left = &n6; n3.right = &n7;
	n5.left = &n8; n5.right = &n9;
	
	bool present = false;
	vector<vector<int>> paths = pathSum(&n0, 22, present);

	for (auto path : paths)
	{
		for (auto node : path)
		{
			cout << node << ",";
		}
		cout << endl;
	}
}