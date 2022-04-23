# Operator Overloading Tips:

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
- How is operator overloading resolved?
  - The compiler chooses the from its list of suitable candidates which it can call for the function. The function with the least amount of effort(implicit casting) is selected.
  - Sometimes, when there are multiple equally suitable candidates available, the compiler gets confused and calls the function call ambiguous meaning that the overloading could not be resolved. Then either deleting the other candidates or making the cast explicit will help in resolving the situation. Another solution could be create a separate a function with those specific operands but this solution would be too specific to the scenario and would not help in all the cases.

## General Format for Operator Overloading

### Unary Operator+,-
```c++
X X::operator- () const {
  return /* a negative copy of *this */;  
}

X X::operator+ () const {
  return *this;
}
```

### Binary Operator+,-,*,/,%
```c++
// Make sure +=,-=,*=,/=,%= are implemented

X operator+ (X const& lhs, X const& rhs) {
  X tmp(lhs);
  tmp += rhs;
  return tmp;
}

// Similar implementations follow for -,*,/,%
```

### Operator <<,>>
```c++
ostream& operator<< (ostream& os, X const& x) {
  os << /* the formatted data of rhs you want to print */;
  return os;
}

istream& operator>> (istream& is, X& x) {
  SomeData sd;
  SomeMoreData smd;
  if (is >> sd >> smd) {
    rhs.setSomeData(sd);
    rhs.setSomeMoreData(smd);
  }
  // In case of failure, make sure to include add this: is.setstate(std::ios_base::failbit);
  return is;
}
```

### Operator+=,-=,*=,/=,%=
```c++
X& X::operator+= (X const& rhs) {
  //apply appropriate changes to *this
  return *this;
}
```

### Operator==,!=
```c++
bool operator== (X const& lhs, X cosnt& rhs) {
  return /* check for whatever means equality */
}

bool operator!= (X const& lhs, X const& rhs) {
  return !(lhs == rhs);
}
```

### Operator<,>,<=,>=
```c++
bool operator< (X const& lhs, X const& rhs) {
  return /* compare whatever defines the order */
}

bool operator> (X const& lhs, X const& rhs) {
  return rhs < lhs;
}

bool operator<= (X const& lhs, X const& rhs) {
  return ((rhs < lhs) || (rhs == lhs));
}

bool operator>= (X const& lhs, X const& rhs) {
  return ((rhs > lhs) || (rhs == lhs));
}

```

### Operator ++,-- (Post and Pre)
```c++
X& X::operator++() { //preincrement 
  /* somehow increment, e.g. *this += 1*/; 
  return *this; 
} 

X X::operator++(int) { //postincrement 
  X oldValue(*this); 
  ++(*this); 
  return oldValue; 
}

// Similar implementation follows for --
```

### Operator [] (with and without const overload)
```c++
// Here Element_t is the return type which is the datatype of the individual element eg: double
// Index_t is the datatype of the index eg: size_t

Element_t X::operator[](Index_t const& index){
  /* Have an if condition to check if the index is out of bounds */
  return /* Element at that index */
}

const Element_t& X::operator[](Index_t const& index) const{
  /* Have an if condition to check if the index is out of bounds */
  return /* Element at that index */
}
```


### Operator ()
```c++
Return_type X::operator() (/*variable number of arguments*/){
  return /* whatever your () should do */;
}
```


### Type conversion operators (eg:int,double,size_t)
```c++
//conversion to T, explicit or implicit
X::operator T() const{
  return /* whatever your definition of a cast to type T should return */;
}

//explicit conversion to U const&
explicit X::operator U const&() const{
  return /* whatever your definition of a cast to type U should return */;
} 

//conversion to V&
V& X::operator V&(){
  return /* whatever your definition of a cast to type V& should return */;
}
```

[Further Reference](https://arne-mertz.de/2015/01/operator-overloading-common-practice/)
