#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    // print yes if pattern exists else no
    void naiverPatternExists(string text, string ptn){
        // time - O( (n-m+1) * m) , no extra space
        const int n = text.size(), m = ptn.size();
        cout << "text: "  << text << " and pattern: " << ptn << "\n";

        if(n < m){
            cout << "pattern greater than text";
            return;
        }
        
        for(int i=0; i<=n-m; i++){
            int j;
            for(j=0; j<m; j++){
                if(ptn[j] != text[i+j]) break;
            }
            if(j == m) cout << i << " ";
        }
        cout << "\n";
    }

    // given that pattern has all disctinct chars
    void naiverPatternExists_imp(string text, string ptn){
        const int n = text.size(), m = ptn.size();
        cout << "text: "  << text << " and pattern: " << ptn << "\n";
        if(n < m){
            cout << "pattern greater than text";
            return;
        }
        
        for(int i=0; i<=n-m;){
            int j;
            for(j=0; j<m; j++){
                if(ptn[j] != text[i+j]) break;
            }
            if(j == m) cout << i << " ";
            if(j == 0) i++;
            else i+=j;
        }
        cout << "\n";
    }

};

int main()
{
    string text = "ABCDABC", ptn = "ABC";
    Solution st;
    st.naiverPatternExists(text, ptn);
    cout << "imp naive pattern search given that ptn has all disctinct chars \n";
    string text2 = "GEEKSFORGEEKS", ptn2 = "EKS";
    st.naiverPatternExists_imp(text2, ptn2);
    return 0;
}
