https://leetcode.com/problems/sort-characters-by-frequency/

*************************************SOLUTION*************************************

class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); i++)
        {
            map[s[i]]++;
        }
        string result = "";
        unordered_map<char,int> :: iterator itr;
        priority_queue<pair<int,char>> pq;
        for(itr = map.begin(); itr != map.end(); itr++)
        {
            pair<int,char> temp;
            temp.first = itr->second;
            temp.second = itr->first;
            pq.push(temp);
        }
        while(!pq.empty())
        {
            pair<int,char> temp = pq.top();
            int frequency = temp.first;
            for(int i = 0; i <frequency; i++)
            {
                result+=temp.second; 
            }
            pq.pop();
        }
        return result;
        
    }
};
