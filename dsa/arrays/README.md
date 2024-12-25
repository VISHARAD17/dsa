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
    - [remove duplicate from sorted array](./remove_duplicates_from_sorted_array.cpp)
    - [move Zero to the end of the array](./move_zeros_to_end.cpp)
    - [left rotate array by 1](./left_rotate_an_element_by_one.cpp)
    - [left rotate array by d places](./left_rotate_by_d_places.cpp)
    - [leaders in array](./leaders_in_array.cpp)
    - [maximum differe in order](./max_diff_in_order.cpp)
    - [max frequency in sorted array](./frq_in_sorted_array.cpp)
    - [buy and sell stocks](./stock_buy_and_sell.cpp)
    - [trapping rain wanter](./trapping_rain_water.cpp)
    - [maximum consecutive ones](./max_consecutive_1s.cpp)
    - [max subarray sum](./max_subarray_sum.cpp)
    


[Go to main](./../../README.md)
