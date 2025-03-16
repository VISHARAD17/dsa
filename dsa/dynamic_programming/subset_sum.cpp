/*
 * Subset sum problem
 *
 * for given array of elements and sum, find out number of subsets of the array with given sum
 * if no such subsets return 0
 * */

#include <iostream>
#include <vector>
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
    int countSubsets(vector<int>&arr, int sum){
        const int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j]; // condition when to do take the element for sum
                // if ele is less than or equal to sum then take it
                if(j-arr[i-1] >= 0) dp[i][j] += dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }

    int recursive_countOfSubsets(vector<int>&arr, int n, int sum){
        if(n < 0) return 0;
        if(n == 0) return (sum == 0 ? 1 : 0);
        return recursive_countOfSubsets(arr, n-1, sum) + recursive_countOfSubsets(arr, n-1, sum-arr[n-1]);
    }
};

int main()
{
    Solution st;
    vector<int>arr = {10, 5, 2, 3, 6};
    cout << "expected ans : 2\n";
    cout << "recursive sol : " << st.recursive_countOfSubsets(arr, arr.size(), 8) << "\n";
    cout << "DP sol : " << st.countSubsets(arr, 8) << "\n";
    return 0;
}
