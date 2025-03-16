/* 
 * Egg dropping puzzel
 * given no of eggs and no of floors find minimum number of trials required to find a threshold floor in worst case
 *
 * threshold floor : dropping and egg from this floor or floors above it will result in egg 
 * breaking but any floors below that will not break egg.
 *
 * */

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
    /* time complexity O(f^2e) and space - O(fe) */
    int eggDrop(int eggs, int floors){
        vector<vector<int>>dp(floors+1, vector<int>(eggs+1, 0));
        // base cases
        // 1. when floor is zero, ans is always 0
        for(int j=1; j<= eggs; j++) dp[0][j] = 0;
        // 2. when floor is 1, ans is always 1
        for(int j=1; j<=eggs; j++) dp[1][j] = 1;
        // 3. when egg is 1, ans is always total floors 
        for(int i=1; i<=floors; i++) dp[i][1] = i;

        for(int i=2; i<=floors; i++){
            for(int j=2; j<=eggs; j++){
                dp[i][j] = INT_MAX;

                for(int x=1; x<=i; x++){
                    //                            egg breaks     egg did not break
                    dp[i][j] = min(dp[i][j], max(dp[x-1][j-1], dp[i-x][j]));
                }
                dp[i][j]++;
            }
        }
        return dp[floors][eggs];
    }

    int recursive_eggDrop(int eggs, int floors){
        if(eggs == 1) return floors;
        if(floors <= 1) return floors;
        int res = floors;
        for(int i=2; i<=floors; i++){
            //            egg breaks, so check floors below    egg did not break, so check floors above 
            res = min(res, max(recursive_eggDrop(eggs-1, i-1), recursive_eggDrop(eggs, floors-i)));
        }
        return res+1;
    }

};

int main()
{
    Solution st;
    int eggs = 2, floors = 10;
    cout << "expected ans : 4\n";
    cout << "recursive sol : " << st.recursive_eggDrop(eggs,floors) << "\n";
    cout << "DP sol : " << st.eggDrop(eggs, floors) << "\n";
    return 0;
}
