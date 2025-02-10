#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
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
    string clearDigits(string s){
        const int n = s.size();
        stack<char>stk;

        for(char &c: s){
            if(isdigit(c)){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else stk.push(c);
        }

        string ans = "";
        while(!stk.empty()){
            char c = stk.top();
            ans += c;
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution st;
    cout << "1st tc : " << st.clearDigits("abc") << "\n";
    cout << "2st tc : " << st.clearDigits("cb34") << "\n";
    return 0;
}
