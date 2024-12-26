#include <vector>
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
    bool checkIfExist(vector<int>& arr) {
        const int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i] == 2 * arr[j] and i != j) return true;
            }
        }
        return false;
    }

};

int main()
{
    Solution st;
    vector<int>arr = {10,2,5,3};
    cout << st.checkIfExist(arr);
    return 0;
}
