#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

const int MAX_NUM_ROWS = 6;
const int MAX_NUM_COLS = 6;

int grid[MAX_NUM_ROWS][MAX_NUM_COLS] =
{
	{1,1,1,0,0,0},
	{1,1,1,0,0,0},
	{1,0,0,1,0,0},
	{0,0,0,0,0,0},
	{1,1,1,0,0,0},
	{1,1,1,0,0,0},
};

struct cell
{
	int row, col;
	bool val;
	bool visited;
};

cell cells[MAX_NUM_ROWS][MAX_NUM_COLS];

void construct_cell_grid()
{
	for (size_t i = 0; i < MAX_NUM_ROWS; i++)
	{
		for (size_t j = 0; j < MAX_NUM_COLS; j++)
		{
			cells[i][j].row = i;
			cells[i][j].col = j;
			
			cells[i][j].val = grid[i][j];
			cells[i][j].visited = false;
		}
	}
}

void construct_cell_from_vector()
{
	for (size_t i = 0; i < MAX_NUM_ROWS; i++)
	{
		for (size_t j = 0; j < MAX_NUM_COLS; j++)
		{
			cells[i][j].row = i;
			cells[i][j].col = j;

			cells[i][j].val = grid[i][j];
			cells[i][j].visited = false;
		}
	}
}

//vector<vector<char>>& convert_grid_to_vector()
//{
//
//}
//
//int numIslands(vector<vector<char>>& grid) 
//{
//
//}

void dfs_walk(int row, int col)
{
	
	std::stack<cell> unvisited_cells;

	unvisited_cells.push(cells[row][col]);

	while (unvisited_cells.size() != 0)
	{
		if (unvisited_cells.top().visited == false)
		{
			//Check TOP neighbor
			if (row > 0 && cells[row - 1][col].val == 1 && cells[row - 1][col].visited == false)
			{
				unvisited_cells.push(cells[row - 1][col]);
			}

			//Check RIGHT neighbor
			if (col < MAX_NUM_COLS - 1 && cells[row + 1][col + 1].val == 1 && cells[row][col + 1].visited == false)
			{
				unvisited_cells.push(cells[row][col + 1]);
			}

			//Check BOTTOM neighbor
			if (row < MAX_NUM_ROWS - 1 && cells[row + 1][col].val == 1 && cells[row + 1][col].visited == false)
			{
				unvisited_cells.push(cells[row + 1][col]);
			}

			//Check LEFT neighbor
			if (col > 0 && cells[row][col - 1].val == 1 && cells[row][col - 1].visited == false)
			{
				unvisited_cells.push(cells[row][col - 1]);
			}

			//Mark current cell as visited
			unvisited_cells.top().visited = true;

			//Remove current cell from stack
			unvisited_cells.pop();
		}
	}
}

void test_problem_200()
{
	construct_cell_grid();

	int num_islands = 0;

	for (size_t row = 0; row < MAX_NUM_ROWS; row++)
	{
		for (size_t col = 0; col < MAX_NUM_COLS; col++)
		{
			if (cells[row][col].val == 1 && cells[row][col].visited == false)
			{
				dfs_walk(row, col);
				num_islands++;
			}
		}
	}

}