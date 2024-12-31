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
private:
    void printMatrix(vector<vector<int>> &matrix){
        for(vector<int> &arr: matrix){
            for(int &x: arr) cout << x << " ";
            cout << "\n";
        }
    }
public:
    /* rotate matrix 90 degrees anti clock wise */
    void rotateMatrixAnticlockwise90Degree(vector<vector<int>> &matrix){
        const int row = matrix.size();
        const int col = matrix[0].size();

        // transpose the matrix
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // reverse the columns
        for(int i=0; i<col; i++){
            int low = 0, high=row-1;
            while(low < high){
                // swap
                int tmp = matrix[low][i];
                matrix[low][i] = matrix[high][i];
                matrix[high][i] = tmp;
                low++;
                high--;
            }
        }

        printMatrix(matrix);
    }

};

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}, 
                                {13, 14, 15, 16}};
    Solution st;
    st.rotateMatrixAnticlockwise90Degree(matrix);
    return 0;
}
