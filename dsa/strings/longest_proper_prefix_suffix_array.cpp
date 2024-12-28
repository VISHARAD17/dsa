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
/*
 * perfect prefix of "abcd" -> "", "a", "ab", "abc"
 * suffix of "abcd" -> "", "d", "cd", "bcd", "abcd"
 * */
public:
    // lps_i -> for array of length i maximum value of string which proper prefix as well as a suffix
    void longestProperPrefixSuffix(string str){
        const int n = str.size();
        vector<int>lps(n, 0);
        int len = 0;

        lps[0] = 0;
        int i=1;
        while(i<n){
            if(str[i] == str[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        cout << "efficient lsp: ";
        for(int &x: lps) cout << x << " ";
        cout << "\n";
    }

    int naiveLongestProperPrefixSuffix(string str, int n){
        for(int len=n-1; len>0; len--){
            bool flag = true;
            for(int i=0; i<len; i++){
                if(str[i] != str[n-len+i]) flag = false;
            }
            if(flag) return len;
        }
        return 0;
    }

    void naiveFillLPS(string str){
        const int n = str.size();
        vector<int>lsp(n, 0);

        for(int i=0; i<n; i++) lsp[i] = naiveLongestProperPrefixSuffix(str, i+1);
        cout << "lsp using naive method :";
        for(int &x: lsp) cout << x << " ";
        cout << "\n";
    }

};

int main()
{
    Solution st;
    string str = "aaabaaaac";
    st.naiveFillLPS(str);
    st.longestProperPrefixSuffix(str);
    return 0;
}
