/*
 * This code explains about unordered_map in c++ stl
 * */
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
    cout << "Code for unordered_map\n";
    unordered_map<int, int> mp;

    // insert 
    mp.insert({1, 2}); //(key, value)
    mp.insert({2, 3}); 
    mp.insert({4, 5}); 
    // we can input elements like this as well
    mp.insert(make_pair(5, 6)); 


    for(auto &x: mp) cout << x.first << ":" << x.second << "\n";
    /*
        This should print :
        5:6
        4:5
        2:3
        1:2
    */
    cout << "after removing\n";

    //remove
    mp.erase(mp.begin()); // deleting first char
    // mp.begin() -> iterator

    // print mp 
    for(auto &x: mp) cout << x.first << ":" << x.second << "\n";
    /*
            This should print :
            4:5
            2:3
            1:2
        */
    return 0;
}
