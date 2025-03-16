/*
 * Edit Distance problem
 *
 * problem : we are allowed three operations, insert, delete, replace. Find min. number of operations needed
 *           to covert s1 into s2.
 *
 *           ex. s1 = CAT  s2 = CUT , edit_distance = 1
 *
 * */


#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

int dp_edit_distance(string s1, string s2){
    // time and space - O(n x m)
    const int n = s1.size();
    const int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    // base cases
    for(int j=0; j<=m; j++) dp[0][j] = j; // first row
    for(int i=0; i<=n; i++) dp[i][0] = i; // first column

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // last char matches
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            // last char does not match, take min of three operations 
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    return dp[n][m];
}

int recur_edit_distance(string s1, string s2, int n, int m){
    // base cases
    if(n == 0) return m;
    if(m == 0) return n;

    if(s1[n-1] == s2[m-1]) return recur_edit_distance(s1, s2, n-1, m-1);
    // 1 + min(delete, insert, replace)
    return 1 + min({recur_edit_distance(s1, s2, n-1, m), recur_edit_distance(s1, s2, n, m-1), recur_edit_distance(s1, s2, n-1, m-1)});
}

int main(){
    string s1 = "CAT", s2 = "CUT";
    int n = s1.size(), m = s2.size();

    int recur_ans = recur_edit_distance(s1, s2, n, m);
    int dp_ans = dp_edit_distance(s1, s2);

    cout << "for string s1: " << s1 << " and s2: " << s2 << "\n";
    cout << "recursive ans : " << recur_ans << "\n";
    cout << "dp ans : " << dp_ans << "\n";
    return 0;
}
