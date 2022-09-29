# Static

Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope. 
Syntax: 
```c++
static data_type var_name = var_value; 
```
Following are some interesting facts about static variables in C.
1) A static int variable remains in memory while the program is running. A normal variable is destroyed when a function call where the variable was declared is over. 
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
  static int count = 0;       // using regular variable
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
