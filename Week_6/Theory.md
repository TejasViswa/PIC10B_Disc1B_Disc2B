# Theory

## new
The new operator is an operator which denotes a request for memory allocation on the Heap. If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. When you create an object of class using new keyword(normal new).

The memory for the object is allocated using operator new from heap.
The constructor of the class is invoked to properly initialize this memory.

```c++
// operator new example
#include <iostream>     // std::cout
#include <new>          // ::operator new

struct MyClassA {
  int data[100];
  MyClass() {std::cout << "constructed [" << this << "]\n";}
};

struct MyClassB {
  int data;
  MyClass() {std::cout << '*';}  // print an asterisk for each construction
};

int main () {

  MyClass * p1 = new MyClassA;
      // allocates memory by calling: operator new (sizeof(MyClass))
      // and then constructs an object at the newly allocated space

  std::cout << "constructed : ";
  // allocates and constructs five objects:
  MyClass * p2 = new MyClass[5];
  std::cout << '\n';
  
  delete[] p2;
  delete p1;

  return 0;
}

```
Output:
```c++
constructed [0x8f0f70]
constructed : *****
```
### What is difference between instantiating an object using new vs. without?
- With new： Call operator new function to get dynamic memory(heap), and then to call the constuctor function.
- Without new: Will not call operator new function, just directly to call the constuctor function. The stack will be used directly instead of heap memory.

[Further Reference](https://stackoverflow.com/questions/3673998/what-is-difference-between-instantiating-an-object-using-new-vs-without#:~:text=Use%20new%EF%BC%9A%20Call%20operator%20new,directly%2C%20no%20use%20to%20malloc.)

## delete
Delete is an operator that is used to destroy array and non-array(pointer) objects which are created by new expression.
 

Delete can be used by either using Delete operator or Delete [ ] operator
New operator is used for dynamic memory allocation which puts variables on heap memory.
Which means Delete operator deallocates memory from heap.
Pointer to object is not destroyed, value or memory block pointed by pointer is destroyed.
The delete operator has void return type does not return a value.

Therefore, following code snippet does not cause any change and gives no error.
```c++
// ptr is NULL pointer
int* ptr = NULL;
 
// deleting ptr
delete ptr;
```
[Further Reference](https://www.geeksforgeeks.org/delete-in-c/)
