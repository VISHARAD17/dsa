// smallest number with set bits
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
    int smallestNumber(int n) {
        int totalBits = log2(n) + 1;
        return (1 << totalBits) - 1;
    }

};

int main()
{
    Solution st;
    cout << st.smallestNumber(5) << "\n";
    cout << st.smallestNumber(10) << "\n";
    cout << st.smallestNumber(3) << "\n";
    return 0;
}
