https://leetcode.com/problems/last-stone-weight/

**********************************************SOLUTION*************************************

class Solution {
public:
    priority_queue<int> p;
    int lastStoneWeight(vector<int>& stones) 
    {
        for(int i = 0; i < stones.size(); i++)
        {
            p.push(stones[i]);
        }
        while(!p.empty() && p.size() != 1)
        {
            int w1 = p.top();
            p.pop();
            int w2 = p.top();
            p.pop();
            if(w1 != w2)
            {
                p.push(w1 - w2);
            }
        }
        if(p.size() == 0)
            return 0;
        else
            return p.top();
    }
};
