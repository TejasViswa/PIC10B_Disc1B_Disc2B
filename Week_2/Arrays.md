# Arrays and pointers

## Arrays in C++
- On the surface, arrays in C++ are similar to those in other languages
	```c++
	char x[N];               // array of N elements of type char

	// N must be an integer constant expression
	```
- The elements must have have subscripts from 0 to N-1 inclusive
- You can access the elements of an array through pointers:
	```c++
	char x[N];
	char *pc = &x[0];

	*pc = 'a';               // same as: x[0] = 'a'
	```
- Incrementing a pointer to an array element causes it to point to the next element:
	```c++
	++pc;                    // pc now points to x[1]
	*pc = 'c'                // same as: x[1] = 'c'
	```
- `++p` causes p to point to the next array element, regardless of the size of each element.
	- if p were "pointer to char":
		- sizeof(char) is 1
		- `++p` would add 1 to p
	- If p were "pointer to int"
		- sizeof(int) is typically greater than 1, say 4.
		- `++p` adds 4 to the pointer representation so that it points to the next int in the array
- Thus, we can use pointer to iterate through an array:
	```c++
	int x[5] = {1,2,3,4,5};
	for(int *p = x; p < x+5; ++p){
		//Some statements
	}
	```
- You can safely point to one element beyond the array but reading or writing to it causes undefined behaviour

## Pointer addition
- Adding an integer to a pointer yields another pointer
	```c++
	int k;
	t *p,*q;
	q = p + k;              // p + k yields a pointer
	
	// You may use int, long and unsigned long as well
	```

## Pointer subtraction
- If p and q both point to elements of the same array
	```c++
	int i,j;
	int x[5];
	int *p = &x[i];
	int *q = &x[j];

	// subtracting the pointers has the same results as subtracting the indices of the two elements

	int m = q - p;           // q - p yields an integer
	int n = j - i;           // j - i yields the same integer

	if (m == n)              // always true
	{//some statements}
	```
- Subracting two pointers is valid only if they both point to elements of the same array (or one beyond the end) otherwise it produces undefined behaviour

## Arrays and Pointers
- Array can also be treated as a pointer
	```c++
	int x[N];
	// you can treat x as a pointer

	// you can use x for ppinter initialization
	int *pi = x;             // same as pi = &x[0] 

	// you can even dereference x as if it were a pointer itself
	*x = 4;                  // same as x[0] = 4;
	
	```

## Subscripting
- In fact, subscripting with [] is really a pointer operation rather than an array operation
- `x[i]` is a shorthand for `*(x+i)`
- These are equivalent:
	```c++
	for(int i = 0; i < n; ++i){
		sum += x[i];         // recommeneded
	}

	for(int i = 0; i < n; ++i){
		sum += *(x+i);       // not recommeneded
	}
	```

## Arrays aren't Pointers
- `int x[N];` is really an array and not a pointer
- But this is allowed:
	```c++
	int x[10];
	int *p;
	
	p = x;                  // compiles without error
	```
- It compiles because an array can "decay" into a pointer of int object.
- The decay (conversion) is momentary similar to:
	```c++
	double d;
	int i;

	d += i;

	//The above line is really equivalent to:
	
	{
		double t = static_cast<double>(i);
		d += t;
	} // t vanishes here
	```
- Then the difference between an array and pointer is as follows:
	```c++
	int x[10];
	int *p;

	// you can assign an array to a pointer

	p = x;                   // x decays to &x[0]

	// but you cannot assign a pointer to an entire array

	x = p;                   // error: can't assign to array
	```
- sizeof and alignof also produce different results for arrays and pointers
	```c++
	char x[32];
	char *p;

	cout << sizeof(x);       // 32*sizeof(char) = 32
	cout << sizeof(p);       // sizeof(char *) = likely 2,4 or 8

	cout << alignof(x);       // alignof(char) = likely 1
	cout << alignof(p);       // alignof`(char *) = likely 2,4 or 8
	```
- But an array parameters are actually pointers
	```c++
	// These are equivalent
	void foo(int *x);         // x is a pointer
	void foo(int x[]);        // x is still a pointer
	void foo(int x[10]);      // same here
	
	// The sizeof(x) is the same (as a pointer) in all these cases
	```
- Therefore, when we actually need to pass an array as a parameter to a function, we pass in a pointer and a size_t denoting the size of the array.
