https://leetcode.com/problems/valid-palindrome/

******************************************SOLUTION*******************************************

class Solution {
public:
    bool helper(string temp)
    {
        int start = 0;
        int end = temp.length() - 1;
        bool result;
        while(start < end)
        {
            if(temp[start] == temp[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) 
    {
        string temp;
       
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 65 && s[i] <= 90)
            {
                
                temp += tolower(s[i]);
                
            }
            else if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
            {
                
                temp += s[i];
                
            }
            
        }
        
        return helper(temp);
    }
};
