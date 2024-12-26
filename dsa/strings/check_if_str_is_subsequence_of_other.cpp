#include <iostream>
#include <string>
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
    // subsequence does not necessorily has to be contigous
    // subsequence of a string is obtained by removing 0 or more chars from it
    void checkIfSubstr(string s1, string s2){
        // check if s2 is substring
        const int n = s1.size();
        const int m = s2.size();
        cout << "s1 = " << s1 << " s2 = " << s2 << " ";
        int i=0, j=0;
        while(i<n and j<m){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(j == m) cout << "YES\n";
        else cout << "NO\n";

    }

};

int main()
{
    Solution st;
    st.checkIfSubstr("ABCD", "AD");
    st.checkIfSubstr("ABCDE", "AED");
    return 0;
}
