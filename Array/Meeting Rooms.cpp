/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval a, Interval b)
    {
        if(a.start == b.start)
            return a.end < b.end;
        else
            return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval> &intervals) 
    {
        if(intervals.size() <= 1)
            return true;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start >= intervals[i - 1].end)
                continue;
            else
                return false;
            
        }
        return true;
    }
};
