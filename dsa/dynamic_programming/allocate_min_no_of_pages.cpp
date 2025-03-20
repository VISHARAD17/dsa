/*
 * allocate minimum no. of pages
 *
 * Given array of books where arr_i represents i_th books pages and total no. of students
 * Minimize the no of pages allocated to each student, condition here is that, we need allocate only contiguos books
 * */


#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    int allocateMinNoOfBooks(vector<int>&books, int students){
        // dp_i_j --> allocation for i students with j books
        vector<vector<int>>dp(students+1, vector<int>(books.size()+1, 0));

        // base case
        for(int j=1; j<=books.size(); j++) dp[1][j] = accumulate(books.begin(), books.begin()+j, 0);

        for(int i=1; i<=students; i++) dp[i][1] = books[0];

        for(int i=2; i<=students; i++){
            for(int j=2; j<=books.size(); j++){
                int res = INT_MAX;

                for(int k=1; k<j; k++){
                    res = min(res, max(dp[i-1][k], accumulate(books.begin()+k, books.end()+j, 0)));
                }
                dp[i][j] = res;
            }
        }
        return dp[students][books.size()];
    }


    int recursive_allocateMinNoOfBooks(vector<int>&books, int n, int students){
        if(students == 1) return accumulate(books.begin(), books.begin()+n, 0);
        if(n == 1) return books[0];

        int res = INT_MAX;

        for(int k=1; k<n; k++){
            res = min(res, 
                        max(
                            recursive_allocateMinNoOfBooks(books, k, students-1),
                            accumulate(books.begin()+k, books.begin()+n, 0)
                        )
                      );
        }
        return res;
    }
};

int main()
{
    vector<int>books = {10, 20, 30, 40};
    Solution st;
    cout << "expected ans : 60\n";
    cout << "recursive sol : " << st.recursive_allocateMinNoOfBooks(books, books.size(), 2) << "\n";
    cout << "DP sol : " << st.allocateMinNoOfBooks(books, 2);
    return 0;
}



