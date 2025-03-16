/*
 * optimal strategy for a game
 *
 * given an even sized array, there are two players who have to pick any the corner elements
 * get the maximum number of coins that I can collect, given that I am playing first ( both players are playing optiamally to win 
 * i.e. trying to maximize there value)
 *
 * ex. coins = {5, 20, 4, 6}
 * 1_st move : P1 picks 6
 * 2_nd move : P2 picks 5
 * 3rd move : P1 picks 20
 * 4th move : P2 picks 4
 * 
 * Hence, O/P : 26
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
    int optimalGame(vector<int>&coins){
        const int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // base case
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = max(coins[i], coins[i+1]);
        }

        // little tricy need to remember
        for(int gap=3; gap<n; gap+=2){
            for(int i=0; i+gap<n; i++){
                int j = i+gap;

                // min of possibilities when we choose the from start and then opponent chooses from either start or end 
                //   opp chose from start   opp choose from end
                int min1 = min(dp[i+2][j], dp[i+1][j-1]);
                // min of possibilities when we choose from end and then opponent chooses from either start or end
                //    opp chose from end     opp choose from start
                int min2 = min(dp[i][j-2], dp[i+1][j-1]);

                dp[i][j] = max(coins[i] + min1, coins[j] + min2);
            }
        }
        return dp[0][n-1];
    }

    /* for each our move, consider the fact that opponent is also playing optimally so he will choose a move 
     * which gives us lower sum
     * */
    int recursive_optimalGame_sol(vector<int>&coins, int start, int end){

        if(start+1 == end) return max(coins[start], coins[end]); // this would be our base case for DP sol

        // opponent choose end coin while we choose start coin
        int opp_end_1 = recursive_optimalGame_sol(coins, start+1, end-1);
        // opponent choose coin after start while we choose start coin
        int opp_start_1 = recursive_optimalGame_sol(coins, start+2, end);
        
        // oppponent chose coins before end coin after we choose end coin  
        int opp_end_2 = recursive_optimalGame_sol(coins, start, end-2);
        // opponent choose coin from start while we chose from end
        int opp_start_2 = recursive_optimalGame_sol(coins, start+1, end-1);
        

        // return max for either conditions
        // 1. chose from start ( here opponent will play optimally to get us min coins)
        int cond_1 = coins[start] + min(opp_start_1, opp_end_1);
        int cond_2 = coins[end] + min(opp_start_2, opp_end_2);


        return max(cond_1, cond_2);
    }

};

int main()
{
    Solution st;
    vector<int>coins{5, 20, 4, 6};
    cout << "recursive solution : " << st.recursive_optimalGame_sol(coins, 0, coins.size()-1) << "\n";
    cout << "DP solution : " << st.optimalGame(coins) << "\n";
    return 0;
}
