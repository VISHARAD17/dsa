#include <iostream>
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
    /* count trailing zeros in a factorial of a number */
    void trailingZeros(int n){
        /* naive solution would be to calculate the factorial then keep counting how many times 
         * the factorial is divisible by 10*/
        // using math  - count the 5 and multiples of 5
        /*
         * trailing zeros = [n/5] + [n/25] + [n/125] + ....
         * */

        int ans = 0;
        for(int i=5; i<=n; i*=5){
            ans += n/i;
        }
        cout << ans << "\n";
    }

};

int main()
{
    Solution st;
    return 0;
}
