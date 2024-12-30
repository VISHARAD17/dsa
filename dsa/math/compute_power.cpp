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
    // given n and x compute x^n
    void computePower(int x, int n){
        /* naive solution would be to multiple x with itself n times time -O(n)*/
        /* time - log(n) and space O(1)*/
        long long res = 1;
        while(n > 0){
            if(n & 1) res *= x;
            x *= x;
            n /= 2;
        }
        cout << res << " ";
    }

};

int main()
{
    Solution st;
    cout << "5^4=";
    st.computePower(5,4);
    return 0;
}
