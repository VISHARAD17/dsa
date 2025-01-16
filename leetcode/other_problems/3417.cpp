/* 3417. Zigzag grid traversal with skip */

#include <iostream>
#include <sys/wait.h>
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

class Solution{
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid){
        bool dir = true, skip = false;
        const int n = grid.size(), m = grid[0].size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                for(int j=0; j<m; j++){
                    if(!skip)ans.push_back(grid[i][j]);
                    skip = !skip;
                }
            }
            else{
                for(int j=m-1; j>=0; j--){
                    if(!skip) ans.push_back(grid[i][j]);
                    skip = !skip;
                }
            }

        }
        return ans;
    }


};

int main()
{
    vector<vector<int>> grid = {{1,2},{3,4}};
    Solution st;
    vector<int>res = st.zigzagTraversal(grid);
    for(auto &x: res) cout << x << " ";
    cout << "\n";
    return 0;
}
