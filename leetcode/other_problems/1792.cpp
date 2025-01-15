#include <iostream>
#include <vector>
#include <queue>
#include <utility>
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
    double calculateGains(int pass, int totalStudents){
        return (double)(pass+1)/(totalStudents+1) - (double)pass/totalStudents;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
        double ans = 0;
        const int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> maxHeap; // ( gains, {pass, totalStudent})

        // populate the initial heap
        for(vector<int> &cl: classes) maxHeap.push({ calculateGains(cl[0], cl[1]), {cl[0], cl[1]}});

        // distribute  extraStudents
        while(extraStudents--){
            // take the highest gainer 
            pair<double, pair<int, int>> curMaxGainers = maxHeap.top();
            maxHeap.pop();
            int curPass = curMaxGainers.second.first;
            int curStudents = curMaxGainers.second.second; 

            maxHeap.push({calculateGains(curPass+1, curStudents+1), {curPass+1, curStudents+1}});
        }

        // calculate the final ans
        while(!maxHeap.empty()){
            auto [gain, classInfo] = maxHeap.top();
            maxHeap.pop();
            ans += (double)classInfo.first / classInfo.second;
        }
        return (double)ans/n;

    }
};

int main()
{
    vector<vector<int>> classess = {{1, 2}, {3, 5}, {2, 2}};
    int eSt = 2;
    Solution st;
    cout << (double)st.maxAverageRatio(classess, eSt);
    return 0;
}
