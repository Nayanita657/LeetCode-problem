https://leetcode.com/problems/rotate-image/


************************************SOLUTION****************************
void rotate(vector<vector<int>>& matrix) 
    {
        int size = matrix.size();
        
        //perform the tranpose of the matrix
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //perform reverse on the each row of the matrix
        for(int i = 0; i < size; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

TC = O(N^2)
SC = O(1)
