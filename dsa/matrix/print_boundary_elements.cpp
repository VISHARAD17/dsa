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
    /* print elements on the boundary of the matrix */
    void printBoundaryElements(vector<vector<int>> &matrix){
        const int row = matrix.size();
        const int col = matrix[0].size();

        if(row == 1){
            for(int i=0; i<col; i++) cout << matrix[0][i] << " ";
            cout << "\n";
        }
        else if(col == 1){
            for(int i=0; i<row; i++) cout << matrix[i][0] << " ";
            cout << "\n";
        }
        else{
            // first row
            for(int i=0; i<col; i++) cout << matrix[0][i] << " ";
            // last col 
            for(int i=1; i<row; i++) cout << matrix[i][col-1] << " ";
            // last row 
            for(int i=col-2; i>=0; i--) cout << matrix[row-1][i] << " ";
            // first col 
            for(int i=row-2; i>=1; i--) cout << matrix[i][0] << " ";
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
    st.printBoundaryElements(matrix);
    return 0;
}
