/*
 * Count BSTs with N keys
 *
 * BST - Binary search tree 
 * A valid BSt hass ==> all nodes on left of current node should be less and the ones on right should be greater
 *
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
    int countBSTsWithNKeys(int n){
        cout << "total BSTs for n = " << n << " are ";
        vector<int>dp(n+1, 0);
        dp[0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }

};

int main()
{
    Solution st;
    cout << st.countBSTsWithNKeys(3) << "\n";
    cout << st.countBSTsWithNKeys(5) << "\n";
    return 0;
}
