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
private:
    const int d = 256;
    const int q = 101;
public:
    /*
     * idea of this algorityhm is to compare the hash value of the pattern with 
     * the hash value of the current window of text, if that matches then only compare the elements
     * */
    void robinKarpAlgo(string text, string ptn){
        const int n = text.size(), m = ptn.size();
        int h = 1; // this is the multipler for the first char
        for(int i=1; i<m; i++) h = (h*d)%q;

        /*
         * hash value for first 3 = d^2 * p_0 + d^1 * p_1 + d^0 * p_2
         *
         * now we need get next hash value i.e. from 1st till 4th
         * so new value = d^2 * p_1 + d^1 * p_2 + d^0 * p_3
                        = d ( d^2 * p_0 + d^1 * p_1 + d^0 * p_2 - d^2 * p_0) +  d^0 * p_3
                        = d ( previous_hash_value - d^(m-1)* p_prev) + p_cur  -> here m was 3
 
         * */

        int p=0, t=0;
        for(int i=0; i<m; i++){
            p = (p*d + ptn[i]) % q;
            t = (t*d + text[i]) % q;
        }

        for(int i=0; i<=n-m; i++){
            if(p == t){
                bool flag = true;
                for(int j=0; j<m; j++){
                    if(text[i+j] != ptn[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) cout << i << " ";
            }
            if(i < n-m){
                t = ((d * (t - text[i]*h)) + text[i+m]) % q;
                if(t < 0) t += q;
            }
        }
    }

};

int main()
{
    Solution st;
    st.robinKarpAlgo("GEEKSFORGEEKS", "EKS");
    return 0;
}
