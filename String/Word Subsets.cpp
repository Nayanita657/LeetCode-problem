https://leetcode.com/problems/unique-paths/

**********************************SOLUTION*****************************

class Solution {
public:
    unordered_map<char, int> actual_count;
    
    
    void helper(string temp)
    {
        unordered_map<char, int> eachWord_count;
        for(int i = 0; i < temp.length(); i++)
        {
            eachWord_count[temp[i]]++;
        }
        
        unordered_map<char, int> :: iterator itr;
        for(itr = eachWord_count.begin(); itr != eachWord_count.end(); itr++)
        {
            auto itr1 = actual_count.find(itr->first);
            if(itr1 != actual_count.end())
            {
                actual_count[itr->first] = max(actual_count[itr->first], itr->second);
            }
            else
                actual_count[itr->first] = itr->second;
        }
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string> result;
        
        for(int i = 0; i < words2.size(); i++)
        {
            string temp = words2[i];
            helper(temp);
        }
        
        string target;
        unordered_map<char, int> :: iterator itr;
        for(itr = actual_count.begin(); itr != actual_count.end(); itr++)
        {
            int count = itr->second;
            for(int k = 1; k <= count; k++)
                target+=itr->first;
        }
        
        for(int i = 0; i < words1.size(); i++)
        {
            string curr = words1[i];
            
            //creating hashtable for this string
            unordered_map<char, int> map;
            for(int k = 0; k < curr.length(); k++)
                map[curr[k]]++;
            
            bool flag = true;
            
            
            
            for(int i = 0; i < target.length(); i++)
            {
                char target_char = target[i];
                auto itr = map.find(target_char);
                if(itr != map.end())
                {
                    map[target_char]--;
                    if(map[target_char] == 0)
                        map.erase(target_char);
                        
                }
                else
                {
                    flag = false;
                    break;
                }
                   
            }
            
            if(flag == true)
                result.push_back(words1[i]);
        }
        return result;
    }
};
