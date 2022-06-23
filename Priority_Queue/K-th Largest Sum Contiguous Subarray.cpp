https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1/#

**********************************************SOLUTION****************************************

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        int start = 0;
        int end = 0;
        int sum = 0;
        while(start < Arr.size())
        {
            sum = sum + Arr[end];
            if(end < Arr.size())
            {
                //insert into priority queue
                if(pq.size() < K)
                    pq.push(sum);
                else if(pq.size() == K)
                {
                    if(pq.top() < sum)
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                }
                end++;
            }
            else if(end == Arr.size())
            {
                //
                start++;
                end = start;
                sum = 0;
            }
        }
        return pq.top();
    }
};
