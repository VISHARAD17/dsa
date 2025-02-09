#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class NumberContainers{
private:
    unordered_map<int, set<int>> numberToIndex;
    unordered_map<int,int> indexToNumber;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index) != indexToNumber.end()){
            int previousNumber = indexToNumber[index];
            numberToIndex[previousNumber].erase(index);
            if(numberToIndex[previousNumber].empty()){
                numberToIndex.erase(previousNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numberToIndex.find(number) != numberToIndex.end()){
            return *numberToIndex[number].begin();
        }
        return -1;
    }

};

int main()
{
    return 0;
}
