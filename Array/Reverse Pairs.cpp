https://leetcode.com/problems/reverse-pairs/

*******************************SOLUTION********************************


int count = 0;
    void merging(vector<int>& part1, vector<int>& part2, vector<int>& nums)
    {
        int k = 0;
        int i = 0;
        int j = 0;
        
        
        //doing calculation part
        int ans = 0;
        
        for(int i = 0; i < part1.size(); i++)
        {
            while(j < part2.size())
            {
                if(part1[i] > (2 * (long long)part2[j]))
                    j++;
                else
                    break;
            }
            ans = ans + (j - 0);
        }
        
        
        i = 0;
        j = 0;
        while(i < part1.size() && j < part2.size())
        {
            if(part1[i] <= part2[j])
            {
                nums[k] = part1[i];
                i++;
                k++;
            }
            else
            {
                nums[k] =part2[j];
                j++;
                k++;
            }
        }
        
        while(i < part1.size())
        {
            nums[k] = part1[i];
            i++;
            k++;
        }
        
        while(j < part2.size())
        {
            nums[k] = part2[j];
            j++;
            k++;
        }
        
        count = count + ans;
        
    }
    
    void helper(vector<int>& nums)
    {
        if(nums.size() <= 1)
            return;
        
        vector<int> part1;
        vector<int> part2;
        
        int mid = nums.size() / 2;
        int size1 = mid;
        int size2 = nums.size() - mid;
        
        for(int i = 0; i < size1; i++)
        {
            part1.push_back(nums[i]);
        }
        
        for(int j = size1; j < nums.size(); j++)
        {
            part2.push_back(nums[j]);
        }
        
        helper(part1);
        helper(part2);
        merging(part1, part2, nums);
    }
    
    int reversePairs(vector<int>& nums) 
    {
        helper(nums);
        return count;
    }
