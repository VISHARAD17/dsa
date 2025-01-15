#ifndef SOLUTION_H
#define SOLUTION_H

#include<iostream>
#include <vector>
#include <algorithm> 
#include<unordered_map>
using namespace std;


class Solution {
private:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int i){
        for(int j=0; j<isConnected.size(); j++){
            // check connection and not visited node
            if(!vis[j] and isConnected[i][j] == 1){
                vis[j] = true;
                dfs(isConnected, vis, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n  = isConnected.size();
        vector<bool>vis(n, false);  
        int ans = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cout << i << " ";
                ans++;
                dfs(isConnected, vis, i);
            }
        }

        return ans;    
    }
};

#endif // SOLUTION_H
