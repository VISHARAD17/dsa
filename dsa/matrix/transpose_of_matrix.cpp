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
    /* given n x n matrix, print its transpose, -> 1st row become 1st col, etc.*/
    void transposeOfMatrix(vector<vector<int>> &matrix){
        const int row = matrix.size();
        const int col = matrix[0].size();

        // swap elements along the diagonal
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(auto &x: matrix){
            for(auto &y: x) cout << y << " ";
            cout << "\n";
        }

    }

};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}, 
                                {13, 14, 15, 16}};
    Solution st;
    st.transposeOfMatrix(matrix);
    return 0;
}
