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

class Solution{
public:
    /* spiral tranversal of a matrix */
    void spiralTraversalOfMatrix(vector<vector<int>> &matrix){
        const int row = matrix.size();
        const int col = matrix[0].size();
        int top = 0, bottom = col-1, left=0, right=col-1;

        while(top <= bottom and left <= right){
            // top row
            for(int i=left; i<=right; i++){
                cout << matrix[top][i] << " ";
            }
            top++;
            // last col 
            for(int i=top; i<=bottom; i++){
                cout << matrix[i][right] << " ";
            }
            right--;
            // last row
            if(top <= bottom){
                for(int i=right; i>=left; i--){
                    cout << matrix[bottom][i] << " ";
                }
            }
            bottom--;
            // first col 
            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    cout << matrix[i][left] << " ";
                }
            }
            left++;
        }
        cout << "\n";
    }

};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}, 
                                {13, 14, 15, 16}};
    Solution st;
    st.spiralTraversalOfMatrix(matrix);
    return 0;
}
