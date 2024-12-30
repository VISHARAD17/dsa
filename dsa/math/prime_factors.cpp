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
private:
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

public:
    void naivePrimeFactors(int n){
        // time complexity O(n^2 * long n)
        if(n == 1){
            cout << "1\n";
            return;
        }
        // time - O(n)
        for(int i=2; i<n; i++){
            // linear complexity
            if(checkPrime(i)){
                int x = i;
                // log n at worst
                while(n%x == 0){
                    cout << i << " ";
                    x *= i;
                }
            }
        }
    }

    void primeFactorsEfficientSol(int n){
        if(n <= 1) return;

        for(int i=2; i*i<=n; i++){
            while(n%i == 0){
                cout << i << " ";
                n /= i;
            }
        }
        if(n > 1) cout << n << "\n";
        else cout << "\n";
    }

    void mostOptimizedPrimeFactors(int n){
        if(n <= 1) return;

        if(n%2 == 0){
            while(n%2 == 0){
                cout << "2 ";
                n /= 2;
            }
        }
        if(n%3 == 0){
            while(n%3 == 0){
                cout << "3 ";
                n /= 3;
            }
        }

        for(int i=5; i*i<=n; i++){
            while(n%i == 0){
                cout << i << " ";
                n /= i;
            }

            while(n%(i+2) == 0){
                cout << i+2 << " ";
                n /=(i+2);
            }
        }
        if(n > 1) cout << n << "\n";
        else cout << "\n";
    }
};

int main()
{
    Solution st;
    cout << "prime factors for 84 using naive sol : ";
    st.naivePrimeFactors(84);
    cout << "\n";
    cout << "prime factors for 84 using efficient sol : ";
    st.primeFactorsEfficientSol(84);
    cout << "prime factors for 84 using further optimize sol : ";
    st.mostOptimizedPrimeFactors(84);
    return 0;
}
