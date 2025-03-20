/*
 * Palindrome partitioning
 *
 * find out minimumn number of cuts we can make in a string, such that all parts are palindrome
 * */

#include <climits>
#include <iostream>
#include <string>
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
private:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int recursive_minCutsToMakePalindrome(string s, int i, int j){
        if(isPalindrome(s, i, j)) return 0;
        int res = INT_MAX;

        for(int k=i; k<j; k++){
            res = min(res,
                      1 + recursive_minCutsToMakePalindrome(s, i, k)+
                      recursive_minCutsToMakePalindrome(s, k+1, j)
                      );
        }
        return res;
    }

    // time complexity - O(n^3), space - O(n^2)
    int minCutsToMakePalindrome(string s){
        const int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // base case
        for(int i=0; i<n; i++) dp[i][i] = 0;

        for(int gap=1; gap<n; gap++){
            for(int i=0; i+gap<n; i++){
                int j = i+gap;
                if(isPalindrome(s, i, j)) dp[i][j] = 0;
                else{
                    dp[i][j] = INT_MAX;
                    for(int k=i; k<j; k++){
                        dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }

};

int main()
{
    Solution st;
    cout << "expected ans : 2\n";
    cout << "recursive sol: " << st.recursive_minCutsToMakePalindrome("geek", 0, 3) << "\n";
    cout << "DP sol : " << st.minCutsToMakePalindrome("geek") << "\n";
    return 0;
}
