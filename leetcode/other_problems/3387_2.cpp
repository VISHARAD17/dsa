
// 3387 - Maximize the amount after two days of conversions

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
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
    void bellman(unordered_map<string, double> &mp, vector<vector<string>> &p, vector<double> &r){
        for(int i=0; i<p.size(); i++){
            for(int j=0; j<p.size(); j++){
                mp[p[i][1]] = max(mp[p[i][1]], mp[p[i][0]] * r[i]);
                mp[p[i][0]] = max(mp[p[i][0]], mp[p[i][1]] / r[i]);
            }
        }
    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2){
        unordered_map<string, double> mp;
        mp[initialCurrency] = 1.0;
        
        bellman(mp, pairs1, rates1);
        bellman(mp, pairs2, rates2);

        return mp[initialCurrency];
    }
    

};

int main()
{
    Solution st;
    return 0;
}
