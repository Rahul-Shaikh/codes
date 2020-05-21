#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> > board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "\t";
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

}

bool isSafe(vector<vector<int> > &board, int x, int y, int n)
{
	int row, col;
	for (col = 0; col < y; col++)
	{
		if (board[x][col]) return false;
	}

	for (row = x, col = y; row >= 0 && col >= 0; row--, col--)
	{
		if (board[row][col]) return false;
	}

	for (row = x, col = y; row < n && col >= 0; row++, col--)
	{
		if (board[row][col]) return false;
	}

	return true;
}

bool solveNQUtil(vector<vector<int> > &board, int col, int n)
{
	if (col >= n) return true; // all queens are placed then

	for (int row = 0; row < n; row++)
	{
		if (isSafe(board, row, col, n))
		{
			board[row][col] = 1;
			if (solveNQUtil(board, col + 1, n)) return true;

			board[row][col] = 0; // Does not have a valid solution so backtracks
		}
	}

	return false;
	
}

void solveNQ(vector<vector<int> > &board, int n)
{
	if (solveNQUtil(board, 0, n) == false)
	{
		cout << "SOLUTION NOT POSSIBLE\n\n";
	}

	printMatrix(board, n);
}

int main(void)
{
	int n = 8;
	vector<vector<int> > board(n, vector<int> (n, 0));

	solveNQ(board, n);
}
