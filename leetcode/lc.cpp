#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "special_array_II.hpp"
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

void solve(){
    // inputs
    vector<int>nums = {3, 4, 1, 2, 6};
    vector<vector<int>> q = {{0, 4}};
    //code
    Solution s;
    vector<bool>res = s.isArraySpecial(nums, q);
    for(bool x: res) cout << x << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--) solve();
    return 0;
}
