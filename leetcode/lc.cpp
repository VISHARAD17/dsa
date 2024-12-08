#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "palindrome.h"
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

void solve(){
    //code
    Solution s;
    cout << s.isPalindrome(121) << "\n" << s.isPalindrome(-121) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    while(t--) solve();
    return 0;
}
