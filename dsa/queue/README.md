### Queue 

- FIFO - first in first out data structure 
- queue data structure:
    ```
                  __________________________
    dequeue() <-- | 10 | 15 | 20 | 30 | 40 | <-- enqueue()
                 front                     rear
    ```
- item added first will be removed first 
- in c++ queue is `queue<int>q` and all below operations has time complexity of O(1)
    - q.top()
    - q.pop() -- removes the first item in the queue ( void function )
    - q.front() -- returns the first item in the queue
    - q.size()
    - q.back() -- prints the last ele in the queue
    - q.empty() -- returns true if queue is empty

- Applications of queue data structure:
    - when we have single resource and there are multiple consumers, here we have to use First come first serve algo.
    - Synchronization between slow and fast devices 
        ex. keyboard is a slow device, when we type it store the chars into a queue and then cpu comes and take those 
        chars in the queue and print/shows them on the screen
    - In operating systems ex. semaphores, FCFS scheduling, buffers for devices like keyboard
    - In computer networks ( routers/switches and mail queues )
    - varitions:
        - deque
        - priority queue (heap)
        - Doubly ended priority queue 
