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

-------
- example hash functions:
    - H(large_key) = lage_key % n
    - for string weighted sum 
        H(str) = str[0] * x^0 + str[1] * x^1 + str[2] * x^2 + ... + str[n] * x^n
    -  




