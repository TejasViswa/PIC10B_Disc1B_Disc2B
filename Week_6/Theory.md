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
