https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

*****************************************SOLUTION***************************************

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> p;
        //int ele = 0;
        int size = matrix.size() * matrix.size();
        int temp = size - k + 1;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                int curr_ele = matrix[i][j];
                if(p.size() < temp)
                {
                    p.push(curr_ele);
                }
                else if(p.size() == temp)
                {
                    if(curr_ele > p.top())
                    {
                        p.pop();
                        p.push(curr_ele);
                    }
                }
            }
        }
        return p.top();
    }
};
