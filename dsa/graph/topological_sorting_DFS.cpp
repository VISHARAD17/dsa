/*
 * topological sorting DFS based
 *
 *  ex.   0   1
 *       / \ / \
 *      *   *   *
 *      2   3   4
 *
 *      order : 1 4 0 2 3 or 1 4 0 3 2  ( 0 and 1 are printed before 3)
 * */
#include <iostream>
#include <vector>
#include <stack>
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
    void dfs(vector<vector<int>> &g, int v, vector<bool>&vis, stack<int>&stk){
        vis[v] = true;
        for(int u: g[v]){
            if(!vis[u]){
                dfs(g, u, vis, stk);
            }
        }
        stk.push(v);
    }
public:
    void printTopologicalSortingDFS(vector<vector<int>>&g, int n, vector<bool>&vis){
        stack<int>stk;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(g, i, vis, stk);
        }
        cout << "topological order: ";
        while(!stk.empty()){
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << "\n";
    }

};

int main()
{
    Solution st;
    int n = 5;
    vector<vector<int>> g(5);
    g[0].push_back(2);
    g[0].push_back(3);
    g[1].push_back(3);
    g[1].push_back(4);
    vector<bool>vis(n, false);
    st.printTopologicalSortingDFS(g, 5, vis);
    return 0;
}
