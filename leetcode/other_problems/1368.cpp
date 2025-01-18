/* 1368.Minimum cost to make at least one valid path in a grid */


#include <climits>
#include <iostream>
#include <vector>
#include <deque>
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
    int minCost(vector<vector<int>>& grid){
        // 1 - right, 2-left, 3- down, 4,-up
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));

        minCost[0][0] = 0;
        deque<vector<int>>dq;
        dq.push_back({0, 0});

                            /*     right,   left,   down,    up  */
        vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!dq.empty()){
            int cur_i = dq.front()[0], cur_j = dq.front()[1];
            dq.pop_front();

            for(int i=0; i<4; i++){
                int new_i = cur_i + dir[i][0], new_j = cur_j + dir[i][1];
                int cost = (grid[cur_i][cur_j] != (i+1) ? 1:0);

                if(new_i >=0 and new_i < n and new_j >=0 and new_j < m and minCost[cur_i][cur_j]+cost < minCost[new_i][new_j]){
                    minCost[new_i][new_j] = minCost[cur_i][cur_j] + cost;

                    if(cost == 1){
                        dq.push_back({new_i, new_j});
                    }
                    else dq.push_front({new_i, new_j});
                }
            }
        }
        return minCost[n-1][m-1];
    }
};

int main()
{
    Solution st;
    vector<vector<int>> grid1 = {{1,1,3},{3,2,2},{1,1,4}}, grid2 = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << "tc 1: " << st.minCost(grid1) << "\n";
    cout << "tc 2: " << st.minCost(grid2) << "\n";
    return 0;
}
