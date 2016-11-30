#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"
#include "../Utilities/utilities.h"


void test_problem_150()
{
	vector<string> tokens = { "3","-4","+" };
	int32_t res = evaluate_rpn(tokens);
}