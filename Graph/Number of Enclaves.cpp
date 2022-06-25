https://leetcode.com/problems/number-of-enclaves/

**************************************SOLUTION************************************************

class Solution {
public:
    
    void DFS(vector<vector<int>>& grid, int i, int j, int row, int column)
    {
        if(i < 0 || j < 0 || i >= row || j >= column || grid[i][j] != 1)
            return;
        else
        {
            grid[i][j] = 0;
            DFS(grid, i - 1, j, row, column);
            DFS(grid, i, j - 1, row, column);
            DFS(grid, i + 1, j, row, column);
            DFS(grid, i, j + 1, row, column);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        
        int row = grid.size();
        int column = grid[0].size();
        //border wise DFS application
        for(int i = 0; i < column; i++) 
        {
            if(grid[0][i] == 1) // top horizental left to right
            {
                //apply DFS in 4 dimentional way
                DFS(grid, 0, i, row, column);
            }
            if(grid[row - 1][i] == 1) //buttom horizental left to right
            {
                DFS(grid, row - 1, i, row, column);
            }
   
        }
        for(int i = 0; i < row; i++) 
        {
            if(grid[i][0] == 1) //left side top to buttom
            {
                //apply DFS in 4 dimentional way
                DFS(grid, i, 0, row, column);
            }
                     
            
            if(grid[i][column - 1] == 1) //right side top to buttom
            {
                DFS(grid, i, column - 1, row, column);
            }
          
        }
             
        int count_one = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 1)
                    count_one++;
            }
        }
        return count_one;
        
       
    }
};
