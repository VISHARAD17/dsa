/*
 * Maximum cuts :
 * Given a rod of length n and three values a, b & c. Find out maximum cuts in the rod such that length of every cut is either a or b or c
 *
 * */


#include <algorithm>
#include<iostream>
using namespace std;

// dp solution
int maximumCuts(int n, int a, int b, int c){
    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        dp[i] = -1;
        if(i-a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i], dp[i-c]);

        // its not -1 which means a cut or no. of cuts were made
        // so +1 to get total pieces
        if(dp[i] != -1) dp[i]++;
    }
    return dp[n];
}

int maxCutRecur(int n, int a, int b, int c){
    if(n == 0) return 0;
    if(n < 0) return -1;

    // take a or b or c and then take max of all possible three conditon
    int res = max({maxCutRecur(n-a, a, b, c), maxCutRecur(n-b, a, b, c), maxCutRecur(n-c, a, b, c)});
    if(res == -1) return res;
    return res+1;

}


int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << "Maximum cuts" << maximumCuts(n, a, b, c);
    return 0;
}
