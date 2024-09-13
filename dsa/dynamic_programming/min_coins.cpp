/*
 * Minimum no. of coins ( given unlimited supply of coins ) to make a given sum
 *
 * */

#include <algorithm>
#include <climits>
#include<iostream>
#include <vector>
using namespace std;


int minCoins(vector<int> coins, int sum){
    const int n = coins.size();
    vector<int>dp(sum+1, INT_MAX);

    dp[0] = 0;
    
    for(int i=1; i<=sum; i++){
       for(int j=0; j<n; j++){
            // if coin less than sum, then take and see possibilities for remaining sum
            if(coins[j] <= i){
                int sub_res = dp[i-coins[j]];
                // if sub_res is int_max then it is not possible to make sum out of remaning coins
                if(sub_res != INT_MAX) dp[i] = min(dp[i], sub_res+1);
            }
        } 
    }

    return dp[sum];

}


// recursive solution
int recur_minCoins(vector<int>arr, int n, int sum){
    if(sum == 0) return 0;
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] <= sum){
            int sub_res = recur_minCoins(arr, n, sum-arr[i]);
            if(sub_res != INT_MAX) res = min(res, sub_res+1);
        }
    }
    return res;
}

int main(){

    int n, sum;
    cin >> n >> sum;

    vector<int>arr(n);
    for(auto &x: arr) cin >> x;

    cout << "recur_sol : " << recur_minCoins(arr, n, sum) << "\n";
    cout << "DP sol : " << minCoins(arr, sum) << "\n";
    return 0;
}
