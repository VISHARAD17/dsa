/*
 * span means common subarry with same starting and ending index
 *
 * so, given two binary subArray of same size, find out common span with same sum
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
    /*
     * get temp arr but getting the diff between both arrays, then ans would be the longest subarray of temp with sum 0
     * */
    int longestCommonSpan(vector<int>&arr1, vector<int>&arr2){
        const int n = arr1.size();
        vector<int>tmp(n, 0);
        for(int i=0; i<n; i++) tmp[i] = arr1[i] - arr2[i];

        // longest subarray with sum 0
        int curPrefixSum = 0;
        unordered_map<int, int>hashMap;
        int maxLen  = 0;
        for(int i=0; i<n; i++){
            curPrefixSum += tmp[i];
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
    vector<int>arr1 = {0,1,0,0,0,0}, arr2 = {1,0,1,0,0,1};
    Solution st;
    cout << st.longestCommonSpan(arr1, arr2);
    return 0;
}
