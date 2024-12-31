#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    /* check if given number is power of 2 or not, print yes or no */
    void naiverPowerOfTwo(int n){
        if(n == 0){
            cout << "no\n";
            return;
        } 
        while(n != 1){
            if(n%2 != 0){
                cout << "no\n";
                return;
            }
            n /= 2;
        }
        cout << "yes\n";
    }

    void powerOfTwo(int n){
        // binary represenation has only 1 set bit 
        // ex. 8 - 000...1000, 16-000...10000
        if((n & (n-1)) == 0) cout << "yes\n";
        else cout << "no\n";
    }

};

int main()
{
    Solution st;
    cout << "checking for 8 --\n";
    st.powerOfTwo(8);
    st.naiverPowerOfTwo(8);
    cout << "checking for 6 --\n";
    st.naiverPowerOfTwo(6);
    st.powerOfTwo(6);
    return 0;
}
