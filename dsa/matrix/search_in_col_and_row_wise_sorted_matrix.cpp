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
    /* search in matrix - matrix is row wise and col wise sorted 
     * col- top to bottom sorted and row left to right sorted 
     * print element if present else print not found */
    void searchInMatrix(vector<vector<int>> &matrix, int val){
        cout << "searching for " << val << " ";
        const int row = matrix.size();
        const int col = matrix[0].size();

        int i=0, j=col-1;
        while(i<row and j>=0){
            if(val == matrix[i][j]){
                cout << "present at i=" << i << " j=" << j << "\n";
                return;
            }
            else if(val < matrix[i][j]) j--;
            else if(val > matrix[i][j]) i++;
        }
        cout << "not present";
    
    }

};

int main()
{
    Solution st;
    vector<vector<int>> matrix  = {{10, 20, 30, 40},
                                   {15, 25, 35, 45},
                                   {27, 29, 37, 48},
                                   {32, 33, 39, 50}};
    st.searchInMatrix(matrix, 29);
    st.searchInMatrix(matrix, 100);
    return 0;
}
