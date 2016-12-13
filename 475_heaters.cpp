#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

using namespace std;

uint32_t find_min_radius(vector<uint32_t>& houses, vector<uint32_t>& heaters)
{
	uint32_t bitmap_size = max(houses[houses.size() - 1], heaters[heaters.size() - 1]);
	
	vector<bool> houses_bitmap(bitmap_size, false);
	vector<bool> heater_bitmap(bitmap_size, false);

	for (size_t i = 0; i < houses.size(); i++)
	{
		houses_bitmap[houses[i] - 1] = true;
	}

	for (size_t i = 0; i < heaters.size(); i++)
	{
		heater_bitmap[heaters[i] - 1] = true;
	}

	uint32_t min_radius = 0;
	bool all_houses_not_warmed = true;
	while (all_houses_not_warmed)
	{
		min_radius++;

		//Loop through heater bitmap
		for (size_t i = 0; i < heater_bitmap.size(); i++)
		{
			if (heater_bitmap[i])
			{
				//House in current position
				houses_bitmap[i] = false;

				//House to the left
				if (i >= min_radius)
				{
					houses_bitmap[i - min_radius] = false;
				}

				//House to the right
				if (i + min_radius < houses_bitmap.size())
				{
					houses_bitmap[i + min_radius] = false;
				}

				//Check if all houses are warmed, with this value of min_radius
				all_houses_not_warmed = false;
				for (size_t j = 0; j < houses_bitmap.size(); j++)
				{
					all_houses_not_warmed = all_houses_not_warmed | houses_bitmap[j];
				}

				if (!all_houses_not_warmed)
				{
					break;
				}
			}
		}

		
	}

	return min_radius;
}

void test_problem_475()
{
	vector<uint32_t> houses = { 3, 4 };
	vector<uint32_t> heaters = { 2, 3, 4, 5};


	uint32_t minRadius = find_min_radius(houses, heaters);
}
