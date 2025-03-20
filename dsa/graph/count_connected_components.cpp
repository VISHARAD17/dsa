/*
 * given graph, count connected components
 *
 * I/P :
 *
 *   0     3   5
 *  / \    |  / \
 *  1  2   4  6  7
 *                \
 *                8
 *
 *  O/P : 3
 * */


#include <iostream>
#include <vector>
#include <queue>
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
private:
    void bfs(vector<vector<int>>adj, vector<bool>&vis, int s){
        vis[s] = true;

        queue<int>q;
        q.push(s);

        while(!q.empty()){
            int topEle = q.front();
            q.pop();
            cout << topEle << " ";

            for(int x: adj[topEle]){
                if(!vis[x]){
                    q.push(x);
                }
            }
        }
    }
public:
    int countConnectedComponent(vector<vector<int>> &adj){
        const int n = adj.size();
        vector<bool>vis(n, false);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(adj, vis, i);
            }
        }
        return ans;

    }


};

int main()
{
    Solution st;
    return 0;
}
