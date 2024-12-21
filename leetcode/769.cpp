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
    int maxChunksToSorted(vector<int>& arr){
        const int n = arr.size();
        vector<int>prefixMax = arr;
        vector<int>suffixMax = arr;

        for(int i=1; i<n; i++) prefixMax[i] = max(prefixMax[i-1], prefixMax[i]);
        
        for(int i=n-2; i>=0; i--) suffixMax[i] = min(suffixMax[i+1], suffixMax[i]);

        int chunks = 0;
        for(int i=0; i<n; i++){
            if(i == 0 or suffixMax[i] > prefixMax[i-1]) chunks++;
        }
        return chunks;
    }

};

int main()
{
    Solution st;
    vector<int>nums= {4,3,2,1,0};
    cout << st.maxChunksToSorted(nums);
    return 0;
}
