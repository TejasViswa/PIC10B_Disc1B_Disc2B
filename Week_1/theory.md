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

## Explicit Casting

- In general, there are mainly 4 types of C++ style casting and 1 C style casting typically used for explicit casting.
- The 4 types of C++ casting are:
  - dynamic_cast
    - This only allows casting from derived to base classes. (If you don't know what this means, that is fine. Just know that this is a good kind of cast)
    - [Further Reading](https://en.cppreference.com/w/cpp/language/dynamic_cast)
  - static_Cast
    - This allows casting between related classes. It can be between base to derived or derived to base. (This is also the good kind of cast)
    - [Futher Reading](https://en.cppreference.com/w/cpp/language/static_cast)
  - reinterpret_cast
    - This allows for casting between any classes that have the same size and they need not be related. If two classes have the same size, then on class can be reinterpreted bitwise into another class. (This is the bad kind of cast. Do not use this unless you really have to)
    - [Further Reading](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
  - const_Cast
    - This allows for casting between non const to const classes and vice versa. (Only if there is an absolute requirement of doing this, avoid using this cast)
    - [Further Reading](https://en.cppreference.com/w/cpp/language/const_cast)
- Finally, the C-style cast is actually a sequence of combination of const, static and reinterpret casting internally. And, therefore, it does not give you a compiler error when trying to casting two unrelated classes. Thus, we need to avoid using C-style casting.
- Therefore, in general, use static_cast always and avoid C-style and reinterpret casting as much as possible.
- [Further Reading](https://en.cppreference.com/w/cpp/language/explicit_cast)

## const correctness

- In general, whenever you look at the keyword 'const', think of it as 'readonly'. Meaning that you can cannot directly manipulate or influence a variable that is const but you can influence it by indirect means (aliasing through another variable / referencing it).
- Whenever you have a class/user defined datatype as the argument of a function, then it is always better to pass by reference with a const in order to avoid direct manipulation within the function. For eg:
  ```c++
  function(const datatype& var_name){
    some statements;
  }
  ```
- Whenever you have a fundamental datatype as an argument to a function, then it is usually fine to pass by reference or value because the size of the variable would be too small to make any significant effect on performance. Therefore, the need to use to a reference arises only if you are going to need to manipulate a variable that you are using within the manin routine.

## lvalues, rvalues and their references

- in general, most things within C++ are expressions and they are generally grouped into either lvalues or ravlues (There is actually a bigger and more generalized hierarchy that also includes glvalues(Generalized lavlues), prvalues(Pure rvalues), xvalues(eXpiring values), etc but that is currently beyond the scope of this discussion).
- Let begin with an lvalue. What do you mean by an lvalue? Let us look at the following code snippet for example:
  ```c++
  int a;
  a = 5;
  ```
  From , our understanfing of C++ so far, we realize that in those two lines of code that first there is a variable that is declared and then later it is initialized in the next line. But, from the compiler point of view, a is an lvalue and 5 is an rvalue and the value at the memory location that a has is now holding a value of 5.
- From our vague understanding of the above code, we can somewhat guess that lvalue is the value that appears on the left hand side of the assignment operator and rvalue is the value that appears on the right hand side of the assignment operator. But, this need not always be true because we can also write the following perfectly valid C++ code snippet as well and there won't be any compiler error:
  ```c++
  int b;
  b = a + 5;
  ```
  Now, notice that a is, in fact, on the right hand side of the assignment operator and is still perfectly valid statement. But now, lets switch things up.
- Do you think the following code is reasonable?
  ```c++
  int c = 6;
  b + 5 = c;
  ```
  We quickly realize that this is not allowed and will actually give you a compiler error. b + 5 cannot be assigned a value of c as this does not meaning sense to the compiler. This is where programming and mathematics differ as the two symbols '=' have very different meanings and is therefore split between both the assignment '=' and equality '==' operators.
- So, now, we can generalize that a lvalue can exist on both sides of the assignment operator but an rvalue can allow exist on the right hand side of it. Historically, lvalue has been used to denote expressions on the left hand side but in recent times, its name has also been changed to 'locator value' in some languages, in order to avoid this confusion.
- But what exactly is an lvalue? It is actually anything (by anything, I actually mean a variable, struct, union, etc) that can store hold some information in a memory location.
- And what is an rvalue? It is actually the data(could be the value from a variable, literal, expression, etc) stored at some address/memory location.
- So, when you actually use an assignment operator, any expression on the right hand side must evaluate to an rvalue (ie: give you a value that you can store) which can be stored into an lvalue (ie: a memory location).
- An lvalue looks like the references you have used so far and an rvalue reference uses two ampersand '&' symbols instead of one:
  ```c++
  int x = 5;
  int& lref = x;
  int&& rref = 20;
  ```
  The ampersand '&' symbol is also called the 'address of' symbol and takes in an lvalue as an operand and outputs its memory location
- [Further Reading](https://www.fluentcpp.com/2018/02/06/understanding-lvalues-rvalues-and-their-references/#:~:text=Now%20an%20lvalue%20reference%20is,with%20two%20ampersands%20(%26%26).)