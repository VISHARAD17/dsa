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
    // nums_i represent the price of stock each day, get the max profit out of it
    // similar problem to get the max diff for arr_j - arr_i while j > i --> this works only when we have
    // to buy only on one day and sell on one day

    /*
     * we can buy and stock on any day and can sell the stock on the upcomming days
     * */

    int naive_buyAndSellStock(vector<int>&nums, int start, int end){
        /*
         *get the max profit between i and j and then recursively call for left of i 
         and right of j
         * */
        
        if(end <= start) return 0;
        
        int profit = 0;

        for(int i=start; i<end; i++){
            for(int j=i+1; j<=end; j++){
                if(nums[j] > nums[i]){
                    int curProfit = nums[j] - nums[i] + naive_buyAndSellStock(nums, start, i) + naive_buyAndSellStock(nums, j, end);
                    profit = max(profit, curProfit);
                }
            }
        }
        return profit;
    }

    int buyAndSellStock(vector<int>&nums){
        const int n = nums.size();
    }
};

int main()
{
    vector<int>nums = {1, 5, 3, 8, 12};
    Solution st;
    cout << "naive sol : " << st.naive_buyAndSellStock(nums, 0, nums.size()-1) << "\n";
    return 0;
}
