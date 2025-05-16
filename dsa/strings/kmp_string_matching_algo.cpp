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
    vector<int> longestProperPrefixSuffix(string str){
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
        return lps;
    }
public:
    // time - upper bound O(2*n) hence on average - O(n)
    void kmpAlgo(string text, string ptn){
        const int n = text.size();
        const int m = ptn.size();

        vector<int>lps = longestProperPrefixSuffix(ptn);
        cout << "lps :";
        for(int &x: lps) cout << x << " ";
        cout << "\n";

        int i=0, j=0;

        while(i<n){
            if(ptn[j] == text[i]){
                i++;
                j++;
            }
            if(j == m){
                cout << (i-j) << " ";
                j = lps[j-1];
            }
            else if(i<n && ptn[j] != text[i]){
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }
    }

};

int main()
{
    string str = "ababcababaad", ptn = "ababa";
    Solution st;
    st.kmpAlgo(str, ptn);
    return 0;
}
