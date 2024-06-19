/*
 * find square root or nearest integer to the square root using binary search
 *
 * */


#include<iostream>
using namespace std;

int squareRoot(int x){
    int low = 1, high =x, ans = -1;

    while(low <= high){
        int mid = (low+high)/2;
        int midSqr = mid * mid;
        
        if(midSqr == x) return mid;
        else if(midSqr > x) high = mid-1;
        else{
            low = mid+1;
            ans = low;
        } 
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << "square root using binary search is" << squareRoot(n) << "\n";
}
