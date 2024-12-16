#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

class Solution{
public:
    int isPrefixOfWord(string sentence, string sw){
        stringstream ss(sentence);
        vector<string>words;
        string w;
        while(ss >> w) words.push_back(w);

        for(int i=0; i<words.size(); i++){
            string word = words[i];
            if(sw.size() <= word.size() and word.substr(0, sw.size()) == sw) return i+1;
        }
        return -1;

    }


};

int main()
{
    Solution st;
    cout << st.isPrefixOfWord("i love eating burger", "burg");
    return 0;
}
