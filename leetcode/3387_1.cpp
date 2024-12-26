// 3387 - Maximize the amount after two days of conversions
// solution using graph

#include <queue>
#include <string>
#include <unordered_map>
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
    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>> &p, vector<double> r){
        unordered_map<string, unordered_map<string, double>> g;
        const int n = p.size();
        for(int i=0; i<n; i++){
            string startCur = p[i][0];
            string endCur = p[i][1];
            double rate = r[i];
            
            g[startCur][endCur] = rate;
            g[endCur][startCur] = 1.0/rate;
        }

        return g;
    }

    unordered_map<string, double> getMaxAmtForD1(string startCur, unordered_map<string, unordered_map<string, double>> g){
        unordered_map<string, double>maxAmts;
        maxAmts[startCur] = 1.0;
        int s;

        queue<string>q;
        q.push(startCur);
    
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            
            double currentAmt = maxAmts[cur];

            // check all possible conversions
            for(auto &e: g[cur]){
                string neighbour = e.first;
                double rate = e.second;

                double newAmt = currentAmt * rate;

                if(newAmt > maxAmts[neighbour]){
                    maxAmts[neighbour] = newAmt;
                    q.push(neighbour);
                }
            }

        }
        return maxAmts;
    }

    unordered_map<string, double> getMaxAmtForD2(string startCur, unordered_map<string, unordered_map<string, double>> g, unordered_map<string, double> initialAmounts){
        unordered_map<string, double> maxAmts = initialAmounts;

        queue<string>q;
        for(const auto &pair: initialAmounts) q.push(pair.first);
        
        while(!q.empty()){
            string cur = q.front();
            q.pop();

            double currentAmount = maxAmts[cur];

            for(auto &e: g[cur]){
                string neighbour = e.first;
                double rate = e.second;

                double newAmount = currentAmount * rate;

                if(newAmount > maxAmts[neighbour]){
                    maxAmts[neighbour] = newAmount;
                    q.push(neighbour);
                }
            }
        }

        return maxAmts;
    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2){
        // create graphs for both days
        unordered_map<string, unordered_map<string, double>> g1 = buildGraph(pairs1, rates1);
        unordered_map<string, unordered_map<string, double>> g2 = buildGraph(pairs2, rates2);
        
        // day 1 max ammount
        unordered_map<string, double> maxDay1Amounts = getMaxAmtForD1(initialCurrency, g1);
        unordered_map<string, double> maxDay2Amounts = getMaxAmtForD2(initialCurrency, g2, maxDay1Amounts);

        return maxDay2Amounts[initialCurrency];

    }


};

int main()
{
    Solution st;
    return 0;
}
