/*
 * coin change problem
 * unbounded knapsack problem
 * problem : give a coin array calculate number of ways to pick coins to get given sum, given unlimited supply of each coin
 *
 * ex.
 * sum = 4
 * coins = []  // size 4
 * */


#include <iostream>
#include <vector>
using namespace std;

void coin_change_dp(vector<int> coins, int sum){
    /* sapce and time - O(n x sum)
       dp table ------>
         n\s ----->
         | 0 | 1 | 2 | 3 | 4 | 
       --|---|---|---|---|---|
       0 | 1 | 0 | 0 | 0 | 0 |
       1 | 1 | 1 | 1 | 1 | 1 |
       2 | 1 | 1 | 2 | 2 | 3 |
       3 | 1 | 1 | 2 | 3 | 4 |
         |---|---|---|---|---|
    */

    const int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1));

    for(int i=0; i<=n; i++) dp[i][0] = 1; // base case where sum if zero
    for(int j=1; j<=sum; j++) dp[0][j] = 0; // base case where number of coins to choose from is zero i.e. coins array is empty

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j) dp[i][j] += dp[i][j-coins[i-1]];
        }
    }
    cout << "dp answers :" << dp[n][sum] << "\n";
}

// naive recursive solution
int recur_sol(vector<int> coins,int n, int sum){
    // two actions per coin - take the coin, do not take the coin
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(n == 0) return 0;
    // consider the last coin or do not consider the last coin 
    //1. take the coin hence sum reduced 2. do not take the coin hence number of coins option reduced
    return recur_sol(coins, n, sum-coins[n-1]) + recur_sol(coins, n-1, sum);
}

int main(){
    int n, sum;
    cin >> n >> sum;
    vector<int>coins(n);
    for(auto &x: coins) cin >> x;
    cout << n << " " << sum << " " << "\n";
    for(auto x: coins) cout << x << " ";
    // answer : 2
    cout << "recursive solution : " << recur_sol(coins, n, sum);
    return 0;
}
