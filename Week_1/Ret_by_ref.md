# Return by References

Please go through [scope](scope.md) and [static](static.md) before you read this section

Take a look at the following code:
```c++
#include <iostream>
using namespace std;

int x = 10;

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
