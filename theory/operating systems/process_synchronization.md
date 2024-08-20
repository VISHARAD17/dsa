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
- 
