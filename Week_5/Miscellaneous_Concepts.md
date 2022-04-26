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
You want to return a const reference when you return a member variable of an object, that you do not want to be modified outside of it. (It is also applicable to free functions)
For example: when your object has a name, you can write the following method:
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

## Algorithms and their Complexity

### Sequential Search

The diagram below shows how this search works. Starting at the first item in the list, we simply move from item to item, following the underlying sequential ordering until we either find what we are looking for or run out of items. If we run out of items, we have discovered that the item we were searching for was not present.

![image](https://user-images.githubusercontent.com/45400093/165247955-f26125a3-30ae-4f0c-84c4-8bb22dcfb6c3.png)

#### Time Complexity

Since a sequential search requires that we go through eah element in a vector/array until the element is found, the complexities can be explained as shown:

![image](https://user-images.githubusercontent.com/45400093/165248212-77272186-4229-4ed6-b710-05f20ec68ca5.png)

### Binary Search
Binary search is a Divide and Conquer algorithm. Like all divide-and-conquer algorithms, binary search first divides a large array into two smaller subarrays and then recursively (or iteratively) operate the subarrays. But instead of working on both subarrays, it discards one subarray and continues on the second subarray. This decision of discarding one subarray is made in just one comparison.
 
So binary search reduces the search space to half at each step. By search space, we mean a subarray of the given array where the target value is located (if present in the array). Initially, the search space is the entire array, and binary search redefines the search space at every step of the algorithm by using the property of the array that it is sorted. It does so by comparing the mid-value in the search space to the target value. If the target value matches the middle element, its position in the array is returned; otherwise, it discards half of the search space based on the comparison result.

![image](https://user-images.githubusercontent.com/45400093/165249079-b0f6af17-36dd-4fc4-ad41-a3c99a5e0f8f.png)

#### Time Complexity

The question is, how many times can you divide N by 2 until you have 1? This is essentially saying, do a binary search (half the elements) until you found it. In a formula this would be this:
```
1 = N/2^x
// Multiply both sides by 2^x
2^x = N
// Taking log_2 on both sides
log_2(2^x) = log_2(N)
x * log_2(2) = log_2(N)
x * 1 = log_2(N)
x = log_2(N)
```
Thus, time complexity is O(log n).

![image](https://user-images.githubusercontent.com/45400093/165403025-4c7c0ebe-16f5-4620-a965-b8b401994eb4.png)

Another way of solving this:

we can establish a recurrence relation T(n)=T(n/2)+1

T(n/2)= T(n/4)+1 therefore T(n)= T(n/4)+2

T(n/4)= T(n/8)+1 therefore T(n)= T(n/8)+3

we can establish a relation

T(n) = T(n/(2^k))+k ----------lets call this as equation 1

and we keep on expanding, we will reach a point where

2^k = n, applying log on both sides

log(2^k) = log(n)

therefore k = log(n)
putting this value of k in equation 1

T(n) = T(n/(2^(log(n)))) + log(n)

therefore T(n) = T(n/n) + log(n) therefore T(n) = T(1) + log(n)

hence T(n) = log(n)
