/*
 * Minimum jumps to reach at end
 *
 * we are given an array, where each element represents the maximum jump we can make from that particular point.
 * what is the min. no. of jumps required to go from first element of the array to the last
 *
 * ex. arr = [3, 4, 2, 1, 2, 1]   min. jumps : 2 
 *            |_1_|           |
 *               |_____2_____|
 *
 * time complexity : O(n)  space complexity : O(n)

 test case:
6
3 4 2 1 2 1

ans : 2
*/



#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int>&arr, const int n){
    vector<int>dp(n); // dp[i] -> min. jumps to reach index i form 0;
    dp[0] = 0; // base case
    for(int i=1; i<n; i++) dp[i] = INT_MAX;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(j+arr[j] >= i) {
                if(dp[j] != INT_MAX) dp[i] = min(dp[j]+1, dp[i]);
            }
        }
    }

    return dp[n-1];
}

/*
 * start from the end, and recursively call for cells from which we can reach the end
 * and similarly repeat for those cells as well and add one to it for the jump
 * */
int minJumpsRecursive(vector<int>&arr, int n){
    // base case : if size of the array is 1 then min jump is 0
    if(n == 1) return 0;
    int res = INT_MAX;
    for(int i=0; i<=n-2; i++){
        // check if from that cell we can reach to the end
        if(i + arr[i] >= n-1){
            int sub_res = minJumps(arr, i+1);
            if(sub_res != INT_MAX) res = min(res, sub_res+1);
        }
    }
    return res;
}

int main(){

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int &x: arr) cin >> x;
    
    int ansDP = minJumps(arr, n);
    int ansRecursive = minJumpsRecursive(arr, n);

    cout << "min. number of jumps (recursively) : " << ansDP << "\n";
    cout << "min. number of jumps : " << ansRecursive << "\n";
}
