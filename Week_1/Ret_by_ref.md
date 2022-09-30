# Return by References

Please go through [scope](scope.md) and [static](static.md) before you read this section

## 1. Take a look at the following code:
(This is slightly different from the example discussed in class)
```c++
#include <iostream>
using namespace std;

int x = 5;

int& fun()
{
    x = 10;
    return x;
}
 
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}
```
Output:
```
10
```

Let us break down what happens here:
- [Global](scope.md) variable x is created and initialized as 5 and it can be accessed anywhere
- Within main function, fun() is called and then assigned 30
    - fun()
        - global variable x is assigned a value of 10
        - and it is now returned (because return datatype is reference)
    - fun() = 30
        - the [global](scope.md) variable x that is returned gets assigned the value of 30
- Currently x holds the value 30
- Once `cout << fun()` is called, [global](scope.md) variable x is now assigned the value 10 again and this is returned
- Therefore, 10 is printed as the output

## 2. Take a look at the following code:
(This is the example discussed in class)
```c++
#include <iostream>
using namespace std;

int& fun()
{
    static int x = 10;
    return x;
}
 
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}
```
Output:
```
30
```

Let us break down what happens here:
- Within main function, fun() is called and then assigned 30
    - fun() call
        - fun() is called for the first time, thus [static](static.md) variable int is created and initialized with value 10
        - and it is now returned (because return datatype is reference)
    - fun() = 30
        - the [static](static.md) variable x that is returned gets assigned the value of 30
- Currently x holds the value 30
- Once `cout << fun()` is called, [static](static.md) variable x is NOT reassigned the value 10 (compiler ignores this because once a [static](static.md) variable is initialized, it is not initialized again) and this is returned
- Therefore, 30 is printed as the output

## Understanding the above code snippet in another way:
Look at this code snippet:
```c++
#include <iostream>
using namespace std;
 
int main()
{
    int x = 5;
    int &y = x;
    y = 6;                  // or x = 6; Both have the same effect
    cout << y << " " << x;
    return 0;
}
```
Output
```
6 6
```
In this code snippet, both x and y are synonymous handles to the same memory locations and when y's value was changed, even x's value was changed. Both output 6 when printed.

### Pass by reference:
Now, lets say I split up the code into a function
```c++
#include <iostream>
using namespace std;

void fn(int &y)
{
    y = 6;
    cout<< y << " ";
}

int main()
{
    int x = 5;
    fn(x);
    cout << x;
    return 0;
}
```
Output
```
6 6
```
This is exactly the same as the previous but split up into a separate function.
- Creating variable in main
- Creating reference to that variable in function

Here, the line `int &y = x` is still executed(at beginning of the function call) but this variable y is not longer a part of the main function but it is a local variable to function `fn`. Therefore, I don't have access to y once the function call ends but every other part of the program is the same.


Now, lets us split the code in the reverse fashion
## Return by reference:
```c++
#include <iostream>
using namespace std;

int& fn()
{
    static int x = 5;
    return x;
}

int main()
{
    int &y = fn();
    fn() = 6;                 // or y = 6; Both have the same effect
    cout << y << " " << fn();
    return 0;
}
```
Output
```
6 6
```
Note: Here, instead of variable x, I'm directly using the function return to print x.
- Creating a variable in function
- Creating a reference of that variable in the main function

Here, y references x (`int &y = x` is still executed(at the end function call when it returns x)) and x can be assigned a value using the function return (everytime you see fn(), replace it with `x` in your mind) and thus both the variables' values are changed.

### NOTE: Once a reference is created, it is always attached / synonymous to the variable it is aliasing. It cannot be reassigned. so something like ` y = z` will not make y now alias z, instead it only copies the value of z to y. y will always reference x once assigned. Therefore, when I call `fn()`, I can only assign values to it and not make it reference something else. It is only giving me the reference / handle to x.
