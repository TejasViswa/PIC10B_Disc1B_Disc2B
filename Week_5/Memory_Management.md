# Memory Management

We write a C++ program and execute it, the operating system of the computer allocates a process which performs all the task mentioned in the program.
Our program gets assigned a process and each process is allocated some memory and which is divided into below-mentioned segments:

1. Text segment  (i.e. instructions)
2. Initialized data segment 
3. Uninitialized data segment  (bss)
4. Heap 
5. Stack

![image](https://user-images.githubusercontent.com/45400093/165229167-26d860d6-0b7b-4f69-919a-a38dd886c00b.png)

By convention, we express these addresses in base 16 numbers. For instance, the smallest possible address is 0x00000000 (where the 0x means base 16), and the largest possible address could be 0xFFFFFFFF.

## Text Segment:
A text segment, also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions.(Basically, all your lines of code go here) 
Usually, the text segment is sharable so that only a single copy needs to be in memory. Also, the text segment is often read-only, to prevent a program from accidentally modifying its instructions.

## Initialized Data Segment: 
Initialized data segment, usually called simply the Data Segment. A data segment is a portion of the virtual address space of a program, which contains the global variables and static variables that are initialized by the programmer.
Ex: static int i = 10 will be stored in the data segment and global int i = 10 will also be stored in data segment

## Uninitialized Data Segment: 
Uninitialized data segment often called the “bss” segment, named after an ancient assembler operator that stood for “block started by symbol.” Data in this segment is initialized by the kernel to arithmetic 0 before the program starts executing. Uninitialized data segment starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.
For instance, a variable declared static int i; would be contained in the BSS segment. 
For instance, a global variable declared int j; would be contained in the BSS segment.

## Stack: 
The stack area traditionally adjoined the heap area and grew in the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted. A “stack pointer” register tracks the top of the stack; it is adjusted each time a value is “pushed” onto the stack. The set of values pushed for one function call is termed a “stack frame”; A stack frame consists at minimum of a return address.
Stack, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and certain information about the caller’s environment, such as some of the machine registers, are saved on the stack. The newly called function then allocates room on the stack for its automatic and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself, a new stack frame is used, so one set of variables doesn’t interfere with the variables from another instance of the function.

## Heap: 
Heap is the segment where dynamic memory allocation usually takes place.
The heap area begins at the end of the BSS segment and grows to larger addresses from there. The Heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single “heap area” is not required to fulfill the contract of malloc/realloc/free; they may also be implemented using mmap to reserve potentially non-contiguous regions of virtual memory into the process’ virtual address space). The Heap area is shared by all shared libraries and dynamically loaded modules in a process.

## Stack vs Heap Memory Allocation

### Stack Allocation

The allocation happens on contiguous blocks of memory. We call it a stack memory allocation because the allocation happens in the function call stack. The size of memory to be allocated is known to the compiler and whenever a function is called, its variables get memory allocated on the stack. And whenever the function call is over, the memory for the variables is de-allocated. This all happens using some predefined routines in the compiler. A programmer does not have to worry about memory allocation and de-allocation of stack variables. This kind of memory allocation also known as Temporary memory allocation because as soon as the method finishes its execution all the data belongs to that method flushes out from the stack automatically. Means, any value stored in the stack memory scheme is accessible as long as the method hasn’t completed its execution and currently in running state.

#### Key Points:

- It’s a temporary memory allocation scheme where the data members are accessible only if the method( ) that contained them is currently is running.
- It allocates or de-allocates the memory automatically as soon as the corresponding method completes its execution.
- Stack memory allocation is considered safer as compared to heap memory allocation because the data stored can only be accessed by owner's thread.
- Memory allocation and de-allocation is faster as compared to Heap-memory allocation.
- Stack-memory has less storage space as compared to Heap-memory.

eg:

![image](https://user-images.githubusercontent.com/45400093/165233758-a8fb2522-fa62-4ae6-af18-46f69ad73859.png)

Since the stack memory of a function gets deallocated after the function returns, there is no guarantee that the value stored in those area will stay the same. A common mistake is to return a pointer to a stack variable in a helper function. After the caller gets this pointer, the invalid stack memory can be overwritten at anytime. The following figure demonstrate one example of such scenario. Assume there is a Cube class that has methods getVolume and getSurfaceArea, as well as a private variable width. ('->' operator is used to access the functions inside a pointer object)

![image](https://user-images.githubusercontent.com/45400093/165234139-c6f157db-b0d0-41f1-9f8c-43dee025db66.png)


### Heap Allocation

The memory is allocated during the execution of instructions written by programmers. Note that the name heap has nothing to do with the heap data structure. It is called heap because it is a pile of memory space available to programmers to allocated and de-allocate. Every time when we made an object it always creates in Heap-space and the referencing information to these objects are always stored in Stack-memory. Heap memory allocation isn’t as safe as Stack memory allocation was because the data stored in this space is accessible or visible to all threads. If a programmer does not handle this memory well, a memory leak can happen in the program.

#### Key Points

- This memory allocation scheme is different from the Stack-space allocation, here no automatic de-allocation feature is provided. We need to use a Garbage collector to remove the old unused objects in order to use the memory efficiently.
- The processing time(Accessing time) of this memory is quite slow as compared to Stack-memory.
- Heap-memory is also not threaded-safe as Stack-memory because data stored in Heap-memory are visible to all threads.
- Size of Heap-memory is quite larger as compared to the Stack-memory.
- Heap-memory is accessible or exists as long as the c++ program runs.

eg:

In the previous section we saw that functions cannot return pointers of stack variables. To solve this issue, you can either return by copy, or put the value at somewhere more permanent than stack memory. Heap memory is such a place. Unlike stack memory, heap memory is allocated explicitly by programmers and it won’t be deallocated until it is explicitly freed. To allocate heap memory in C++, use the keyword new followed by the constructor of what you want to allocate. The return value of new operator will be the address of what you just created (which points to somewhere in the heap).

![image](https://user-images.githubusercontent.com/45400093/165234842-1b2f3898-cb8d-4150-9429-5c7069047bef.png)

You may notice in the above example that even at the end of the program, the heap memory is still not freed. This is called a memory leak.
Memory leaks in small programs might not look like a big deal, but for long-running servers, memory leaks can slow down the whole machine and eventually cause the program to crash.

To free heap memory, use the key word delete followed by the pointer to the heap memory. Be careful about the memory you freed. If you try to use the pointers to those memory after you free them, it will cause undefined behavior. To avoid such issues, it is good practice to set the value of freed pointers to nullptr immediately after delete. Here is an example that correctly frees memory after using it.

![image](https://user-images.githubusercontent.com/45400093/165235051-c39f50e4-26fb-4bf4-939e-afc00ee2b742.png)
