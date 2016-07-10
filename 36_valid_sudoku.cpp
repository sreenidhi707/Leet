
#include "36_valid_sudoku.h"

bool is_array_valid(vector<char> arr)
{
	int count[9];
	memset(count, 0, sizeof(count));

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] != '.')
		{
			if (count[arr[i] - '0'])
			{
				return false;
			}
			count[arr[i] - '0']++;
		}
	}
	return true;
}

vector<char> get_column_vector(vector<vector<char>>& board, int col)
{
	int board_size = board[0].size();

	vector<char> temp;
	for (size_t i = 0; i < board_size; i++)
	{
		temp.push_back(board[i][i*board_size + col]);
	}

	return temp;
}

vector<char> get_square_vector(vector<vector<char>>& board, int id)
{
	int board_size = board[0].size();

	vector<char> temp;
	int start_row = 0;
	int start_col = 0;
	switch (id)
	{
	case 0:
		start_row = 0;
		start_col = 0;
		break;
	case 1:
		start_row = 0;
		start_col = 3;
		break;
	case 2:
		start_row = 0;
		start_col = 6;
		break;
	case 3:
		start_row = 3;
		start_col = 0;
		break;
	case 4:
		start_row = 3;
		start_col = 3;
		break;
	case 5:
		start_row = 3;
		start_col = 6;
		break;
	case 6:
		start_row = 6;
		start_col = 0;
		break;
	case 7:
		start_row = 6;
		start_col = 3;
		break;
	case 8:
		start_row = 6;
		start_col = 6;
		break;
	default:
		break;
	}

	temp.push_back(board[start_row + 0][start_col + 0]); 
	temp.push_back(board[start_row + 0][start_col + 1]); 
	temp.push_back(board[start_row + 0][start_col + 2]);
	
	temp.push_back(board[start_row + 1][start_col + 0]); 
	temp.push_back(board[start_row + 1][start_col + 1]); 
	temp.push_back(board[start_row + 1][start_col + 2]);
	
	temp.push_back(board[start_row + 2][start_col + 0]); 
	temp.push_back(board[start_row + 2][start_col + 1]); 
	temp.push_back(board[start_row + 2][start_col + 2]);

	return temp;
}

bool is_valid_soduku(vector<vector<char>>& board)
{
	int board_size = board[0].size();

	//Check if rows are valid
	for (size_t i = 0; i < board_size; i++)
	{
		if (!is_array_valid(board.at(i)))
		{
			return false;
		}
	}

	//Check if columns are valid
	for (size_t i = 0; i < board_size; i++)
	{
		//Create column vector
		vector<char> col = get_column_vector(board, i);
		if (!is_array_valid(col))
		{
			return false;
		}
	}

	//Check if squares are valid
	for (size_t i = 0; i < board_size; i++)
	{
		//Create square vector
		vector<char> col = get_square_vector(board, i);
		if (!is_array_valid(col))
		{
			return false;
		}
	}

	return true;
}