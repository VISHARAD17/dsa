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
    void printDivisors(int n){
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                cout << i << " ";
                // if condition to avoid priting i two times incase n is a square
                if(i != n/i) cout << n/i << " ";
            }
        }
        cout << "\n";
    }

};

int main()
{
    Solution st;
    cout << "all divisors of 25 : ";
    st.printDivisors(25);
    return 0;
}
