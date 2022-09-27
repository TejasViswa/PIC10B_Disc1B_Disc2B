# Pointers and Memory

## Pointers and Addresses
- Pointer object holds address of another object and its type includes the type of object it points to.
	```c++
	int *pi;               // pointer to int
	unsigned long *pul;    // pointer to unsigned long
	```
- For any object x, &x returns its address. If x has type T, then &x has type "pointer to T"
	```c++
	int i;
	unsigned long ul;

	int *pi = &i;
	unsigned long *pul = &ul

	// It can point to different objects at different times
	int a = 1, b = 2;
	int *p = &a;           // p[]-->[1]a
	p = &b;                // p[]-->[2]b
	```

## Null Pointers
- Different null pointers
	```c++
	int *p1 = NULL;        // traditional C
	int *p2 = 0;           // traditional C++
	int *p3 = nullptr;     // modern C++
	```
- Use only nullptr because NULL is defined as: (as a macro inside `<cstddef>`)
	```c++
	#define NULL 0
	// or
	#define NULL 0L
	```
- Passing NULL to overloaded fns:
	```c++
	void f(int i);
	void f(char *s);
	
	f(NULL);               // calls f(int), not f(char *)
	// Because NULL has an integer type and is a better match to f(int)
	```
- nullptr has a unique type that can conver to to any pointer type and not to an integer type. (Introduced in C++ 11)

## Pointer Dereferencing
- `*`operator is used to dereference a pointer. If p is a pointer, then `*p` is the object to which it points.
	```c++
	int i = 13;
	unsigned long ul = 42;
	int *pi = &i;            // pointer to int
	unsigned long *pul = &ul;// pointer to unsigned long

	*pi = 14;                // store 14 into i
	*pul += 2;               // add 2 to ul
	```
- Dereferencing a null pointer producess undefined behaviour

## Object Lifetimes
- Pointer doesn't have the same lifetimes as the object to which it points to.
	```c++
	vois f(int *pi){         // pi's lifetime begins
	// Some statements
	}                        // pi's lifetime ends
	int i = 10;
	f(&i);        
	           
	// f creates a new instance of pi and it exists only for duration of this single function call
	// whereas object i exists before the function call and will continue to exist even after the function call
	```
- Conversely, the lifetime of the pointed-to object might end first:
	```c++
	int *g(){
		int i = 0;
		//some statements    // i's lifetime begins
		return &i;
	}                        // i's lifetime ends
	
	int *pi = g();           // i points to dead i
	
	// Here, g() return &i, but i no longer exists
	// The initializer for pi is a dangling pointer
	// Accessing *pi would produce undefined behaviour
  ```
## const and pointers
- Pointer to const T
	- `const T *p = ~~~;`
	- `T const *p = ~~~;`
	- Both of the above lines have the same meaning:
		```c++
		T x,y;
		p = &x;               // OK: You can modify pointer P
		*p = y;               // no: can't modify T object referenced by *p
		```
- const pointer to T
	- `T *const p = ~~~;`
	- meaning:
		```c++
		T x,y;
		p = &x;               // no: can't modify pointer p
		*p = y;               // OK: can modify T object referenced by *p
		```
- const pointer to const T
	- `const T *const p = ~~~;`
	- `T const *const p = ~~~;`
	- Both of the above lines have the same meaning:
		```c++
		T x,y;
		p = &x;               // no: can't modify pointer P
		*p = y;               // no: can't modify T object referenced by *p
		```
- The same above rules apply to `volatile` and in general, `const` and `volatile` are together known as CV qualifiers

## References
- References provide an alternative to pointers as a way of associating names with objects
```c++
int i;
int &ri = i;
// ri has type "reference to int"
// ri is initialized to refer to int
// Reference ri is an alias for i
```
- Reference can be essentially thought of as a const pointer that is dereferenced everytime it is used
```c++
int &ri = i; 
// Equivalent to: 
int *const cpi = &i;

ri = 4;
// Equivalent to:
*cpi = 4;

int j = ri + 2;
// Equivalent to:
int j = *cpi + 2;
```
- Once a reference is created, it can't be changed to refer to anything else
```c++
int i,j;
int &ri = i;          // binds ri to i
ri = j;               // assigns j to i through ri
```
- Since you can't change what a reference refers to, you must give it a value at the time you define it:
```c++
int &ri;              // error: initializer required
```

## Differences with pointers
- There's no reference equivalent of a "null pointer"
	- A pointer with a null value might point to something else in the future
	- But a reference refers to the same object for its entire lifetime
	- A reference that started out as "null" would always be "null"

## Dangling reference
Just like a dangling pointer, you can also have a dangling reference:
```c++
	int &f(){
		int i = 0;
		~~~
		return i;            // This is a dangling reference
	}
	// The lifetime of the variable i ends with the function call but if the reference that it returns is stored, then the value that this returned reference stores produces undefined behaviour
```
