https://leetcode.com/problems/number-of-islands/

**************************************SOLUTION*************************************

class Solution {
public:
    void BFS(vector<vector<char>>& grid,int i, int j, int row,int column)
    {
        if(i < 0 || j < 0 || i >= row || j >= column || grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        BFS(grid, i, j-1, row, column);
        BFS(grid, i - 1, j, row, column);
        BFS(grid, i, j + 1, row, column);
        BFS(grid, i + 1, j, row, column);
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int column = grid[0].size();
        int num_of_islands = 0;
        if(row == 0)
            return 0;
        else
        {
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)
                {
                    if(grid[i][j] == '1')
                    {
                        BFS(grid,i,j,row,column);
                        num_of_islands++;
                    }
                }
            }
        }
        return num_of_islands;
    }
};
