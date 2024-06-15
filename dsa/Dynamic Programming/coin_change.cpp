/*
 * unbounded knapsack problem
 * coin change problem
 * problem : give a coin array calculate number of ways to pick coins to get given sum, given unlimited supply of each coin
 * */


#include <iostream>
#include <vector>
using namespace std;


void coin_change_dp(vector<int> coins, int sum){
    const int n = coins.size();
    //  4    4   4   4
    // | 1 | 2 | 3 | 4 |
    // | 3 | 4 | 5 | 7 |
    // | 2 | 4 | 5 | 6 |
    

}

int recur_sol(vector<int> coins,int n, int sum){
    // two actions per coin - take the coin, do not take the coin
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(n == 0) return 0;
    // consider the last coin or do not consider the last coin 
    //1. take the coin hence sum reduced 2. do not take the coin hence number of coins reduced
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
