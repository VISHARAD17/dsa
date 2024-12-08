#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "TwoSum.h"
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

void solve(){
    //code
    vector<int>nums = {1, 2, 3, 4, 5, 6};
    int target = 9;

    Solution ts;
    vector<int>result = ts.twoSum(nums, target);
    for(int &res: result) cout << res << " ";
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--) solve();
    return 0;
}
