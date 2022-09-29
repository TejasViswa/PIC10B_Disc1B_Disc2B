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
        - global variable x is assigned a value of 5
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
10
```

Let us break down what happens here:
- Within main function, fun() is called and then assigned 30
    - fun() call
        - fun() is called for the first time, thus [static](static.md) variable int is created and initialized with value 5
        - and it is now returned (because return datatype is reference)
    - fun() = 30
        - the [static](static.md) variable x that is returned gets assigned the value of 30
- Currently x holds the value 30
- Once `cout << fun()` is called, [static](static.md) variable x is NOT reassigned the value 10 (compiler ignores this because once a [static](static.md) variable is initialized, it is not initialized again) and this is returned
- Therefore, 30 is printed as the output

