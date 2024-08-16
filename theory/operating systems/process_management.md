### Process Management
- Program is something that resides on the hardware ( ex. code file ) and compiler converts it into 
binary programe - this file ( a.out for c++ ) also exists on hard disk. This binary program is then
loaded into the ram and then run by the processor. So, **process is a program is execution**
- this is how `program` looks in memory :

```
    |------------|
    |            |
    |   Stack    |
    |            |
    |------------|
    | Heap       |
    |------------|
    | text / code|
    |------------|
    | Data       |
    |____________|
```
`Data` - stores static and global variables

`text/code` - binary code to be executed

`heap` - Dynamatically allocated memory( grows upwords)

`stack` - stores functions calls and their local variables( grows downwards)

when we run the program it becomes a process

### Process State
- **Single tasking systems**: After finishing one command only we can run the next command

Mutiprogramming System `5 state model` :

![Process flow diagram](./diagrams/process_state_pic_1.png)

- Multi-tasking is doing processes whithin give time slots, process waits when its time slot is over,
then resumes again when given a time slot
- `New` - just clicked on the file and process control information is created by the OS but not loaded into 
the RAM 
- `Ready` : Once process is loaded in the memory, it is in ready state. It is ready to picked by the processor.
it is assigned by to a processor by a dispatcher.
- `Running` : Once the process is dispatched it is running state means it is assigned to CPU ( processor ) and now
it is doing its computations. when a higher priority tasks comes to the CPU then the current process goes to `ready` State
or when there is a timeout i.e. the assigned time to the process is over and process is still not finished then again it goes 
to `Ready` state.
- `Waiting`: this state happens when IO is requested during execution, then it goes back to `ready` state 

Mutiprogramming system `7 state model`:

![Process flow diagram state 7](./diagrams/7_state_model.png)
- `Suspend / Block` - when CPU is ideal when all process are waiting for IO then it suspends few ( sends back to hard disk)
and brings more process in RAM for better efficiency
- `Suspend/ Ready` - when suspened process in hard disk complets I/O then it goes into suspend/ready
state. ( This is also in hard disk). This is hard disk space 
is called swap space. Then it goes to ready state with CPU is free otherwise if a high-priority tasks comes up 
then it gets suspended back to suspend/ready state.

### Process Control Block
- A process can be moved from ready to running state and vice versa. It has to moved from running to ready 
when time allocated to it expires or a high priority task comes into memory. Hence, in order to resume 
the previous task from the same state where it was stoped OS must store all the information related to
the process. The process should feel like it is continuing from the same spot. All this information is 
stored in a data structure called Process control block. It is stored in a very secured place in a memory 
as to be not currupted by any user process.

- **Contents of Process control block**:
    - process ID : unique identifier assigned to every process by OS 
    - process state : state of the process ex. ready, running, etc.
    - CPU registers : process uses mutiple CPU registers to perform its operation. One of them is 
    program counter which tells next intruction to be executed. Hence, they are also stored in order 
    to run the process form the previous state where it was stopeed.
    - Accounts information : CPU time consumed so far, any systerm specific information 
    - I/O information : what I/Os process was using and what was there states. 
    - CPU scheduling information : priority of the process 
    - memory information : what all memory blocks were allocated to this process.

- these are generic fields stored in a control block, there are many more fields in today's modern complex OS.
- It is the most central data structure of the OS and used by almost all modules( ex. I/O module ) of OS

