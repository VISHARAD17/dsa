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
    // time - O(n * log(log n)) ~ O(n)
    void printPrimeSmallerThanN(int n){
        vector<bool>isPrime(n+1, true);

        for(int i=2; i<=n; i++){
            if(isPrime[i]){
                cout << i << " ";
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        cout << "\n";
    }

};

int main()
{
    Solution st;
    cout << "prime numbers less than 84 are ";
    st.printPrimeSmallerThanN(84);
    return 0;
}
