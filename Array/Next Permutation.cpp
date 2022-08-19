https://leetcode.com/problems/next-permutation/

****************************SOLUTION*************************

void nextPermutation(vector<int>& nums) 
    {
        int end = nums.size() - 1;
        bool flag = false;
        while(end != 0)
        {
            if(nums[end] > nums[end - 1])
            {
                flag = true;
                break;
            }
            end--;
        }
        
        if(flag == false)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int swapped_ind = end - 1;
        int min_diff_index;
        int min_diff = INT_MAX;
        while(end < nums.size())
        {
            if(nums[end] > nums[swapped_ind])
            {
                int diff = nums[end] - nums[swapped_ind];
                if(min_diff >= diff)
                {
                    min_diff = diff;
                    min_diff_index = end;
                }
                
            }
            end++;
        }
        
        swap(nums[swapped_ind], nums[min_diff_index]);
        
        reverse(nums.begin() + swapped_ind + 1, nums.end());
    }


TC = O(N)
SC = O(1)
