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
public:
    void isPalindrome(int n){
        /* convert to string and compare to its reverse*/
        // using math 
        int rev = 0;
        cout << "given number is "  << n << ", ans=";
        int tmp = n;
        while(n >= 10){
            int lastDigit = n%10;
            rev = rev * 10 + lastDigit;
            n /= 10;
        }
        if(n != 0) rev = rev * 10 + n;
        cout << (tmp == rev ? "yes\n": "no\n");
    }

};

int main()
{
    Solution st;
    st.isPalindrome(367);
    st.isPalindrome(363);
    return 0;
}
