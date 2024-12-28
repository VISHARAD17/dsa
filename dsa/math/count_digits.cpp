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
    /* count number of digits in a number */
    void countDigits(int n){
        int count = 0;

        while(n >= 10){
            count++;
            n /= 10;
        }
        count++;
        cout << "count = " << count;
    }

};

int main()
{
    Solution st;
    st.countDigits(9235);
    return 0;
}
