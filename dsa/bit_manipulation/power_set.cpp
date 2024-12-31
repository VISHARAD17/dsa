#include <iostream>
#include <string>
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
    /* print the power power set 
     * ex. "abc" power set  = {"", "a", "b", "c", "ab", "ac", "bc", "abc"}*/
    void powerSet(string s){
        const int n = s.size();
        int powerSetSize = (1 << n); // 2^n

        for(int i=0; i<powerSetSize; i++){
            for(int j=0; j<n; j++){
                // when j_th bit is set
                if((i & (1<<j)) != 0) cout << s[j];
            }
            cout << " ,";
        }
        cout << "\n";
    }

};

int main()
{
    Solution st;
    st.powerSet("abc");
    return 0;
}
