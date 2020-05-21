// O(ROW*COL)

#include <iostream>

#define COL 5
#define ROW 5

using namespace std;

bool canInclude(int I[][COL], int row, int col, bool visited[][COL])
{
    return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (!visited[row][col] && I[row][col]));
}

void DFS(int I[][COL], int row, int col, bool visited[][COL])
{
    static int rowTerm[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colTerm[] = {1, 0, -1, 1, -1, 1, 0, -1};

    visited[row][col] = true;

    for (int i = 0; i < 8; i++)
    {
        if (canInclude(I,row + rowTerm[i], col + colTerm[i], visited))
        {
            DFS(I, row + rowTerm[i], col + colTerm[i], visited);
        }
    }
}

int countIslands(int I[][COL])
{
    int count = 0;
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < ROW; i++)
    {
        for (int i1 = 0; i1 < COL; i1++)
        {
            if (!visited[i][i1] && I[i][i1])
            {
                DFS(I, i, i1, visited);
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                    { 0, 1, 0, 0, 1 }, 
                    { 1, 0, 0, 1, 1 }, 
                    { 0, 0, 0, 1, 0 }, 
                    { 1, 0, 1, 0, 1 } }; 

    cout << "Number of islands is: " << countIslands(M) << endl; 
    return 0; 
}