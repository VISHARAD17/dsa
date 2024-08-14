### Operating systems introduction
[Article](https://www.geeksforgeeks.org/batch/sde-theory-1/track/Introduction-to-Operating-System/article/MjgxOA%3D%3D)

- Manger or incharge for our systems

```
          User 
            |
        Applications
            |
operating systems ( linux, windows)
            |
hardware (CPU, HDD, memory)
```
__________________________________________________________________________________________

* Reason for operating system to exists :
    - Resource management : We have limited resource for a particular machine. it manages which application or process to run in backgroud. handles
                           multiple applications.
    - Abstraction : operating system extracts the hardware ( talks to them), we don't need to write machine/binary code. It provides system calls to
                    the library, using which application development becomes easier
    - Protection : protects application from each other, protects from malware. kind of system manager

__________________________________________________________________________________________

### Types of Operating systems
[Article](https://www.geeksforgeeks.org/batch/sde-theory-1/track/Introduction-to-Operating-System/article/MTY5NA%3D%3D)
* Single tasking :
    - very basic/simple operating systems
    - only one process can exists in RAM and can run at a time 
    - cons : CPU has to sit ideal during IO
    - ex. MS-DOS

* Multiprogramming and Multi-tasking:
    - Use single CPU to run multiple processes concurrently
    - Multi-tasking : tasked are performed in their assigned time slots. Multi-tasking systems are
    responsive, since they do not have to wait for other processes to finish. It is an extension to 
    Multi-programming where one task does the processing while the other does its I/O.

* Multi-threading :
    - running one or more threads in interleaved fashion
    - more responsiveness
    - a processor is made up of one or more threads
    - thread is smallest unit of CPU
    - switching between threads is less costly than switching between processes
    - ex. VLC player, MacOS, Linux

* Multi-processing
    - OS supporting multiple processors
    - Divide multiple threads into multiple processors and multiple processors into multiple processes
----------------------------------
### Multi-threading introduction:
[Article](https://www.geeksforgeeks.org/batch/sde-theory-1/track/Introduction-to-Operating-System/article/MTc5OQ%3D%3D)

- **Multi-tasking** : doing multiple tasks and the same time. Ex. listening to music and browsing
web. Here, we are performing two diff. tasks at the same time.
- **Multi-threading** : doing multiple things within a process or task. Ex. downloading something
in browser and browsing. Here, we're doing different things within a same browser process/task.

- **Real world examples**
    - Multi-threading :
        - word processor : typing, saving, formatting and spell-checking happens at the same
        time
        - web servers : Apache HTTP servers uses thread pools
        - IDEs : Modern IDEs do compilation, error checks while we write the code
        - Games : In modern game multiple objects are implemented on multiple threads
- **Advantages of Multi-threading**:
    - Parallelism and improved performance
    - Responsiveness
    - Better resource utilization
- **Disadvantages** :
    - Difficulty in writing, testing and debugging code : when running a multi-threaded program we might
    get different results when ran on different time, hence difficult to reproduce the error
    - can lead to deadlock and race condition : race condition happens when we have shared variables across different classes
    or when multiple threads are working on same shared variable.
    ex. need to increment a variable twice and print it : sometimes 2 threads increment them at the same time and print
    it resulting it getting incremented only 1 time.
    deadlock happens when a resource required by a thread_1 is held by thread_2 and resource required by thread_2 is held
    by thread_1, resulting in circular dependency kind of situation. Here, no thread can proceed further.

### Process vs threads
[Article](https://www.geeksforgeeks.org/batch/sde-theory-1/track/Introduction-to-Operating-System/article/MjU4NQ%3D%3D)
 - threads are stack of their own function calls
 - all threads have same heap segment, same data and same code
 - **threads vs process**
    - Threads are lightweight. Faster/easier to create/terminate threads
    - Multiple threads in the same process :
        - share same address space
        - Easier to communicate
        - context switching is easier ( switching context from one process to other process is computationally
        intensive. we need to store the state of the current process and we need to resume the other process. Memory mapping need to be changed
        and cache needs to be cleared, etc. However, incase of threads only stack pointer register need to change). This faster 
        especially when threads are in userspace and kernel is not involved.

### User threads vs Kernel threads
[Article](https://www.geeksforgeeks.org/batch/sde-theory-1/track/Introduction-to-Operating-System/article/ODMy)
- Simple threads which are managed by user space are user threds whereas threads managed by kernel space are kernel Threads
- **User threads**
    - context switching : Fast ( as no mode switch is required cause they are in the same
    process)
    - Blocking : One thread can block all other threads ( since kernel is not aware of user managed threds
    it blocks entire process including threads)
    - Multicore or Multi-processing : cannot take advantage of Multicore system. only concurrent execution
    on single processor i.e. while on process is doing I/O other process will do CPU utilization
    - creation / termination : Fast
- **Kernel threads**
    - context switching: Slow. Mode switch is required from user to Kernel 
    and kernel needs to be involved
    - Blocking : A thread can only block itself only
    - Multicore or Multi-processing : can take full advantage of multicore system.
    - creation / termination : Slow
- We can have both type threads in a process i.e. mix of user threads and kernel threadsSLow
- **Mapping of user threads to kernel threads** :
    - One to One : Every user thread creates a kernel thread ( most common )
    - One to Many : When we create multiple threads in a process, all are mapped to a single kernel thread 
    . This can be seen as purely user managed multi-threaded system. Context switching is faster. since, only
    kernel is managing only one thread.
    - Many to Many : Multiple user threads are mapped to multiple kernel threads

