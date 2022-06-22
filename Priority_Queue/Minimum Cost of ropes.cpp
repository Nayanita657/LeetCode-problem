https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

***********************************************SOLUTION**************************************************

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        // Your code here
        long long result = 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size() > 1)
        {
            //extract first two min length and add them
            long long  val1 = pq.top();
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            result = result + val1 + val2;
            pq.push(val1 + val2);
        }
        return result;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
