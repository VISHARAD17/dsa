### Deque
- operations ( all are O(1) time )
    - insertFront 
    - deleteFront
    - insertBack
    - deleteBack
    - getFront 
    - getBack
    - Size
    - isEmpty -- bool
- can be implement using circular array and doubly linked lists 
- Applications:
    - A deque can be used as both stack and queues
    - to store history of actions ex. back and front button of browsers, whenever we visit a page 
    it add to the end of queue and when buffer becomes full it deletes from the front, and when we 
    do back button it check the back of queue, as we keep hiting back button, it keeps on removing
    from the end 
    - A steal process scheduling algorithm
    - implementing a priority queue with on;t two types of priorities for ex. priorities of type 1 and 2.
    so we need to finish all 1 tasks before 2. Hence, whenever priority task 1 comes we add it in front 
    and whenever priority task 2 comes we add it in rear.
    - maximum and minimum of all subarray of size k in a given array

- implementation in c++
    - it is implemented using doubly linked list
    - also it provides random access
    - `include<deque>` -> header
    - initialization - `deque<int>dq = {1, 2, 3, 4}`
    - operations ( all operations are O(1)) :
        - `push_front`
        - `push_back`
        - `dq.front()`
        - `dq.back()`
        - `dq.pop_front()`
        - `dq.pop_back()`
        - `dq.size()`
    - `dq.erase()` and `dq.insert()` at a given index is O(n) operation

Problems:
- [first circular tour](./first_circular_tour.cpp)
- [maximum of all subarrays of size k](./maximum_of_all_subarrays_of_size_k.cpp)
