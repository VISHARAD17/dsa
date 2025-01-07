#include <climits>
#include <iostream>
#include <vector>
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
    void medianOfSortedArrays(vector<int>&arr1, vector<int>&arr2){
        const int n1 = arr1.size(), n2 = arr2.size();
        int begin_1 = 0, end_1 = n1; // assuming n_1 is smaller array 
        while(begin_1 <= end_1){
            int i1 = (begin_1+ end_1)/2;
            int i2 = (n1+n2+1)/2  - i1;

            int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
            int max1 = (i1 == 0) ? INT_MIN: arr1[i1];

            int min2 = (i2 == n2) ? INT_MAX: arr2[i2];
            int max2 = (i2 == 0) ? INT_MIN: arr2[i2-1];

            if(max1 <= min2 && max2 <= min1){
                if((n1+n2)/2 == 0){
                    cout << (double)(max(max1, max2) + min(min1, min1))/2;
                    return;
                }
                else{
                    cout << (double) max(max1, max2);
                    return;
                }
            }
            else if(max1 > min2) end_1 = i1-1;
            else begin_1 = i1 + 1;
        }
    }

};

int main()
{
    Solution st;
    vector<int>arr1 = {30, 40, 50, 60}, arr2 = {5, 6, 7, 8, 9};
    st.medianOfSortedArrays(arr1, arr2);
    return 0;
}
