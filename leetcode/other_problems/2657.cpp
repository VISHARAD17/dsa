/* 2657.Find the prefix common array of two arrays */


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    void printSet(multiset<int> &m){
        for(auto &x: m) cout << x << " ";
        cout << "\n";
    }
    
    int getLen(vector<int> &frq, int endIdx){
        int ans = 0;
        for(int i=0; i<frq.size(); i++){
            if(frq[i] == 2) ans++;
        }
        return ans;
    }
public:
    void printArray(vector<int> &arr){
        for(auto &x: arr) cout << x << " ";
        cout << "\n";
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        const int n = A.size();
        vector<int>frq(n+1, 0);
        vector<int>ans;
        for(int i=0; i<n; i++){
            frq[A[i]]++, frq[B[i]]++;
            // cout << "frq at " << i << " ";
            // printArray(frq);
            ans.push_back(getLen(frq, max(A[i], B[i])));
        }
        return ans;
    }
};

int main()
{
    vector<int>A = {1,3,2,4}, B = {3,1,2,4};
    vector<int>A1 = {2,3,1}, B1 = {3,1,2};
    Solution st;
    vector<int> res = st.findThePrefixCommonArray(A, B);
    vector<int> res1 = st.findThePrefixCommonArray(A1, B1);
    cout << "tc 1: ";
    st.printArray(res);
    cout << "tc 2: ";
    st.printArray(res1);
    return 0;
}
