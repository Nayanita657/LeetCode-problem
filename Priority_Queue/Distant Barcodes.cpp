https://leetcode.com/problems/distant-barcodes/

****************************************SOLUTION***************************************

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < barcodes.size(); i++)
        {
            map[barcodes[i]]++;
        }
        unordered_map<int,int> :: iterator itr;
        for(itr = map.begin(); itr != map.end(); itr++)
        {
            pair<int,int> temp;
            temp.first = itr->second;
            temp.second = itr->first;
            pq.push(temp);
        }
        vector<int> result;
        int index = 0;
        while(pq.size() != 0)
        {
            pair<int,int> temp = pq.top();
            if(result.size() == 0)
            {
                pq.pop();
                result.push_back(temp.second);
                index++;
                temp.first = temp.first - 1;
                if(temp.first != 0)
                    pq.push(temp);
            }
            else
            {
                if(result[index - 1] == temp.second)
                {
                    //removing the current element
                    pq.pop();
                    pair<int,int> curr_next_ele = pq.top();
                    pq.pop();
                    result.push_back(curr_next_ele.second);
                    index++;
                    curr_next_ele.first = curr_next_ele.first - 1;
                    if(curr_next_ele.first != 0)
                        pq.push(curr_next_ele);
                    pq.push(temp);
                }
                else
                {
                    pq.pop();
                    result.push_back(temp.second);
                    index++;
                    temp.first = temp.first - 1;
                    if(temp.first != 0)
                        pq.push(temp);
                }
            }
        }
        return result;
    }
};
