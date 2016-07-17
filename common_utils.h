#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H
#pragma once

#include "common_includes.h"
#include "common_structs.h"

vector<int> get_sorted_array(int n);
vector<int> get_random_array(int n);
void print_array(vector<int>& arr);
void array_rotate_modulo(vector<int>& arr, int k);
#endif
