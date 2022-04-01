# Some Additional Theory

## Loops:

- for-loop:
  - What do you think is the output of the following code snippet?
    ```c++
    for(;;){
      cout<<"hello";
    }
    ```
    If you thought that it will give you a compiler error, then you guessed wrong. Surprisingly, it gives you an infinite loop of "hello"s.
  - A for-loop without any terminating condition in the middle always evaluates to a value of 1 or true and therefore, control stays in the loop unless an additional condition is added. For eg:
    ```c++
    int n = 1;
    for(;;){
      ++n;
      cout<<"hello";
      if(n==5){
        break;
      }
    }
    ```
    Here, the control exits the loop when n reaches 5.
  - The previous snippet gives an intuition as to how we can emulate a while-loop using a for-loop:
    ```c++
    int n = 5, i = 0;
    for( ; i < n ; ){
      ++i;
      cout<<"hello";
      }
    }
    ```
  - Now that we know we can leave the expressions within the for-loop empty, we also come to another realization that the expressions within the for-loop need not be the usual initialization, termination and incrementation expression and that they could be any expressions. The following code snippets are all perfectly valid for-loops:
    - Example:
      ```c++
      int n = 0;
      for (std::cout << "Loop start\n";
           std::cout << "Loop test\n";
           std::cout << "Iteration " << ++n << '\n'){
          if(n > 1){
              break;
          }
      }
      ```
      Output:
      ```
      Loop start
      Loop test
      Iteration 1
      Loop test
      Iteration 2
      Loop test
      ```
    - Example:
      ```c++
      char cstr[] = "Hello";
      for (int n = 0; char c = cstr[n]; ++n){
          std::cout << c;
      }
      ```
      Output:
      ```
      Hello
      ```
  - [Further Reading](https://en.cppreference.com/w/cpp/language/for)
  - Finally, we arrive at what a typical for-loop for iterating through an vector should look like:
    ```c++
    // v is a vector
    for(size_t i = 0, N = v.size(); i < N; ++i){
      cout<<v[i]<<'\n';
    }
    ```
    [Why do we use size_t?](#using-size_t-instead-of-int)
    [Why do we use pre increment operator?](#overloading-post-increment-operator)
    
- while-loop:
  - Unlike the examples we have seen above, a while loop cannot have an empty expression, it will give you a compiler error. It needs an expression within the parentheses that can evaluate to 1 or true so that the control can enter within the loop.

## Using size_t instead of int

- Before explaining about size_t, let me brief a bit about typedef because size_t is a type of typedef.
- A typedef declaration is a way to shorten or alias complicated or long data types into a simpler name. For eg:
  ```c++
  typedef unsigned long long int lt;
  lt i;
  ```
  Now, lt is basically a shorthand for unsigned long long int and be used instead. Therefore, i is now a variable of type lt.
- [Further Reading](https://en.cppreference.com/w/cpp/language/typedef)
- Now, we know what a typedef is. size_t is basically a typedef that adapts according to the maximum allowable object size of the operator system. For eg: if the OS is 32 bit, then size_t is a unsigned int and if the OS is 64 bit, then it is a unsigned long long int.
- Apart from adapting to the system architecture, size_t is also an unsigned int meaning that it will always utillize twice as much space as its counterpart signed int datatype.
- Disadvantage of size_t is when you need to perform arithmetic and you encounter negative values. When -1 is assigned to a size_t variable, it is instead forced to the maximum value of its current datatype (similar to a modulo operation).
- [Further Reading](https://en.cppreference.com/w/cpp/types/size_t)

## Overloading Post Increment Operator

- A post increment operator is different from a pre increment operator in only one aspect that when it is called, an additional variable is created and the original variable's value is copied to it and incremented unlike the pre increment operator where there is no additional variable being created.
- Therefore, a pre increment operator is preferred because we avoid the copying.
- [Further Readiing](https://en.cppreference.com/w/cpp/language/operator_incdec)
