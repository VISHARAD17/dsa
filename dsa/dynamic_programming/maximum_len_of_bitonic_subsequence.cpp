/*
 * Maximum length of bitonic subsequence\
 * - Variation of LIS problem
 * - bitonic subsequence is a subsequence which first increases and then decreases 
 * - increasing part or decreasing part of this subsequence can be empty 
 * - means an only increasing or only decreasing subsequence can be considered as bitonic
 * - hence for both increasing and decreasing array ans would be the size of the array ( given no negative elements )
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
private:
    /*
     * here, instead of returning max LIS, return LIS array
     * */
    // time - O(n^2), space - O(n)
    vector<int> LIS(vector<int>&a){
        const int n = a.size();
        vector<int>lis(n);
        lis[0] = 1; // base case 

        for(int i=1; i<n; i++){
            lis[i] = 1;
            for(int j=0; j<i; j++){
                // if strictly increasing then > or if non-decreasing then >=
                if(a[i] > a[j]) lis[i] = max(lis[i], lis[j]+1);
            }
        }

        return lis;
    }
public:
    /*
     * idea is to find the LIS of arr and reverse arr and get the max (sum of LIS of both arr - 1)
     * subtracking 1, i_th element would be considered twice while adding both LIS
     * */
    int maxLenOfBitonicSubseq(vector<int>&arr){
        vector<int>revArr = arr;
        reverse(revArr.begin(), revArr.end());

        vector<int>lisArr = LIS(arr);
        vector<int>lisRevArr = LIS(revArr);

        int res = INT_MIN;
        for(int i=0; i<arr.size(); i++) res = max(res, lisArr[i]+lisRevArr[i]-1);
        return res;
    }

};

int main()
{
    Solution st;
    vector<int>arr = {1,11,2,10,4,5,2,1};
    cout << "expected ans: 6\n";
    cout << "LIS sol: " << st.maxLenOfBitonicSubseq(arr) << "\n";
    return 0;
}
