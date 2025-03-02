### Hashing 
- hashing is used to implement dictionaries where we have key & value pairs
- provides `search`, `insert` and `delete` operations in O(1) time.
- all keys are unique 
- hashing is not useful for :
    - finding closet key 
    - storing data in sorted order 
    - prefix searching 
- Applications of hashing :
    - implementing dictionaries 
    - database indexing 
    - cryptography 
    - caches : browsers have local data for certain urls, hashing is used here where key is the 
        url and value is the local data
    - Symbol tables in compilers/interpreters : to search different predefined variables
     ex. in c++, `for` and in java `case`
    - routers : wifi routers need to find out devices on local networks using their ip addresses 
        for this mapping, hashing is used 

---

#### Direct address table 
- boolean array with limited range for keys ex. 1 - 1000
- 1 means data it present and 0 means not present 
- this provides all above 3 operations in O(1) time, but keys can only be integers  
    not float, not string, etc,


- in hashing, it hashed the the different possible keys from the universe of keys and use them 
and an index in an array
    ``` 
    ---------------     -----------------
    | universe of | --> | hash function | --> usable array index 
    | keys        |     -----------------    ( for the array known as hash table )
    ---------------
    ```
---

- **How hash functions should be :**
    - should always map a large key to a small key 
    - should generate value from 0 to m-1 ( m is the possible max val possible for index)
    - should be fast ,O(1) for integers and O(n) for string of length n
    - should uniformly distribute large keys into hash table slots

---
- **example hash functions:**
    - H(large_key) = large_key % n;
    - for string weighted sum 
        H(str) = str[0] * x^0 + str[1] * x^1 + str[2] * x^2 + ... + str[n] * x^n

---
- **Collision handling:**
    - collision happends when a hash function produces same index for multiple keys
    - if we know key in advance then we can do perfect hashing 
    - if we do not know the key in advance we use below methods to avoid collusion
        - chaining
        - open addressing
            - linear probling
            - quadratic probling
            - Double hashing 

---
- **Chaining** :
    - chaining is a collison handling method used in hashing 
    - ex. 

        ```
        H(x) = x % 7;

        keys = {50, 21, 58, 17, 15, 49, 56, 22, 23, 25}

        hash table :

        idx value
        --------
        0  | 21 | -> 49 -> 56
        1  | 50 | -> 15 -> 22
        3  | 58 | -> 23
        4  | 17 |
        5  | 25 |
        6  |    |
        7  |    |
        ---------
        Table structure is a Arrya of linked list
        ```
    - performce analysis :
        - `n` -> number of keys to be inserted
        - `m` -> no. of stores in hash table
        - load factor -> n/m
        - assuming uniform distribution of keys among slots, expected length of chain : load factor = n/m
            - expected search time O(1 + n/m) --> O(1) for computing hash function
            - expected time for insert / delete : 0(1 + n/m) --> O(1) for computing hash function
    - Data structures for storing chains: (`l` is chain length)
        - Linked list: 
            - search `O(l)`, insert `O(l)`, delete `O(l)`
        - Dynamic size array `vector<?>vec`
            - search `O(l)`, insert `O(l)`, delete `O(l)`
        - Self balancing BSTs :
            - AVL tree, Red-black tree
            - search `O(log l)`, insert `O(log l)`, delete `O(log l)`
    - implementation of chaining : when collision happens we form a chain
        - implementation using linked list 
            ```cpp
            struct MyHash(){
                int BUCKET;
                list<int> *table;

                MyHash(int b){
                    BUCKET = b;
                    table = new list<int>[*];

                }

                void insert(int key){
                    int i = key % BUCKET;
                    table[i].push_back(key);
                }
                
                void remove(int key){
                    int i =  key % BUCKET;
                    table[i].remove(key);
                }
                
                bool search(int key){
                    int i = key % BUCKET;
                    for(int k : table[i]){
                        if(k == key) return true;
                    }
                    return false;
                }
            }
            ```
