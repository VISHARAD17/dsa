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
    int getSumOfDigits(int num){
        int ans = 0;
        while(num != 0){
            int rem = num%10;
            num /= 10;
            ans += rem;
        }
        return ans;
    }

};

int main()
{
    Solution st;
    cout << st.getSumOfDigits(10) << "\n";
    cout << st.getSumOfDigits(111) << "\n";
    return 0;
}
