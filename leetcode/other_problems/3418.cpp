/* 3418.Maximum Amount of Money Robot can Earn */

#include <climits>
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
    // 3D DP problem
    int maximumAmount(vector<vector<int>>& coins){
        const int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        for(int count=0; count<3; count++){
            for(int i=n-1; i>=0; i--){
                for(int j=m-1; j>=0; j--){

                    // base case: bottom right
                    if(i==n-1 and j==m-1){
                        dp[i][j][count] = count > 0 ? max(0, coins[i][j]) : coins[i][j];
                        continue;
                    }

                    int ans = INT_MIN;

                    if(i+1 < n){
                        ans = max(ans, coins[i][j] + dp[i+1][j][count]);
                        if(count > 0) ans = max(ans, dp[i+1][j][count-1]);
                    }

                    if(j+1 < m){
                        ans = max(ans, coins[i][j] + dp[i][j+1][count]);
                        if(count > 0) ans = max(ans, dp[i][j+1][count-1]);
                    }

                    dp[i][j][count] = ans;
                }
            }
        }
        return dp[0][0][2];
    }


};

int main()
{
    vector<vector<int>> coins = {{0,1,-1},{1,-2,3},{2,-3,4}};
    Solution st;
    cout << st.maximumAmount(coins);
    return 0;
}
