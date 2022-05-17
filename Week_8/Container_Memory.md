# Containers and Memory Allocation:

[Vector Memory Allocation](https://stackoverflow.com/questions/8036474/when-vectors-are-allocated-do-they-use-memory-on-the-heap-or-the-stack#:~:text=So%20no%20matter%20how%20you,always%20allocated%20on%20the%20heap%20.)

Allocators are objects responsible for encapsulating memory management. std::allocator is used when you want to separate allocation and do construction in two steps. It is also used when separate destruction and deallocation is done in two steps.

All the STL containers in C++ have a type parameter Allocator that is by default std::allocator. The default allocator simply uses the operators new and delete to obtain and release memory.

Declaration :
```
template <class T> class allocator;
```

Member functions associated with std::allocator() :

- address: It is used for obtaining the address of an object although it is removed in C++20.
- construct: It is used to construct an object.It is also removed in C++20.
- destroy: It is used to destruct an object in allocated storage.It is also removed in C++20.
- max_size: It returns the largest supported allocation size.It is deprecated in C++17 and removed in
C++20.
- allocate: Used for allocation of memory.
- deallocate: Used for deallocation of memory.

Eg1:
```c++
// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
using namespace std;
int main()
{
  
    // allocator for integer values
    allocator<int> myAllocator;
  
    // allocate space for five ints
    int* arr = myAllocator.allocate(5);
  
    // construct arr[0] and arr[3]
    myAllocator.construct(arr, 100);
    arr[3] = 10;
  
    cout << arr[3] << endl;
    cout << arr[0] << endl;
  
    // deallocate space for five ints
    myAllocator.deallocate(arr, 5);
  
    return 0;
}
```
Output:
```
10
100
```
Eg2:
```c++
// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
#include <string>
using namespace std;
  
int main()
{
  
    // allocator for string values
    allocator<string> myAllocator;
  
    // allocate space for three strings
    string* str = myAllocator.allocate(3);
  
    // construct these 3 strings
    myAllocator.construct(str, "Welcome");
    myAllocator.construct(str + 1, "to");
    myAllocator.construct(str + 2, "UCLA");
  
    cout << str[0] << str[1] << str[2];
  
    // destroy these 3 strings
    myAllocator.destroy(str);
    myAllocator.destroy(str + 1);
    myAllocator.destroy(str + 2);
  
    // deallocate space for 3 strings
    myAllocator.deallocate(str, 3);
}
```
Output:
```
WelcometoUCLA
```
Advantage of using std::allocator

- allocator is the memory allocator for the STL containers. This container can separate the memory allocation and de-allocation from the initialization and destruction of their elements. Therefore, a call of vec.reserve(n) of a vector vec allocates only memory for at least n elements. The constructor for each element will not be executed.
- allocator can be adjusted according to the container of your need, for example, vector where you only want to allocate occasionally.
- On the contrary, new doesn’t allow to have control over which constructors are called and simply construct all objects at the same time. That’s an advantage of std:: allocator over new
