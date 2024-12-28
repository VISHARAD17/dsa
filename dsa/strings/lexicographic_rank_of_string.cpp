#include <iostream>
#include <string>
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
private:
    int factorial(int n){
        if(n == 0 or n == 1) return 1;
        
        int ans = 1;
        for(int i=2; i<=n; i++) ans *= i;
        return ans;
    }
public:
    /* print the lexicographic rank among the permutations of the string */
    void lexicographicRank(string s){
        cout << "rank for " << s << "is ";
        const int n = s.size();
        
        int res= 1;
        int mul = factorial(n);

        vector<int>chr(256, 0);
        for(int i=0; i<n; i++) chr[s[i]]++;
        // now get the cumulitive count
        for(int i=1; i<256; i++) chr[i] += chr[i-1];

        for(int i=0; i<n-1; i++){
            mul /= (n-i);
            res += chr[s[i] - 1] * mul;
            for(int j=s[i]; j<256; j++) chr[j]--;
        }
        cout << res << "\n";
    }

};

int main()
{
    Solution st;
    st.lexicographicRank("string");
    return 0;
}
