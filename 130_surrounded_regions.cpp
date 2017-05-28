#include "stdafx.h"
#include "common_driver.h"
#include "common_utils.h"


void print2D_c(vector<vector<char> > data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}
void print2D_b(const vector<vector<bool>>& data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& flag)
{
	/*
	Return if
	1. There is an X in location (x,y)
	2. There is an O in location(x, y), but we have already visited this location
	*/
	if (board[y][x] == 'X' || (board[y][x] == 'O' && flag[y][x]))
	{
		return;
	}

	int max_row_id = board.size();
	int max_col_id = board[0].size();
	
	queue < pair<int, int> > points; //A queue to hold unexamined nodes
	points.push(make_pair(x, y)); //Push the current point
	
	while (!points.empty())
	{
		pair<int, int> new_point = points.front(); //Get the point at the head of the queue
		flag[new_point.second][new_point.first] = true; //Mark the new point as visited

		//new_point.first	--> x --> column
		//new_point.second	--> y --> row
		
		//Check for all 4 neighbours

		//Add Top
		if (new_point.second > 0 &&
			board[new_point.second - 1][new_point.first] == 'O' &&
			flag[new_point.second - 1][new_point.first] == false)
		{
			points.push(make_pair(new_point.first, new_point.second - 1));
			flag[new_point.second - 1][new_point.first] = true;
		}

		//Add Right
		if (new_point.first < (max_col_id - 1) &&
			board[new_point.second][new_point.first + 1] == 'O' &&
			flag[new_point.second][new_point.first + 1] == false)
		{
			points.push(make_pair(new_point.first + 1, new_point.second));
			flag[new_point.second][new_point.first + 1] = true;
		}

		//Add Bottom
		if (new_point.second < (max_row_id - 1) &&
			board[new_point.second + 1][new_point.first] == 'O' &&
			flag[new_point.second + 1][new_point.first] == false)
		{
			points.push(make_pair(new_point.first, new_point.second + 1));
			flag[new_point.second + 1][new_point.first] = true;
		}

		//Add Left
		if (new_point.second > 0 &&
			board[new_point.second][new_point.first - 1] == 'O' &&
			flag[new_point.second][new_point.first - 1] == false)
		{
			points.push(make_pair(new_point.first - 1, new_point.second));
			flag[new_point.second][new_point.first - 1] = true;
		}

		points.pop(); //Remove the point which we have just examined
	}
}

void solve(vector<vector<char>>& board) 
{
	//Return if empty board is given
	if (board.empty())
	{
		return;
	}

	//Create a 2D array of flags to mark visited locations
	vector<bool> t(board[0].size(), false);
	vector< vector<bool> > flag(board.size(), t);

	//We only need to loop the nodes in the outer edges of the board
	//i.e first row, last row, first column, last column

	//First row
	//Mark all O's as visted which are connected to any node in the first row
	for (size_t i = 0; i < board[0].size(); i++)
	{
		dfs(i, 0, board, flag);
	}

	//Last row
	//Mark all O's as visted which are connected to any node in the last row
	for (size_t i = 0; i < board[0].size(); i++)
	{
		dfs(i, board.size() - 1, board, flag);
	}

	//First column
	//Mark all O's as visted which are connected to any node in the first column
	for (size_t i = 0; i < board.size(); i++)
	{
		dfs(0, i, board, flag);
	}

	//Last column
	//Mark all O's as visted which are connected to any node in the last column
	for (size_t i = 0; i < board.size(); i++)
	{
		dfs(board[i].size() - 1, i, board, flag);
	}

	//Now, loop through the flag array and for every unvisited location, force it into X
	for (size_t row = 0; row < flag.size(); row++)
	{
		for (size_t col = 0; col < flag[row].size(); col++)
		{
			board[row][col] = flag[row][col] ? 'O' : 'X';
		}
	}
}


//vector< vector<char> > test
//{
//	{	
//		{'O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
//		{'X','X','X','X','X','X','X','X','X','X','O','O','O','X','X','X','X','X','X','X'},
//		{'X','X','X','X','X','X','O','O','O','X','O','X','O','X','X','X','X','X','X','X'},
//		{'X','X','X','X','X','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X'},
//		{'X','X','X','X','X','X','O','X','O','O','O','X','X','X','X','X','X','X','X','X'},
//		{'X','X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X'},
//	}
//};
vector< vector<char> > test
{
	{
		{ 'O','O','O','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{ 'X','X','X','X','X','X','X','X','X','X','O','O','O','X','X','X'},
		{ 'X','X','X','X','X','X','O','O','O','X','O','X','O','X','X','X'},
		{ 'X','X','X','X','X','X','O','X','O','X','O','X','O','O','O','X'},
		{ 'X','X','X','X','X','X','O','X','O','O','O','X','X','X','X','X'},
		{ 'X','X','X','X','X','X','O','X','X','X','X','X','X','X','X','X'},
	}
};

//vector< vector<char> > test
//{
//	{'O','O','X','X'},
//	{'X','X','O','X'},
//	{'X','X','X','X'},
//};

void test_problem_130()
{
	print2D_c(test);
	solve(test);
	print2D_c(test);
	cout << "Solved";
}