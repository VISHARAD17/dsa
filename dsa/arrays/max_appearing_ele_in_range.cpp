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
    // return the max occuring element in all the given ranges
    // range i to j means array [i...., j]
    // Sol: build a prefix sum for the freq.
    void maxAppearingElementInGiveRange(vector<int>&left, vector<int>&right){
        const int n = left.size(); // or right.size()
        vector<int>frq(101, 0);

        for(int i=0; i<n; i++){
            frq[left[i]]++, frq[right[i]+1]--;
        }

        int res = 0;
        for(int i=1; i<101; i++){
            frq[i] += frq[i-1];
            if(frq[i] > frq[res]){
                res = i;
            }
        }
        cout << "max element in the range : " << res << "\n";
    }
};

int main()
{
    Solution st;
    vector<int> left = {1, 2, 4}, right = {4, 5, 7};
    st.maxAppearingElementInGiveRange(left,right);
    return 0;
}
