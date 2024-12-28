#include <iostream>
#include <algorithm>
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
    /* largest number that divides both a and b*/
    
    int gDForHCF(int a, int b){
        cout << "gdf/hcf of a=" << a << "and b=" << b << "is ";
        while(a != b){
            if(a < b) b -= a; 
            else a -= b; 
        }
        return a;
    }
    
    // time - O(min(a,b)) - linear time
    int naiveGDForHCF(int a, int b){
        cout << "gdf/hcf of a=" << a << "and b=" << b << "is ";
        int res = min(a, b);
        
        while(res > 0){
            if(a%res == 0 and b%res == 0){
                return res;
            }
            res--;
        }
        return -1;
    }

};

int main()
{
    Solution st;
    cout << "naive solution " << st.naiveGDForHCF(3, 6) << "\n";
    cout << "opt solution "  << st.gDForHCF(12, 15) << "\n";
    return 0;
}
