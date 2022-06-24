https://leetcode.com/problems/rotting-oranges/

********************************************SOLUTION*******************************************

class Solution {
public:
    bool BFS_helper(vector<vector<int>>& grid, int i, int j, int row, int column)
    {
        if(i < 0 || j < 0|| i >= row || j >= column || grid[i][j] != 1)
        {
            return false;
        }
        else
        {
            grid[i][j] = 3;
            return true;
        }
    }
    int BFS(vector<vector<int>>& grid, queue<pair<int,int>> pendingQueue, int row, int column)
    {
        int time = 0;
        while(!pendingQueue.empty())
        {
            pair<int,int> front = pendingQueue.front();
            pendingQueue.pop();
            int val1 = front.first;
            int val2 = front.second;
            if(val1 == -1 && val2 == -1)
            {
                if(!pendingQueue.empty())
                {
                    time++;
                    pair<int,int> temp;
                    temp.first = -1;
                    temp.second = -1;
                    pendingQueue.push(temp);
                }
                else
                    break;
            }
            else
            {
                bool r1 = BFS_helper(grid, val1, val2 - 1, row, column);
                bool r2 = BFS_helper(grid, val1 - 1, val2, row, column);
                bool r3 = BFS_helper(grid, val1, val2 + 1, row, column);
                bool r4 = BFS_helper(grid, val1 + 1, val2, row, column);
                if(r1 || r2 || r3 || r4)
                {
                    if(r1)
                    {
                        pair<int,int> temp;
                        temp.first = val1;
                        temp.second = val2 - 1;
                        pendingQueue.push(temp);
                    }
                    if(r2)
                    {
                        pair<int,int> temp;
                        temp.first = val1 - 1;
                        temp.second = val2;
                        pendingQueue.push(temp);
                    }
                    if(r3)
                    {
                        pair<int,int> temp;
                        temp.first = val1;
                        temp.second = val2 + 1;
                        pendingQueue.push(temp);
                    }
                    if(r4)
                    {
                        pair<int,int> temp;
                        temp.first = val1 + 1;
                        temp.second = val2;
                        pendingQueue.push(temp);
                    }
                }
            }
            
                
        }
        return time;
            
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int column = grid[0].size();
        int total_time_cal = 0;
        queue<pair<int,int>> pendingQueue;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 2)
                {
                    //this mango is rotten so mark it as different color and push it in the queue
                    grid[i][j] = 3;
                    pair<int,int> temp;
                    temp.first = i;
                    temp.second = j;
                    pendingQueue.push(temp);
                }
            }
        }
        pair<int,int> temp;
        temp.first = -1;
        temp.second = -1;
        pendingQueue.push(temp);
        total_time_cal = BFS(grid, pendingQueue, row, column);
        
        //checking the entire grid for fresh orange
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column ; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return total_time_cal;
    }
};
