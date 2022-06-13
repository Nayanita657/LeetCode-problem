https://leetcode.com/problems/reorganize-string/

*****************************************SOLUTION*******************************

class Solution {
public:
    string reorganizeString(string s) 
    {
        string result = "";
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); i++)
        {
            map[s[i]]++;
        }
        unordered_map<char,int> :: iterator itr;
        for(itr = map.begin(); itr != map.end(); itr++)
        {
            pair<int,char> temp;
            temp.first = itr->second;
            temp.second = itr->first;
            pq.push(temp);
        }
        int index = 0;
        while(pq.size() > 1)
        {
            pair<int,char> temp = pq.top();
            if(result.length() == 0)
            {
                result+=temp.second;
                index++;
                pq.pop();
                temp.first = temp.first - 1;
                if(temp.first != 0)
                {
                    pq.push(temp);
                }
            }
            else
            {
                if(result[index - 1] == temp.second)
                {
                    //exract the next element from the heap
                    pq.pop();
                    pair<int,char> curr_next_ele = pq.top();
                    pq.pop();
                    result+=curr_next_ele.second;
                    index++;
                    curr_next_ele.first = curr_next_ele.first - 1;
                    if(curr_next_ele.first != 0)
                    {
                        pq.push(curr_next_ele);
                    }
                    pq.push(temp);
                }
                else
                {
                    result+=temp.second;
                    index++;
                    pq.pop();
                    temp.first = temp.first - 1;
                    if(temp.first != 0)
                    {
                        pq.push(temp);
                    }
                }
            }
        }
        if(pq.size() == 1)
        {
            pair<int,char> temp = pq.top();
            if(temp.first > 1 || (result[index - 1] == temp.second))
                result = "";
            else
                result+=temp.second;
        }
        return result;
    }
};
