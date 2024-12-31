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
    void checkKthBitSetOrNot(int n, int k){
        cout << "n= " << n << " k= " << k << " ";
        int x = (1 << (k-1)); // this will shift only 1 set bit to the left side k places
        if(n&&x == 1) cout << "yes\n"; // compare that bit with k_th bit of n
        else cout << "no\n";
    }

};

int main()
{
    Solution st;
    st.checkKthBitSetOrNot(5, 1);
    st.checkKthBitSetOrNot(5, 2);
    return 0;
}
