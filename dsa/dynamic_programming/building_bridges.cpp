/*
 * Building bridges
 * - Given set of pairs, make bridges between those pairs such that no bridge is crossing each other
 * - variation of LIS
 *
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
private:
    int lis(vector<int>&a){
        const int n = a.size();
        // time - O(n^2), space - O(n)
        vector<int>lis(n);
        lis[0] = 1; // base case 

        for(int i=1; i<n; i++){
            lis[i] = 1;
            for(int j=0; j<i; j++){
                // if strictly increasing then > or if non-decreasing then >=
                if(a[i] > a[j]) lis[i] = max(lis[i], lis[j]+1);
            }
        }
        return *max_element(lis.begin(), lis.end());
    }

public:
    /*
     * SOL:
     * - sort the array of pairs according to the first element, if first element matches the sort according to the last element
     * - then take the LIS of second elements in the sorted array of pairs ( since, its increasing it will ensure no bridge is crossing )
     * */
    int buildBridge(vector<vector<int>> pairs){
        const int n  = pairs.size();
        /*c++ handles by default the case when first element is same*/
        sort(pairs.begin(), pairs.end());

        vector<int>secondEle;
        for(auto &x: pairs) secondEle.push_back(x[1]);
        return lis(secondEle);
    }
};

int main()
{
    Solution st;
    vector<vector<int>> pairs = {{6,2}, {4,3}, {2,6}, {1,3}};
    cout << "expected ans: 2\n";
    cout << "LIS sol: " << st.buildBridge(pairs) << "\n";
    return 0;
}
