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

## Copy Constructor
A copy constructor is a member function that initializes an object using another object of the same class.

The default constructor does only shallow copy. Whereas copy constructor allows for deep copy.
![image](https://user-images.githubusercontent.com/45400093/166435502-8f136627-0f86-48df-be76-b4feb5e48177.png)

```c++
#include<iostream>
using namespace std;
 
class Point
{
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }
 
    // Copy constructor
    Point(const Point &p1) {x = p1.x; y = p1.y; }
 
    int getX()            {  return x; }
    int getY()            {  return y; }
};
 
int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here
 
    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();
 
    return 0;
}
```
Output:
```
p1.x = 10, p1.y = 15
p2.x = 10, p2.y = 15 
```
[Further Reference](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)

## When is a Copy Constructor called?
The Copy constructor is called mainly when a new object is created from an existing object, as a copy of the existing object. 

In C++, a Copy Constructor may be called for the following cases: 

1) When an object of the class is returned by value. 
2) When an object of the class is passed (to a function) by value as an argument. 
3) When an object is constructed based on another object of the same class. 
4) When the compiler generates a temporary object.

```c++
// CPP Program to demonstrate the use of copy constructor
#include <iostream>

using namespace std;
  
class storeVal {
public:
    // Constructor
    storeVal() {}
    // Copy Constructor
    storeVal(const storeVal& s)
    {
        cout << "Copy constructor has been called " << endl;
    }
};
  
// Driver code
int main()
{
    storeVal obj1;
    storeVal obj2 = obj1;
    getchar();
    return 0;
}
```
Output:
```
Copy constructor has been called 
```

[Further Reference](https://www.geeksforgeeks.org/when-is-a-copy-constructor-called-in-cpp/)
### Copy Constructor vs Assignment Operator
[Further Reference](https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/)

[Additional Reference](https://www.geeksforgeeks.org/copy-constructor-argument-const/)

[Additional Reference](https://www.geeksforgeeks.org/copy-elision-in-c/)
