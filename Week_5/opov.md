# General Format for Operator Overloading

## Some general rules for declaring operator overloading:
- When to declare operator overloading function as a free function or member function?
  - If the operator is binary:
    - If the operator is compound / updation operator (operator that modifies the object itself)-> make it a member function
      - eg: +=, -=, *=, /=, %=
    - If the operator does not update any particular object -> make it a free function (either separately defining outside the class or using the friend keyword within the class)
      - eg: +, -, *, /, %
    - If first operator is of a class that you cannot access (eg:ostream class) -> make it a free function (either separately defining outside the class or using the friend keyword within the class)
      - eg: <<, >>
  - If the operator is unary -> make it a member function
     - eg: ++(pre), ++(post), --(pre), --(post)
```diff
- Note: Exceptions exist for all these rules
```
- When to declare a free function within the class using a friend?
  - In general, whenever the operator needs access to the member variables which are private then you would use the friend keyword. If the implementation does not need access to the provate variables and can instead be accomplished with the help of the public member functions then you can avoid having to use the friend keyword and instead declare the function outside the class as a free function.
- When to use the const keyword for the functions?
  - Whenever we have a accessor function (ie: a function that does not modify any of the member variables), then we can declare it as a const
- When do we use explicit?
  - We use explicit when we want to avoid ambiguity between any candidate functions or when we don't want any implicit conversion taking place.
  - eg: 
    ```c++
    explicit operator size_t () const;
    ```
- When do we use delete?
  - if we do not want the compiler to not consider a certain function (usually a candidate function that is not declared and called after one or more of the operands are implicitly casted), then we delete its declaration by using the delete keyword.
  - eg:
    ```c++
    return_type operator+(operand1_datatype,operand2_datatype) = delete;
    ```
   

