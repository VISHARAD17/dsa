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
    // liner time complexity O(n) -> where n is the no. of set bits
    void naiveCountSetBits(int n){
        int res = 0;
        while(n > 0){
            if(n%2 == 1){
                res++;
            }
            n /= 2;
        }
        cout << "set bits using naive method " << res << "\n";
    }
    // liner time complexity O(n) -> where n is the no. of set bits
    void countSetBits(int n){
        int res = 0;
        while(n > 0){
            n = n & (n-1); // this makes last set bit of n as zero
            res++;
        }
        cout << "set bits using imp algo" << res << "\n";
    }

    // constant time complexity
    void countSetBitsImp(int n){
        // assumning 32 bit represenation
        vector<int>countOfSetBits(256, 0); // 255 has all the last 8 bits set in 32 bits representation
        countOfSetBits[0] = 0;
        
        // [ i & (i-1) ] + 1 because that & reduces one set bit
        for(int i=1; i<256; i++) countOfSetBits[i] = countOfSetBits[i & (i-1)] + 1;

        // right shift 8 bits and compare again, all 32 bits are divided into 4 parts
        int ans = countOfSetBits[n & 255] + countOfSetBits[(n >> 8) & 255] + countOfSetBits[(n >> 16) & 255] +
                  countOfSetBits[( n >> 24 )];
        cout << "set bits using constant algo : " << ans << "\n";
    }

};

int main()
{
    Solution st;
    st.countSetBits(5);
    st.naiveCountSetBits(5);
    st.countSetBitsImp(5);
    return 0;
}
