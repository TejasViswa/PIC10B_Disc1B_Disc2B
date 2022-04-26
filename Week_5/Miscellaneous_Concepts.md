# Miscellaneous Concepts

## Static Keyword in a free function

When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call.

```c++
// C++ program to demonstrate 
// the use of static Static 
// variables in a Function
#include <iostream>
#include <string>
using namespace std;
  
void demo()
{ 
    // static variable
    static int count = 0;
    cout << count << " ";
      
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}
  
int main()
{
    for (int i=0; i<5; i++)    
        demo();
    return 0;
}
```
Output:
```
0 1 2 3 4 
```
You can see in the above program that the variable count is declared as static. So, its value is carried through the function calls. The variable count is not getting initialized for every time the function is called.

## Returning const references

### Why return const references?
You want to return a const reference when you return a property of an object or a variable, that you do not want to be modified outside of it. For example: when your object has a name, you can write the following method:
```c++
const std::string& get_name(){ return name; };
```
### When should you use a const reference parameter?
When passing an argument by reference, always use a const reference unless you need to change the value of the argument.(Additional info: Non-const references cannot bind to r-values. A function with a non-const reference parameter cannot be called with literals or temporaries.)

### When should you return by reference?
When it's okay to modify the value of the variable that is referenced.

### What does it mean if a reference is returned and how can you get undefined behaviour?
It basically means the returned value is an alias to whatever you returned from the function.
When returning a reference, be careful that the object being referred to does not go out of scope. So it is not legal to return a reference to local var. But you can always return a reference on a static variable. This is when you enter undefined behaviour.

eg:
```c++
#include <iostream>

using namespace std;

const int& foo(){
  int x = 5;
  return x;
}
int main() {
  int y = 0;
  y = foo();
  cout<<y;  // The output may or may not be 5
  return 0;
}
```

