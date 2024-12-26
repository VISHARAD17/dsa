### Strings

#### String functions:
- `strcmp(str_1, str_2)`
    - returns 1 if 1st string is lexiographically greater than 2nd
    - return 0 if both are same
    - returns -1 if 2nd is lexiographically greater than the 1st

### pattern searching in string
text - size n and pattern - size m
- Naive - O((n-m+1) * m) - no preprocessing required
    - O(n) - when all the chars are unique
- robin karp -  O((n-m+1) * m) - prepocess the pattern
- kmp - O(n) - preprocess the pattern
- suffix tree - O(m)- preproces the text

#### Problems
- [Palindrome check](./palindrome_check.cpp)
- [check if string is subsequence of other]()
- [leftmost non repeating char](./leftmost_non_repeating_element.cpp)
- [leftmost repeating char](./leftmost_repeating_char.cpp)
- [anagram](./anagram.cpp)
- Pattern search 
    - [naive pattern search]()
    - something

