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
public:
    /* check if pattern or its permutation i.e. anagram is present in the given text
     * print yes or no
     */
    /*
     * naive solution would be to check each window one by one time - O((n-m+1) * m) 
     * cause for each loop (len n-m+1) we have to check m times, in summary quadratic time
     * */
    void anagramSearch(string text, string ptn){
        const int n = text.size();
        const int m = ptn.size();
        cout << "strings are text=" << text << "and pattern=" << ptn << " ";
        if(m > n){
            cout << "no\n";
            return;
        }
        
        vector<int>chrText(256, 0), chrPtn(256, 0);
        // first m chars
        for(int i=0; i<m; i++){
            chrText[text[i]]++;
            chrPtn[ptn[i]]++;
        }

        for(int i=m; i<n; i++){
            if(chrText == chrPtn){
                cout << "yes\n";
                return;
            }

            chrText[text[i-m]]--;
            chrText[text[i]]++;
        }
        cout << "no\n";
    }

};

int main()
{
    Solution st;
    string text = "geeksforgeeks", pattern = "frog";
    st.anagramSearch(text, pattern);
    return 0;
}
