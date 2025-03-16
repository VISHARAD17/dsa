/*
 * maximum sum with no two consecutive
 *
 * Given array of positive elements, find maximum sum of elements such that no 2 elements that are contributing to the sum are consecutive
 * */
#include <iostream>
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
    int noTwoConsecutiveSum(vector<int>&arr){
        const int n = arr.size();
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        vector<int>dp(n+1);

        // base cases
        dp[0] = arr[0];
        dp[2] = max(arr[0], arr[1]);

        for(int i=3; i<=n; i++){
            dp[i] = max(dp[i-1], arr[i-1]+dp[i-2]);
        }
        return dp[n];
    }

    // start from the last element and call recursively
    int recursive_noTwoConsecutiveSum(vector<int>&arr, int n){
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);

        return max(
            recursive_noTwoConsecutiveSum(arr, n-1), // --> do not consider the n-1_th element
            recursive_noTwoConsecutiveSum(arr, n-2) + arr[n-1] // --> consider the n-1_th element
        );
    }

};

int main()
{
    vector<int>arr = {10,5,15,20};
    Solution st;
    cout << "expected ans : 30\n";
    cout << "recursive sol : " << st.recursive_noTwoConsecutiveSum(arr, arr.size()) << "\n";
    cout << "DP sol : " << st.noTwoConsecutiveSum(arr) << "\n";
    return 0;
}
