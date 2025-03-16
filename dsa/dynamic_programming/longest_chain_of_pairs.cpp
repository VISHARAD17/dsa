/*
 * Longest chain of pairs:
 * - Given an array of pairs find the longest chain of pairs such that both elements of pairs are greater than the previous pairs' elements
 * - it is given than first ele < second ele in a pair
 * - ex. for {a, b} < {c, d} only if b < c
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
    /*
     * sol: 
     * - sort the array based on the first element
     * - take LIS of second elements ( but keep a check to compare first element of pair with second element of previous pair)
     * */
    int longestChainOfPairs(vector<vector<int>>&pairs){
        const int n = pairs.size();

        // sort based on first element
        sort(pairs.begin(), pairs.end());

        vector<int>lis(n);
        lis[0] = 1;
        for(int i=1; i<n; i++){
            lis[i] = 1;

            for(int j=0; j<i; j++){
                // only change in LIS code apart from sorting part
                // compare the first element of the ith pair with second element of the j_th pair
                if(pairs[i][0] > pairs[j][1]) lis[i] = max(lis[j]+1, lis[i]);
            }
        }
        return *max_element(lis.begin(), lis.end());
    }

};

int main()
{
    Solution st;
    vector<vector<int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << "expected ans: 3\n";
    cout << "LIS sol: " << st.longestChainOfPairs(pairs) << "\n";
    return 0;
}
