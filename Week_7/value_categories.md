# Value Categories

## Expressions
- Sequence of operators and their operands which specify some computation process
- [Reference](https://en.cppreference.com/w/cpp/language/expressions)
- characterized by two factors:
	- data type
	- value category
- may produce a result
- may generate side-effects

## Value Categories
- Every expression is either an lvalue or an rvalue
- an lvalue is not an rvalue and an rvalue is not an lvalue
- Value categories properties of expressions
	- has identity
		- does the expression have a name
		- does the expression have a memory location
		- can you take the address of the expression

## lvalue and rvalues
- An ==lvalue== is an expression referring to an object (an object is a region of storage)
	- typically an entity which has a name
	- lifetime persists beyond the current statement
	- must be able to take the address of using the & operator

`Widget *button = new Widget;`
- button is an lvalue, data type "pointer to Widget"
	- has a name
	- can take the address of button
- `*button` is an lvalue
	- does not actually have a name
	- can take the address of `*button`
```c++
int foo1 = 7;
foo1 = 9;    // this is an lvalue

const int foo2 = 7;
foo2 = 9;    // this is also an lvalue
```

-  An ==rvalue== is anything that isn't an lvalue (not so obvious later on)
	- typically an entity which does not have a name
	- lifetime usually ends with the current statement
	- may not be able to take the address of the entity
	- a temporary value
	- a literal such as 42, true, or nullptr
	- enums, return values of functions, results of operations
`int someVar = 35`
- the data type of someVar is int, it is an lavlue
- the stat type of 35 is int, it is an rvalue
`35 = someVar;`
- this is not legal code since 35 is an rvalue and it located on the left side of this expression

### Why does this distinction exist?
- It is to let the compiler know if the expression occupies space (data storage)

### Literals
- Most literals are rvalues, including:
	-  3, 3.1415, 'a'
- However, character string literals, such as "xyzzy", are lvalues as they occupy data storage (because we need to be able to iterate through them)

### Lvalues used as rvalues
- lvalue can appear on either side of assignment:
```c++
int m,n;
m = n;        // OK: m and n are both lvalues
```
- you can assign the value in n to the object designated by m
- Officially, C++ performs an lvalue-to-rvalue conversion

### operands of other operators
- Concept is similar in other operands like `+`
```c++
int x;

~~~ x + 2 ~~~ // OK: lvalue + rvalue
~~~ 2 + x ~~~ // OK: ravlue + lvalue
```
- The return value of an addition, say `m + n` is stored in a compiler generated temporary object (often a CPU register) and this is an rvalue
- Thus `m + 1 = n;` is an error because it yields an rvalue and it does not have a physical location that is gets assigned to
- ==Unary `*`== yields an lvalue
```c++
int a[N];
int *p = a;
char *s = nullptr;

*p = 3;      // OK
*s = '\0';   // undefined behaviour (reason is not due to lvalue[this assignment is fine] but simply because s is a null pointer)
```

### Data storage
- Ideally, rvalue don't occupy data storage but in some situations like when an abnormally large value is given, then a compiler uses storage
- And ideally lvalues always occupy storage but some compilers might forgo this in certain cases when optimizers are involved
- A programmer needs to only think of ideal cases and assume as such
- But an rvalue of class type usually occupies some storage unlike built-in types

### Non-modifiable lvalues
- lvalues are generally modifiable but it becomes non-modifiable if it has a const-qualified type
```c++
char const name[] = "dan";
~~~
name[0] = 'D';                // errror: name[0] is const

// name[0] is an lavlue, but it's non-modifiable
// Each element of a const array is itself const

int const MAX = 100;

// You can't assign to it similar to an rvalue
MAX += 3;                    // error: MAX is non-modifiable

// But you can take its address
int const *p = &MAX;         // OK: MAX is an lvalue
```

### Behaviour
| Type                    | can take the address of | can assign to |
| ----------------------- | ----------------------- | ------------- |
| lvalue                  | yes                     | yes           |
| non-modifiable lvalue | yes                     | no            |
| (non-class) rvalue      | no                      | no            |

[References](References.md)
