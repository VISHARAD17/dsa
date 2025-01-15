// 1475 - final price after discount
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
    vector<int> finalPrices(vector<int>& arr){
        const int n = arr.size(); 
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j] <= arr[i]){
                    ans[i] = arr[i] - arr[j];
                    break;
                }
            }
            if(ans[i] == -1) ans[i] = arr[i];
        }
        return ans;
    }

};

int main()
{
    Solution st;
    return 0;
}
