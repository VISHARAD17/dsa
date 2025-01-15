/* Check if a parenthesis string can be valid */

#include <string>
#include <stack>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    bool canBeValid(string s, string locked){
        const int n = s.size();
        if(n%2 == 1) return false;

        stack<int>unlock, open;

        for(int i=0; i<n; i++){
            if(locked[i] == '0') unlock.push(i);
            else if(s[i] == '(') open.push(i);
            else if(s[i] == ')'){
                if(!open.empty()) open.pop();
                else if(!unlock.empty()) unlock.pop();
                else return false;
            }
        }
        
        while(!open.empty() and !unlock.empty() and open.top() < unlock.top()){
            open.pop();
            unlock.pop();
        }

        if(!unlock.empty() and unlock.size()%2 == 1) return false;
        if(!open.empty()) return false;
        return true;
    }

};

int main()
{
    Solution st;
    string s = "))()))", locked = "010100";
    cout << st.canBeValid(s, locked);
    return 0;
}
