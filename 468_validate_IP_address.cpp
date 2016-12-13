#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

//string ipv4_or_ipv6(string s)
//{
//	bool has_to_be_ipv4 = false;
//	bool has_to_be_ipv6 = false;
//	
//	//Check if there is a dot in the string
//	uint32_t dot_count = 0;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '.')
//		{
//			has_to_be_ipv4 = true;
//			dot_count++;
//		}
//	}
//	has_to_be_ipv4 = dot_count != 4 ? false : true;
//
//	//Check if there is a colon in the string
//	if (!has_to_be_ipv4)
//	{
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (s[i] == ':')
//			{
//				has_to_be_ipv6 = true;
//				break;
//			}
//		}
//	}
//
//	if (has_to_be_ipv4 && has_to_be_ipv6)
//	{
//		return "Neither";
//	}
//	else if(has_to_be_ipv4 || has_to_be_ipv6)
//	{
//		if (has_to_be_ipv4)
//		{
//			string temp;
//			for (size_t i = 0; i < s.size(); i++)
//			{
//				//leading zero test
//				if (s[i] == '.' && s[i + 1] == '0')
//				{
//					if (i == s.size() - 2)
//					{
//						//this condition is fine
//					}
//					else
//					{
//						if (s[i + 2] != '.')
//						{
//							return "Neither";
//						}
//					}
//				}
//
//				temp
//			}
//		}
//		else
//		{
//
//		}
//	}
//	else
//	{
//		return "Neither";
//	}
//}

void test_problem_468()
{
	string s;

	//string result = ipv4_or_ipv6(s);
}