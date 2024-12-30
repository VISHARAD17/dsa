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
    bool checkPrime(int n){
        // add more check to reduce the number of iterations
        if(n == 1) return false;
        if(n == 2 or n == 3) return true;

        if(n % 2 == 0 or n%3 == 0) return false;

        for(int i=5; i*i <= n; i+=6){
            if(n%i == 0 or n%(i+2) == 0) return false;
        }
        return true;
    }

    // time - O(n) linear
    bool naiveCheckForPrime(int n){
        if(n == 1) return false;

        for(int i=2; i<n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

};

int main()
{
    Solution st;
    return 0;
}
