## Dynamic Programming

    Dynamic programming is optimization over plain recursion. Idea of dynamic programming is to reuse the solution where there are overlapping subproblems.

### ways to implement DP solutions :
    - Memoization ( top down )
    - Tabulation ( Bottom up )

-----------------------------------------------------------

Fibonacci series :

1. Memoization Solution

time - O(n)
space - O(n)

```C++
vector<int>mem(n+1, -1); // public vector

int memoFib(int n){
    // if not calculated then calculate otherwise return the stored value
    if(mem[n] == -1){
        int res;
        if(n == 0 or n == 1){
            return n;
        }
        else res = memoFib(n-1) + memoFib(n-2);
        mem[n] = res;
    }
    return mem[n];
}
```

2. Tabulation Solution

time - O(n)
space - O(n)

```C++
int fib(n){
    vector<int>dp[n+1];
    //base cases
    dp[0] = 0;
    dp[1] = 1;
    // fib logic
    for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
```
