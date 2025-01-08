
#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <vector>
#include <algorithm> 
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        return (revStr == str ? true: false);
    }
};
#endif // SOLUTION_H
