https://leetcode.com/problems/kth-largest-element-in-a-stream/

**********************************SOLUTION*****************************************

class KthLargest {
public:
    int global_k;
    //vector<int> global_vec;
    //creating max_heap
    priority_queue<int,vector<int>,greater<int>> p;
    KthLargest(int k, vector<int>& nums) 
    {
        global_k = k;
        //global_vec = nums;
        for(int i = 0; i < nums.size(); i++)
        {
            if(p.empty())
                p.push(nums[i]);
            else
            {
                if(p.size() < k)
                {
                    p.push(nums[i]);
                }
                else if(p.size() == k)
                {
                    if(nums[i] > p.top())
                    {
                        p.pop();
                        p.push(nums[i]);
                    }
                }
            }
        }
    }
    
    int add(int val) 
    {
        if(p.empty())
        {
            p.push(val);
        }
        else
        {
            if(p.size() < global_k)
            {
                p.push(val);
            }
            else if(p.size() == global_k)
            {
                if(val > p.top())
                {
                    p.pop();
                    p.push(val);
                }
            }
        }
        
        return p.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
