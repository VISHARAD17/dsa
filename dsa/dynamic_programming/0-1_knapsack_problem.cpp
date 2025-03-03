/*
 * given, weight and value array where for i_th item has weight[i] and val[i]
 * we are given a max. possible capacity of the bag i.e. w
 *
 * we need to maximize the value of items in the bag without execeeding the max. capacity of the bag
 * [ Note : 0-1 knapsack means we have limited supply of items, either take the item or do not take the item]
 *
 * ex. 
 * I/P -> val = [10, 40, 30, 50] , weight = [5, 4, 6, 3] w = 10
 * O/P -> 90
 *
 * */


#include<iostream>
#include <vector>
using namespace std;

/*
 * time complexity : O(n x w)
 * space : O(n x w)
 * */

int knapsack_01_dp(vector<int> &weights, vector<int>&val, int n, int w){
    /*
     *
        
        dp[n+1][w+1] where dp[i][j] -> maximum val that we can collect with first i items and with capacity j

   n\w  0 | 1 | 2 | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
      |---|---|---|----|----|----|----|----|----|----|----|
    0 | 0 | 0 | 0 | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  |
    1 | 0 | 0 | 0 | 0  | 0  | 10 | 10 | 10 | 10 | 10 | 10 |
    2 | 0 | 0 | 0 | 0  | 40 | 40 | 40 | 40 | 40 | 50 | 50 |
    3 | 0 | 0 | 0 | 0  | 40 | 40 | 40 | 40 | 40 | 50 | 70 |
    4 | 0 | 0 | 0 | 50 | 50 | 50 | 50 | 90 | 90 | 90 | 90 |

     * */

    vector<vector<int>> dp(n+1, vector<int>(w+1)); // dp[n+1][w+1]
    // base case 1: for n=0 i.e. for no item in the array solution is zero (first row)
    for(int i=0; i<=w; i++) dp[0][i] = 0;
    // base case 2: for 0 capacity solution is zero (first col)
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){

            // current capacity j is less than the item's weight, then just simply ignore the item
            if(j < weights[i-1]) dp[i][j] = dp[i-1][j];
            else{
                // take max of both cases : (take the item or do not take the item)
                //           do not take the item       take the item
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-weights[i-1]]);
            }
        }
    }
    return dp[n][w];
}
/*
 * time complexity : T(n) = 2T(n-1) + O(1)
 *                  O(2^n)
 * */
int knapsack_01_recursive(vector<int> &weights, vector<int> &val, int n, int w){
    // base case : if no item left in the array or capacity becomes zero
    if(n == 0 or w == 0) return 0;

    // if weight of the item is more than the capacity simply ignore the item
    if(weights[n-1] > w) return knapsack_01_recursive(weights, val, n-1, w);
    else{
        /* return max between the cases where ( take the item or do not take the item)
        *                             do not take the item                                     take the itesm so reduce the capacity */
        return max(knapsack_01_recursive(weights, val, n-1, w), val[n-1] + knapsack_01_recursive(weights, val, n-1, w-weights[n-1]));
    }
}

int main(){
    int w, n;
    cin >> w >> n;
    vector<int>weights(n), val(n);
    for(int &x: weights) cin >> x;
    for(int &x: val) cin >> x;
   
    // solutions 
    cout << "0-1 knapsack problem : \n";
    cout << "DP solution : " << knapsack_01_dp(weights, val, n, w) << "\n";
    cout << "recursive solution : " << knapsack_01_recursive(weights, val, n, w) << "\n";

    return 0;
}