---
- **Open Addressing :**
    - Another way of handeling collisons
    - requirements : no of slots in hash table >= no of keys to be inserted
    - advantage over chaining is that is it cache friendly 
    - add into the next slots when the index is already filled
    - **Linear poling** : adds to the next empty slot where there is collision, but if last slot it filled it checkes in circular manner 
    - problem with linear poling is when collision happens we add the key to next empty slots, creating a cluster, this cluster 
    keeps increasing for each collision. This affects the search and delete operations ( which becomes a linear search due to large cluster size)
    - to solve this problem of clustering, we can using double hashing or quadratic poling
    - **Quadratic poling :**
        - instead of going to the next slot go to ith slot, ex. first time collision go to next slot, second time collision go to 2^2 = 4th slot 
        - but this can form secondary clusters if subsequent keys follows the same kind of path but better that primary clustering which happens during the linear poling.
        - is m ( available slots) is a prime number and no. of slots available are more than double the size of keys, then quadratic poling is garanted to work.
    - **Double hashing :**
        - basically uses a secondary hash function when collision happens
        - h2(key) and m should be relatively prime ( this way you get all the possible slots)
        - hash function : `h(key) = key % 7`
        - when `i_th` collision happends : `H(key) =  (h(key) + i * h_2(key)) % 7`
    - implementation of open hashing :
        ```cpp
       struct MyHash(){
           int * arr;
           int cap, size;

           MyHash(int c){
               cap =  c;
               size = 0;

               for(int i=0; i<cap; i++) arr[i] = -1;
           }

           int hash(int key) return key % cap;

           bool search(int key){
               int h = hash(key);
               int i = h;

               while(arr[i] != -1){
                   if(arr[i] ==  key) return true;
                   i = (i+1) % cap;
                   if(i == h) return false;
               }
               return false;
           }

           bool insert(int key){
               if(size == cap) return false;

               int i = hash(key);
               while(arr[i] != -1 and arr[i] != 2 and arr[i] != key){
                   i = (i+1) % cap;
               }
               if(arr[i] == key) return false;
               else{
                   arr[i] = key;
                   size++;
                   return true;
               }
               return false;
           }

           bool erase(int key){
               int h = hash(key);
               int i = h;

               while(arr[i] = -1){
                   if(arr[i] == key){
                       arr[i] = -2;
                       return true;
                   }
                   i = (i+1) % cap;
                   if(i == h) return false;
               }
               return false;
           }
       } 
        ```
- **chaining vs open addressing** :

| chaining | Open addressing |
|---|---|
|  hash table never fills  | table may become full and might require resizing |
| Less sensative to hash function | Requires extra care while designing hash functions to avoid collision |
| Poor cache performace cause diff nodes are stored in diff places | Cache friendly |
| Extra space for linking | Extra space might be needed to achieve same performace as chaining |

- If we are known the count of keys in advance we can use open addressing but to have a dynamic structure to insert more and more keys
we can use chaining which has in general better performace.
---

#### Hash in C++
- **Unordered Set** :
    - normal `set<int>` in c++, is implemented using Red-black tree and the unorodered set is based on hashing 
    - `unordered_set<int> hashSet`
    - time complexities:
        - `O(1)` : hash.begin(), hash.end(), hash.cbegin(), hash.cend(), hash.size(), hash.empty()
        - on average `O(1)`: 
            - insert(), erase(it), erase(), find() --> return iterator if number is present otherwise hash.end(), count() --> return 1 if present otherwise 0
- **Unordered Map**:
    - Map is based on red-black tree whereas unordered_map is based on hashing.
    - no order of keys
    - `unordered_map<int, int> hashMap` --> takes (key, value) pair
        - `O(1)` : hashMap.begin(), hashMap.end(), hashMap.cbegin(), hashMap.cend(), hashMap.size(), hashMap.empty()
        - on average `O(1)`: 
            - insert(), erase(it), erase(), find() --> return iterator if number is present otherwise hashMap.end(), count() --> return 1 if present otherwise 0

#### Problems:
- [count distinct elements](./count_distinct_elements.cpp)
- [frq of array elements](./frq_of_arr_elements.cpp)
- [intersection of two unsorted arrays](./intersection_of_two_unsorted_arr.cpp)
- [union of two unsorted arrays](./union_of_two_unsorted_arrys.cpp)
- [Pair with given sum in unsorted array](./pair_with_given_sum_in_unsorted_array.cpp)
- [subarray with zero sum](./subArray_with_zero_sum.cpp)
- [subarray with given sum](./subArray_with_given_sum.cpp)
- [length of longest subarray with given sum](./len_of_longest_subArray_with_given_sum.cpp)
- [longest subarray with equal 1s and 0s](./longest_subarray_with_equal_ones_and_zeros.cpp)
- [longest common span with same sum in binary array](./longest_common_span_with_same_sum_in_binary_arr.cpp)
- [print all elements occured more than n/k time](./more_than_n_by_k_occurences.cpp)


[go to main](../../README.md)
