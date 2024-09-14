/*
 * Detect cycle in directed graph
 *
 *                     ----- 5
 *                     |     ^
 *                     *     | 
 *   0 --> 1 <-- 2 --> 3 --> 4
 *                 
 *    there is a cycle in 3, 4 & 5
 * */


#include<iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    cout << n;
    return 0;
}
