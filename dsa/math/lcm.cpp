#include <iostream>
#include <algorithm>
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
private:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
public:
    /* least common nmultiple for ex. for 4, 6, LCM is 12*/
    int naivLCM(int a, int b){
        cout << "LCM of a=" << a << "and b=" << b << "is ";
        int res = max(a, b);
        while(true){
            if(res%a == 0 and res%b == 0) return res;
            res++;
        }
        return res;

    }
    
    int lcm(int a, int b){
        cout << "optimal LCM of a=" << a << "and b=" << b << "is ";
        return (a*b)/gcd(a, b);
    }

};

int main()
{
    Solution st;
    cout << st.naivLCM(4, 6) << "\n";
    cout << st.lcm(4, 6) << "\n";
    return 0;
}
