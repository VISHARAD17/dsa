/*
 * longest subarray with equal ones and zeros
 * */


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    /* treat 1 and 0 as 1 and -1 , and use the prefix sum to get the longest subarray with zero sum*/
    int longestSubArrayWithEqualOnesAndZeros(vector<int>&arr){
        const int n = arr.size();
        int curPrefixSum = 0, maxLen = 0;
        unordered_map<int, int>hashMap;
        for(int i=0; i<n; i++){
            curPrefixSum += (arr[i] ? 1: -1);
            if(curPrefixSum == 0) maxLen = max(maxLen, i+1);
            if(hashMap.find(curPrefixSum) != hashMap.end()){
                int len = abs(i - hashMap[curPrefixSum]);
                maxLen = max(maxLen, len);
            }
            else hashMap[curPrefixSum] = i;
        }
        return maxLen;
    }

};

int main()
{
    vector<int>arr ={1,0,1,1,1,0,0}; // ans : 6
    Solution st;
    cout << st.longestSubArrayWithEqualOnesAndZeros(arr);
    return 0;
}
