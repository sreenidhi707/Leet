#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

int unique_paths(vector<vector<int>>& obstacleGrid)
{
	int H = obstacleGrid.size();
	int W = obstacleGrid[0].size();
	vector<vector<int>> paths(H, vector<int>(W, 0));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			paths[i][j] = 0;
		}
	}

	//Initialize first column
	for (int row = 0; row < H; row++)
	{
		//Check if first element in every row is a 1 in obstacle grid
		if (obstacleGrid[row][0] == 1)
		{
			break;
		}
		paths[row][0] = 1;
	}

	//Initialize first row
	for (int col = 0; col < W; col++)
	{
		//Check if first element in every row is a 1 in obstacle grid
		if (obstacleGrid[0][col] == 1)
		{
			break;
		}
		paths[0][col] = 1;
	}

	for (int row = 1; row < H; row++)
	{
		for (int col = 1; col < W; col++)
		{
			if (obstacleGrid[row][col] == 1)
			{
				paths[row][col] = 0;
			}
			else
			{
				paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
			}
		}
	}

	return paths[W - 1][H - 1];
}

void test_problem_63()
{
	vector<int> trow = { 0, 0 };
	vector<vector<int>> tpaths = { trow };

	int uniquePaths = unique_paths(tpaths);
	cout << uniquePaths;
}