#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H
#pragma once

#include "common_includes.h"
#include "common_structs.h"

//Arrays
vector<int> get_sorted_array(int n);
vector<int> get_sorted_array(int start, int end);
vector<int> get_random_array(int n);
void print_array(vector<int>& arr);
void array_rotate_modulo(vector<int>& arr, int k);

//Linked Lists
int get_length_ll(ListNode* head);
ListNode* get_tail_ll(ListNode* head);
void print_ll(ListNode* head);
ListNode* get_random_ll(int n);
ListNode* get_sorted_ll(int n);
ListNode* get_sorted_ll(int start, int end);
ListNode* get_node_from_end(ListNode* head, int n, int length);
ListNode* rotate_right_ll(ListNode* head, int k);

#endif
