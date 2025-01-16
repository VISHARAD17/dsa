/* 3419.Minimize the maximum edge weight of the graph */

#include <iostream>
#include <vector>
#include <utility>
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
    int dfs(int i, int m, vector<vector<pair<int, int>>> &ral, vector<int> &vis){
        int res = 1;
        vis[i] = 1;

        for(auto [j, w]: ral[i]){
            if(w <= m and !vis[j]){
                res += dfs(j, m, ral, vis);
            }
        }
        return res;
    }
public:
    /* we can ignore threshold cause min value is 1 and max value if threshold */
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold){
        // reverse adjacency list 
        vector<vector<pair<int, int>>> ral(n);

        for(auto &e: edges){
            ral[e[1]].push_back({e[0], e[2]});
        }
        
        int l=1, r= 1e6+1;
        while(l < r){
            int m = (l+r)/2;
            vector<int>vis(n);
            if(dfs(0, m, ral, vis) == n) r = m;
            else l = m+1;
        }

        return l == 1e6+1 ? -1: 1;
    }


};

int main()
{
    vector<vector<int>> edges = {{1,0,1},{2,0,2},{3,0,1},{4,3,1},{2,1,1}};
    Solution st;
    cout << st.minMaxWeight(5, edges, 2);
    return 0;
}
