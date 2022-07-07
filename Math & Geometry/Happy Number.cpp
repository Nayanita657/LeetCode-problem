https://leetcode.com/problems/happy-number/

*********************************SOLUTION***************************************

class Solution {
public:
    bool isHappy(int n) 
    {
        bool result;
        unordered_map<int, int> map;
        unordered_map<int, int> :: iterator itr;
        while(1)
        {
            string num = to_string(n);
            long long prod = 0;
            for(int i = 0; i < num.length(); i++)
            {
                int val = num[i] - '0';
                prod = prod + pow(val,2);
            }
            if(prod == 1)
            {
                result = true;
                break;
            }
                    
            map[prod]++;
            if(map[prod] > 1)
            {
                result = false;
                break;
            }
            n = prod;
        }
        
        return result;
    }
};
