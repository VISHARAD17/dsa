/* reversing a queue */

#include <iostream>
#include <queue>
#include <stack>
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
    void printQueue(queue<int>q){
        if(q.empty()) cout << "queue is empty";
        while(q.empty() == false){
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
public:
    void reverseQueue(queue<int> &q){
        // insert all elements into the stack and them push them back from the stack into the queue 
        cout << "original queue: ";
        printQueue(q);
        stack<int>stk;

        while(q.empty() == false){
            int frontEle = q.front();
            stk.push(frontEle);
            q.pop();
        }

        while(stk.empty() == false){
            int topEle = stk.top();
            q.push(topEle);
            stk.pop();
        }
        cout << "reverse queue: ";
        printQueue(q);
    }

};

int main()
{
    queue<int>q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);
    Solution st;
    st.reverseQueue(q);
    return 0;
}
