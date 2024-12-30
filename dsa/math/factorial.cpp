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
    void factorial(int n){
        cout << "factorial of " << n << "is ";
        if(n <= 1){
            cout << "1\n";
            return;
        }
        long long ans = 1;
        for(int i=2; i<=n; i++) ans *= i;
        cout << ans << "\n";
    }

};

int main()
{
    Solution st;
    st.factorial(1);
    st.factorial(6);
    st.factorial(34);
    return 0;
}
