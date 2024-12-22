#include <iostream>
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

/*
 * move zeros in the array to the end while keeping the same order of the other non-zero elements
 * ex. arr = {10, 5, 0, 0, 8, 0, 9, 0} O/P - {10, 5, 8, 9, 0, 0, 0, 0}
 * */
class Solution{
public:
    void moveZerosToEnd(vector<int>&nums){
        const int n = nums.size();
        int curZero = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                curZero = i;
                break;
            }
        }

        for(int i=curZero; i<n; i++){
            if(nums[i] != 0){
                nums[curZero] = nums[i];
                nums[i] = 0;
                while(curZero < n and nums[curZero] != 0) curZero++;
            }
        }
        cout << "Array -- ";
        for(int &x: nums) cout << x << " ";
    }

    void betterSolution(vector<int>&nums){
        const int n = nums.size();
        int curIdx = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                int tmp = nums[curIdx];
                nums[curIdx] = nums[i];
                nums[i]  = tmp;
                curIdx++;
            }
        }

        cout << "Array -- ";
        for(int &x: nums) cout << x << " ";
    }

};

int main()
{
    Solution st;
    vector<int>nums = {10, 5, 0, 0, 8, 0, 9, 0};
    st.moveZerosToEnd(nums);
    cout << "\n";
    st.betterSolution(nums);
    return 0;
}
