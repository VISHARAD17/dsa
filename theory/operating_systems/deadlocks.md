## Deadlocks

### Introduction
- When a process is ran it requires lot of resources ex. files to read, printer to print, etc. This resources are provided
by the operating system in proper manner. Here, some resources might be non-shareable i.e. one process at a time.
- Deadlock situation: 
    Assume two processes `p1` & `p2` and two resources `r1`(printer) & `r2`(file which needs to be written, non-shearable task)
    now, `p1` is using `r1` and `p2` is using `r2`, when `p1` needs to write to a file `r2` is goes into waiting mode for that
    perticular resources. Similar, to `p2` when it needs to print something `r1`. This creates a dependecy kind of 
    loop that one process it waiting for another to finish ( circular wait )
    This, situation is known as deadlock
- Neccessory conditions for deadlock:
    - Mutual Exclusion ( all resources are non-shearable )
    - Hold and wait 
    - No resource preemption ( cannot preempt the resource when a process is using it )
    - Circular wait
- if there is deadlock in system, then no progress can happen 
- Resource allocation graph
- [resource-allocation-graph](./diagrams/deadlock_resource_allocation_graph.png)
