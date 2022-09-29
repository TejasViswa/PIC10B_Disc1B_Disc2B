# Static Variables

Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope. 
Syntax: 
```c++
static data_type var_name = var_value; 
```
A static variable remains in memory while the program is running. A normal variable is destroyed when a function call where the variable was declared is over. 
For example, we can use static int to count a number of times a function is called, but a normal variable can’t be used for this purpose.
```c++
#include<iostream>
int fun()
{
  static int count = 0;       // using static
  count++;
  return count;
}
  
int main()
{
  cout << fun();
  cout << fun();
  return 0;
}
```
Output
```
1 2
```
But if we use a normal variable, then:
```c++
#include<iostream>
int fun()
{
  int count = 0;       // using regular variable
  count++;
  return count;
}
  
int main()
{
  cout << fun();
  cout << fun();
  return 0;
}
```
Output
```
1 1
```

### NOTE: Once a static variable is declared / initialized in a function, that line is not called again. In the above program with the static example, the function is called twice but the value of count is 2. It does not become 0 again and get incremented. The line with static is executed only once in a program and never again. if the compiler sees it again, it is ignored.
