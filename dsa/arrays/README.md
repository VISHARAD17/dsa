### Arrays
- arrays have contiguous memory
- random access, can find the element in constant time `O(n)`
- cache friendlyness ( stores individual item in contiguous location)
- Array types
    - fixed size arrays
        - `int arr[n]` (stack allocated memory) or `int *arr = new int arr[n]` ( heap allocated memory )
    - dynamic size arrays
        - `vector<int>a(n)` -- can give fixed size
        - `vector<int>a` -- dynamic size
        - Time complexity:
            - insert : `O(n)`
            - delete : `theta(n)`
            - search
                - sorted: `O(log_n)`
                - unsorted: `O(n)`
            - update `i_th` element: `O(1)`
            - get `i_th` element: `O(1)`
        
- Main problems:
    - [Second largest element](./second_largest_element_array.cpp)
    - [check if array is sorted](./check_if_arrays_is_sorted.cpp)
    - [reverse an array](./reverse_array_elements.cpp)
    - [remove duplicates from a sorted array]()
    - [move zeros to end]()
    - [left rotate an array by one]()
    - [left rotate an array by D places]()
    - [Leaders in an array problem]()
    - [maximum differece problem]()


[Go to main](./../../README.md)
