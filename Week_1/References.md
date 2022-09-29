# References

What is the output for the following piece of code?
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
