https://leetcode.com/problems/letter-case-permutation/

***********************************SOLUTION************************************************

class Solution {
public:
    vector<string> result;
    
    void helper(string str, vector<string>& output)
    {
        if(str.length() == 0)
        {
            string str;
            for(int i = 0; i < output.size(); i++)
            {
                str+=output[i];
            }
            result.push_back(str);
            return;
        }
        else
        {
            char ch = str[0];
            if(str[0] >= 48 && str[0] <= 57)
            {
                //this is number
                //no need to do upper or lower case
                int c = ch - '0';
                output.push_back(to_string(c));
                helper(str.substr(1), output);
                output.pop_back();
            }
            else
            {
                //make to lowercase
                char c = tolower(ch);
                string t1;
                t1+=c;
                output.push_back(t1);
                helper(str.substr(1), output);
                output.pop_back();
                t1 = "";
                
                
                //make to upper case
                c = toupper(ch);
                t1+=c;
                output.push_back(t1);
                helper(str.substr(1), output);
                output.pop_back();
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> output;
        helper(s, output);
        return result;
    }
};
