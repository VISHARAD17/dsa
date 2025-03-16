## Dynamic Programming
Dynamic programming is optimization over plain recursion. Idea of dynamic programming is to reuse the solution where there are overlapping subproblems.

### ways to implement DP solutions
- Memoization ( top down )
- Tabulation ( Bottom up )

---
Fibonacci series :

1. Memoization Solution :
Time - `O(n)`,  space - `O(n)`

```cpp
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
---

2. Tabulation Solution

time - O(n)
space - O(n)

```cpp
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
---

#### Dynamic Programming problems :
- [Longest common subsequence and variations](./longest_common_subsequence.cpp)
- [Edit distance](./edit_distance.cpp)
- [coin change](./coin_change.cpp)
- [Maximum cut](./maximum_cuts.cpp)
- [Min coins](./min_coins.cpp)
- [Minimum jumps to reach end](./minimum_jumps_to_reach_at_end.cpp)
- [0-1 knapsack](./0-1_knapsack_problem.cpp)
- [Longest increasing subsequence](./logest_increasing_subsequence.cpp)
- Variations of LIS(Longest increasing subsequence):
    - [maximum sum of increasing subsequence](./maximum_sum_increasing_subsequence.cpp)
    - [Maximum length of bitonic subsequence](./maximum_len_of_bitonic_subsequence.cpp)
    - [Building bridges](./building_bridges.cpp)
    - [Longest chain of pairs]()
- [0-1 kanpsack problem](./0-1_knapsack_problem.cpp)
- [Optimal strategy for a game](./optimal_strategy_for_a_game.cpp)
- [Egg dropping puzzel](./egg_dropping_puzzle.cpp)
- [count BSTs with n keys](./count_BSTs_with_n_keys.cpp)
- [maximum sum with no two consecutives](./max_sum_with_no_2_consecutive.cpp)
- [subset sum problem](./subset_sum.cpp)
- [matrix chain multiplication](./matrix_chain_multiplication.cpp)



[Go to main](./../../README.md)
