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
    // print matrix in snake pattern i.e row in reverse of the previous row
    void printInSnakePattern(vector<vector<int>> &matrix){
        const int row = matrix.size();
        const int col = matrix[0].size();
        for(int i=0; i<row; i++){
            if(i%2 == 0){
                for(int j=0; j<col; j++) cout << matrix[i][j] << " ";
            }
            else{
                for(int j=col-1; j>=0; j--) cout << matrix[i][j] << " ";
            }
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
    st.printInSnakePattern(matrix);
    return 0;
}
