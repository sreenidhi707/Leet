#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"

const int MAX_NUM_ROWS = 6;
const int MAX_NUM_COLS = 6;

//vector< vector<int> > test
//{
//	{1,1,1,0,0,0},
//	{1,1,1,0,0,0},
//	{1,0,0,1,0,0},
//	{0,0,0,0,0,0},
//	{1,1,1,0,0,0},
//	{1,1,1,0,0,0},
//};

//vector< vector<int> > test
//{
//	{1,1,1,1,0},
//	{1,1,0,1,0},
//	{1,1,0,0,0},
//	{0,0,0,0,0},
//};

vector< vector<int> > test
{
	{ 1 },
};


struct point
{
	int x, y, value, visited;
public:
	point(int a, int b, int val) { x = a, y = b; value = val; visited = false; }
};

vector< vector<point> > convert(vector< vector<int> > grid)
{
	vector< vector<point> > grid_points;
	for (int row = 0; row < grid.size(); row++)
	{
		vector<point> row_points;
		for (size_t col = 0; col < grid[row].size(); col++)
		{
			point p(col, row, grid[row][col]);
			row_points.push_back(p);
		}
		grid_points.push_back(row_points);
	}

	return grid_points;
}

int number_of_islands(vector< vector<point> > grid)
{	
	if (grid.empty())
	{
		return 0;
	}
	
	queue<point> unvisited_points;
	int islands = 0;
	int max_row_id = grid.size();
	int max_col_id = grid[0].size();

	for (size_t y = 0; y < max_row_id; y++)
	{
		for (size_t x= 0; x < max_col_id; x++)
		{
			if (grid[y][x].visited == false && grid[y][x].value)
			{
				unvisited_points.push(grid[y][x]);
				islands++;
				while (!unvisited_points.empty())
				{
					point top = unvisited_points.front();
					grid[top.y][top.x].visited = true;

					cout << "Processing point " << top.x << "," << top.y << endl;

					//Top neighbour
					if (top.y > 0 && 
						grid[top.y - 1][top.x].visited == false &&
						grid[top.y - 1][top.x].value == 1) //point NOT in first row
					{
						grid[top.y - 1][top.x].visited = true;
						unvisited_points.push(grid[top.y - 1][top.x]);
					}

					//Right neighbour
					if ((top.x < max_col_id - 1) && 
						(grid[top.y][top.x + 1].visited == false) &&
						(grid[top.y][top.x + 1].value == 1)) //point NOT in last column
					{
						grid[top.y][top.x + 1].visited = true;
						unvisited_points.push(grid[top.y][top.x + 1]);
					}

					//Bottom neighbour
					if ((top.y < max_row_id - 1) && 
						(grid[top.y + 1][top.x].visited == false) &&
						(grid[top.y + 1][top.x].value == 1)) //point NOT in last row
					{
						grid[top.y + 1][top.x].visited = true;
						unvisited_points.push(grid[top.y + 1][top.x]);
					}

					//Left neighbour
					if ((top.x > 0) && 
						(grid[top.y][top.x - 1].visited == false) &&
						(grid[top.y][top.x - 1].value == 1)) //point NOT in first column
					{
						grid[top.y][top.x - 1].visited = true;
						unvisited_points.push(grid[top.y][top.x - 1]);
					}

					unvisited_points.pop();
				}
			}
		}
	}

	return islands;
}

void test_problem_200()
{
	vector< vector<point> > grid = convert(test);
	int islands = number_of_islands(grid);
	cout << "Number of Islands is:" << islands << endl;
}