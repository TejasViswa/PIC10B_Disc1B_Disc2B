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

## Recursion

The process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called as recursive function.

### how does this look mathematically?
Let us consider a problem that a programmer have to determine the sum of first n natural numbers, there are several ways of doing that but the simplest approach is simply add the numbers starting from 1 to n. So the function simply looks like,
```
// approach(1) – Simply adding one by one

f(n) = 1 + 2 + 3 + . . . . + n
```
but there is another mathematical approach of representing this,
```
// approach(2) – Recursive adding 

f(n) = 1             n=1

f(n) = n + f(n-1)    n>1
```
There is a simple difference between the approach (1) and approach(2) and that is in approach(2) the function “ f( ) ” itself is being called inside the function, so this phenomenon is named as recursion and the function containing recursion is called recursive function, at the end this is a great tool in the hand of the programmers to code some problems in a lot easier and efficient way.

### What is base condition in recursion? 
In the recursive program, the solution to the base case is provided and the solution of the bigger problem is expressed in terms of smaller problems.
```c++
#include <iostream>
using namespace std;

int factorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
```
Output:
```c++
Enter a non-negative number: 4
Factorial of 4 = 24
```
In the above example, base case for n < = 1 is defined and larger value of number can be solved by converting to smaller one till base case is reached.

### Working of factorial program

![image](https://user-images.githubusercontent.com/45400093/165243555-02eb5b8e-1265-4fab-855a-d33123ed87da.png)

As we can see, the factorial() function is calling itself. However, during each call, we have decreased the value of n by 1. When n is less than 1, the factorial() function ultimately returns the output.
