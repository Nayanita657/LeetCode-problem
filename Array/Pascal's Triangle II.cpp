https://leetcode.com/problems/pascals-triangle-ii/

********************************SOLUTION*********************************

vector<int> getRow(int rowIndex) 
    {
        vector<int> result;
        int n = rowIndex + 1;
        int row = rowIndex;
        for(int col = 0; col < n; col++)
        {
            long long int res = 1;
            for(int i = 0; i < col; i++)
            {
                res = res * (row - i);
                res = res / (i + 1);
            }
            result.push_back(res);
        }
        return result;
    }


TC = O(N)
SC = O(1)
