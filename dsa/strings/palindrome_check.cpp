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
    void palindromeCheck(string s){
        cout << "given string is " << s << " and is palindrom :";
        const int n = s.size();
        int half = (int)n/2;
        for(int i=0; i<=half; i++){
            if(s[i] != s[n-i-1]){
                cout << "no\n";
                return;
            }
        }
        cout << "yes\n";
    }

    void whileLoopCheck(string s){
        const int n = s.size();
        int i=0, j=n-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
        cout <<  "YES\n";
        return;
    }

};

int main()
{
    Solution st;
    st.palindromeCheck("ABCDCBA");
    st.palindromeCheck("ABC");
    st.palindromeCheck("A");
    return 0;
}
