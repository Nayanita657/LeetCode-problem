https://leetcode.com/problems/max-area-of-island/

**************************************SOLUTION************************************

class Solution {
public:
    int BFS(vector<vector<int>>& grid, int i, int j, int row, int column)
    {
        if(i < 0 || i >= row || j < 0 || j >= column || grid[i][j] != 1)
        {
            return 0;
        }
        else
        {
            grid[i][j] = 2;
            int val1 = BFS(grid, i, j - 1, row, column);
            int val2 = BFS(grid, i - 1, j, row, column);
            int val3 = BFS(grid, i, j + 1, row, column);
            int val4 = BFS(grid, i + 1, j, row, column);
            return (1 + val1 + val2 + val3 + val4);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int max_area = INT_MIN;
        int row = grid.size();
        int column = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 1)
                {
                    int val = BFS(grid, i, j, row, column);
                    if(max_area < val)
                        max_area = val;
                }
            }
        }
        if(max_area == INT_MIN)
            return 0;
        else
            return max_area;
    }
};
