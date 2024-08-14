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
