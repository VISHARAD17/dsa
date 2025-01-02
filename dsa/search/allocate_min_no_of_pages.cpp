#include <climits>
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
private:
    int getSum(vector<int>nums, int start, int end){
        int sum = 0;
        for(int i=start; i<=end; i++) sum += nums[i];
        return sum;
    }
    int getPossibleStudents(vector<int>&nums, int sum){
        int curSum = 0;
        const int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(curSum > sum){
                count++;
                curSum = nums[i];
            }
        }
        return count;
    }
public:
    /* given number of pages minimize the max. no. of pages allocated to student
     * so basically divide given pages  into n student/contiguous_groups such that max no. of pages in a grp in minimized
     * */
    int naiveMinimizeAllocatedPagesRecursive(vector<int>&pages, int curSize, int k){
        // for k subgroups we need k-1 cuts, so go through all possible combinations
        // and get the min value for max subgroup sum
        
        // base conditions
        if(k == 1) return getSum(pages, 0, curSize-1);
        if(curSize == 1) return pages[0];

        int ans = INT_MAX;

        for(int i=1; i<curSize; i++){
            ans = min(ans, max(naiveMinimizeAllocatedPagesRecursive(pages, i, k-1), getSum(pages, i, curSize-1)));
        }
        return ans;
    }

    int minimizeAllocatedPagesBinarySearchSol(vector<int>&pages, int students){
        const int n = pages.size();
        // idea is to use max and min value possible i.e min value would be the max array ele 
        // and max value would be the sum of all array ele ( when k=1 case )

        int sum = accumulate(pages.begin(), pages.end(), 0);
        int minPossible = *max_element(pages.begin(), pages.end());

        int low = minPossible, high = sum;
        int ans = INT_MIN;

        while(low <= high){
            int mid = (high+low)/2;
            int reqStudent = getPossibleStudents(pages, mid);
            if(reqStudent <= students){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

};

int main()
{
    Solution st;
    vector<int>pages = {10, 5, 30, 1, 2, 5, 10, 10};
    int students = 3;
    cout << "recursive sol:" << st.naiveMinimizeAllocatedPagesRecursive(pages, pages.size(), students) << "\n"; 
    cout << "binary search sol: " << st.minimizeAllocatedPagesBinarySearchSol(pages, students) << "\n";
    return 0;
}
