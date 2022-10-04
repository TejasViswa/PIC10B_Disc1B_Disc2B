# References

## 1. What is the output for the following piece of code?
```c++
#include <iostream>
using namespace std;

int fun(int& x) { return x; }

int main()
{
	cout << fun(10);
	return 0;
}
```
Hint: Its not 10...

Well, unfortunately, the code never compiles. It gives you an error:
```c++
error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
  cout << fun(10);
                ^
```
Read about [rvalues](theory.md#lvalues-rvalues-and-their-references)

But basically, we can't assign literals ([temporaries or rvalues](theory.md#lvalues-rvalues-and-their-references)) [ie: 5, 'a', etc] to references.
`int&` can only accept variables of datatype int ([lvalues](theory.md#lvalues-rvalues-and-their-references) with datatype int)

Therefore, we can fix the above code as:
```c++
#include <iostream>
using namespace std;

int fun(int& x) { return x; }

int main()
{
	int y = 10;
	cout << fun(y);
	return 0;
}
```
Output
```
10
```
Note: While references always have to be initialized, it does not mean that the variable that it is referring has to be initialized. In the above example if y was not initialized, the code still executes fine but the value printed is random/unknown.

## 2. What is the output of the following code snippet?
```c++
#include <iostream>
using namespace std;

int& fun()
{
	int x = 10;
	return x;
}

int main()
{
	fun() = 30;
	cout << fun();
	return 0;
}
```

It doesn't compile and gives you the following warning:
```
warning: reference to local variable 'x' returned [-Wreturn-local-addr]
  int x = 10;
      ^
```

We are trying to return a reference to a variable that doesn't exist anymore. Even if the code executes, it gives you undefined behaviour.

One way to fix this code with minimal changes is:
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

We use the '[static](static.md)' keyword for the local variable so that it doesn't expire after the function call. [Static](static.md) variables have a lifetime that is usually for the entire duration of the program. But remember, the [scope/visibility](scope.md) of the variable is still local, meaning, you cannot manipulate the variable outside the function.

```c++
#include <iostream>
using namespace std;

int main()
{
    {
    	int x = 5;
    }              // x dies here
    cout << x;
    return 0;
}
```
In this code snippet, the [lifetime and scope](scope.md) of the variable x are only within the same code block. ie: We can't access it after the "}".

The **[scope](scope.md)** of a variable refers to the areas or the sections of the program in which the variable can be accessed, and the **[lifetime](scope.md)** of a variable indicates how long the variable stays alive in the memory.

## Please refer to [Return by Reference](Ret_by_ref.md)
