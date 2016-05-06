#pragma once

#include <iostream>
using namespace std;

class doubly_ll_node
{
public:
	doubly_ll_node()
	{
		right = NULL;
		left = NULL;
		payload = '0';
		printed = false;
	}

	doubly_ll_node* right;
	doubly_ll_node* left;
	char payload;
	bool printed;
};

class doubly_ll
{
public:
	doubly_ll()
	{
		phead = NULL;
		node_count = 0;
	}

	doubly_ll_node* phead;
	int node_count;
	
	void add_node(char payload);
	doubly_ll_node* get_nth_node(int n);
	
};

void doubly_ll::add_node(char payload)
{
	if (phead == NULL)
	{
		//Create new node
		phead = new doubly_ll_node;
		phead->left = NULL;
		phead->right = NULL;
		phead->payload = payload;
	}
	else
	{
		doubly_ll_node* pnode = phead;
		while (pnode->right != NULL)
		{
			pnode = pnode->right;
		}

		//Create new node
		doubly_ll_node* new_node = new doubly_ll_node;

		pnode->right = new_node;

		new_node->left = pnode;
		new_node->right = NULL;
		new_node->payload = payload;
	}

	node_count++;
}

doubly_ll_node* doubly_ll::get_nth_node(int n)
{
	doubly_ll_node* node = phead;

	if (n > node_count)
	{
		cout << "Requested node does not exist, there are only " << node_count << " nodes" << endl;
		return NULL;
	}

	for (size_t i = 0; i < n; i++)
	{
		node = node->right;
	}

	return(node);
}