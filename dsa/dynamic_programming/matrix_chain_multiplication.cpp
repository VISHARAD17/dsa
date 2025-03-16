/*
 * matrix chain multiplication
 *
 * A[3 x 4] * B[4 x 5] = C[3 x 5]
 * Note: here columns of A has to match with rows of B
 * total no of multiplications = 4 * 3 * 5
 *
 *
 * Given array of elements, find of minimum number of element multiplications required to multiply all the matrices
 *
 *
 * arr = {1, 2, 3, 4} --> array
 *
 * then, m1 = 1 x 2, m2 = 2 x 3, m3 = 3 x 4
 *
 * min no of multiplications in m1 * m2 * m3, we can ,multiply in any order m1*(m2*m3) / (m1*m2)*m3
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
    int recursiveMultiplication(vector<int>&arr, int i, int j){
        if(i+1 == j) return 0; // only one matrix
        int res = INT_MAX;

        for(int k=i+1; k<j; k++){
            res = min(res, 
                    recursiveMultiplication(arr, i, k) +
                    recursiveMultiplication(arr, k, j) +
                    arr[i] * arr[j] * arr[k]
                    );
        }
        return res;
    }
    int matrixMultiplication(vector<int>&arr){
        const int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // base case 
        for(int i=0; i<n-1; i++) dp[i][i+1] = 0;

        for(int gap=2; gap<n; gap++){
            for(int i=0; i+gap<n; i++){
                int j = i+gap;

                dp[i][j] = INT_MAX;

                for(int k=i+1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k]);
                }
            }
        }
        return dp[0][n-1];
    }


};

int main()
{
    vector<int>arr = {20, 10, 30, 40};
    Solution st;
    cout << "expected solution : \n";
    cout << "recursive sol: " << st.recursiveMultiplication(arr, 0, arr.size()-1) << "\n";
    cout << "DP sol : " << st.matrixMultiplication(arr) << "\n";
    return 0;
}
