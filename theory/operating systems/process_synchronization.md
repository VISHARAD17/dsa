## Process Synchronization

### Introduction
- All process discussed before were independent of each other. Processes might talk to each other.
- Processes:
    - independent : has their own address space and works only in that address space
    - co-operative: might need talk to each other. ex. this cmd `ps | grep 'chrome' | wc` lists all 
    the process, then finds the lines which has chrome in it and then counting words in the outpu. These three 
    processes needs to communicate with each other in order to produce the output. Here, `grep` take the 
    input from `ps` and `wc` take the input from `grep`
- this communication has be handled by operating system. Inter-process communication can happen 
in single process system ( concurrent execution - one after another) or in a muti-process system
- Process `P_1` executes partially then processe `P_2` executes partially and again process `P_1` runs, this 
interleaving exexution is called concurrent execution
- processes communicate within a system using shared memory ex. global variables
- we can see different behaviousrs / different unexpected outputs because of race conditions

### Critical Section
- Race condition : when we have inconsistent values because of different sequence of 
execution, when two processes are interlived.
Also we might get different outputs depending on the order of execution. So, there is no 
deterministic variable
- the part where we access shared variable is `critical` section and 
otherohter part it `not-critical` section
- hence, we need same machanism to ensure that one process run a critical process 
at a time
- so we put some logic before (`entry section`) and after (`exist section`) critical section
- critical section comes when we have write/modify operation on a shared variable

### Goals of Synchronization mechanism :
- `Mutual exclusion`: only one process is allowed to enter critical sectionExecution
- `Progress`: processes that do not need/wish to enter critical section should not 
be blocking other processes. So, only processes that requires critical section should 
only compete
- `Bounded waiting / Fairness` : it should not happen that a process is waiting forever 
to entire into critical section and other processes are getting to use critical section 
again and again or processes comming after it are getting to use critical section.
Hence, there should be bound on waiting for critical section 
- `performance`: locking mechanism that allows one process at a time to enter into 
critical section should be fast. Types of locking mechanisms: hardware and software

### Overview of Synchronization mechanisms :
- `Disabling interepts` : a process before entiring into a critical section declares 
that it should not be interepted while doing its execution. This only works for single 
processor system. OS disables other processes from entering into the critical section.
This might accquire system forever and disables other process from happneing( serious issue )
Hence, not fesible, can cause security issues as well.
- `Locks ( Mutex )` : acquire the lock, then enter the critical section then release the lock.
they can be implmented in software and hardware. Whereas hardware is mnost common, because its 
fast.
- `Semaphore` : It has two things signal and wait. When a process enters a critical section
it causes wait and when it's done then it causes single which means other processes can 
enter into critical section. these signal and wait processes need to be atomic, to ensure 
they are atomic they uses locks
- `Monitors`:
    - monstly used for threads synchronization.
    - it is implemented in Java. JVM ( java virtual machine ) manages the synchronization 
    hence, it is a software solution.
    - They operate at a higher level than semaphore.
    - Instead of putting enter and exit section, before and after resp. of a critical 
    section. All the shared variables and the methods modifying shared variables are put 
    in a same class. All methods in that class are declared synchronous. So that, single 
    process / single thread can run at a time.

### `Lock` mechanism for synchronization :
- They mechanism are used to build mechanisms like semaphore, Monitors, etc.
- notes on locs  
