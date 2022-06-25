https://leetcode.com/problems/surrounded-regions/

*************************************************SOLUTION*********************************************

class Solution {
public:
     
    void DFS(vector<vector<char>>& grid, int i, int j, int row, int column)
    {
        if(i < 0 || j < 0 || i >= row || j >= column || grid[i][j] != 'O')
            return;
        else
        {
            grid[i][j] = 'Y';
            DFS(grid, i - 1, j, row, column);
            DFS(grid, i, j - 1, row, column);
            DFS(grid, i + 1, j, row, column);
            DFS(grid, i, j + 1, row, column);
        }
    }
    void solve(vector<vector<char>>& grid) 
    {
        
        int row = grid.size();
        int column = grid[0].size();
        //border wise DFS application
        for(int i = 0; i < column; i++) 
        {
            if(grid[0][i] == 'O') // top horizental left to right
            {
                //apply DFS in 4 dimentional way
                DFS(grid, 0, i, row, column);
            }
            if(grid[row - 1][i] == 'O') //buttom horizental left to right
            {
                DFS(grid, row - 1, i, row, column);
            }
   
        }
        for(int i = 0; i < row; i++) 
        {
            if(grid[i][0] == 'O') //left side top to buttom
            {
                //apply DFS in 4 dimentional way
                DFS(grid, i, 0, row, column);
            }
                     
            
            if(grid[i][column - 1] == 'O') //right side top to buttom
            {
                DFS(grid, i, column - 1, row, column);
            }
          
        }
             
       
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 'Y')
                {
                    grid[i][j] = 'O';
                    continue;
                }
                if(grid[i][j] == 'O')
                    grid[i][j] = 'X';
            }
        }
       
    }
};
