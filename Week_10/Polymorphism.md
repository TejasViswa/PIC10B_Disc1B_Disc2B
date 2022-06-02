# Polymorphism

The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism - a person at the same time can play different roles based on the situation. Just like how a woman could be a mother, a sister, a wife or an employee at the same time. So the same person can possess different behavior in different situations. This is called polymorphism. Polymorphism is considered as one of the important features of Object Oriented Programming.

In C++ polymorphism is mainly divided into two types:

- Compile time Polymorphism
- Runtime Polymorphism

![image](https://user-images.githubusercontent.com/45400093/171590637-dcf4270e-ae94-4fea-bd04-465ff2e043db.png)

## Compile time Polymorphism

- Function Overloading
  - We have already seen multiple examples of this. When there are multiple functions with same name but different parameters then these functions are said to be overloaded. Functions can be overloaded by change in number of arguments or/and change in type of arguments.
  eg:
  ```c++
  // C++ program for function overloading
	#include <iostream>

	using namespace std;
	class funcOverload
	{
		public:

		// function with 1 int parameter
		void func(int x)
		{
			cout << "value of x is " << x << endl;
		}

		// function with same name but 1 double parameter
		void func(double x)
		{
			cout << "value of x is " << x << endl;
		}

		// function with same name and 2 int parameters
		void func(int x, int y)
		{
			cout << "value of x and y is " << x << ", " << y << endl;
		}
	};

	int main() {

		funcOverload obj1;

		// Which function is called will depend on the parameters passed
		// The first 'func' is called
		obj1.func(7);

		// The second 'func' is called
		obj1.func(9.132);

		// The third 'func' is called
		obj1.func(85,64);
		return 0;
	}

  ```
  Output:
  ```
  value of x is 7
  value of x is 9.132
  value of x and y is 85, 64
  ```
  In the above example, a single function named func acts differently in three different situations which is the property of polymorphism.
 - Operator Overloading
	  ```c++
	  // CPP program to illustrate
		// Operator Overloading
		#include<iostream>
		using namespace std;

		class Complex {
		private:
			int real, imag;
		public:
			Complex(int r = 0, int i =0) {real = r; imag = i;}

			// This is automatically called when '+' is used with
			// between two Complex objects
			Complex operator + (Complex const &obj) {
				Complex res;
				res.real = real + obj.real;
				res.imag = imag + obj.imag;
				return res;
			}
			void print() { cout << real << " + i" << imag << endl; }
		};

		int main()
		{
			Complex c1(10, 5), c2(2, 4);
			Complex c3 = c1 + c2; // An example call to "operator+"
			c3.print();
		}
	  ```
		
	  Output:
	  ```
	  12 + i9
	  ```
  	In the above example the operator ‘+’ is overloaded. The operator ‘+’ is an addition operator and can add two numbers(integers or floating point) but here the operator is made to perform addition of two imaginary or complex numbers. 
	
## Runtime Polymorphism

Runtime Polymorphism is achieved with function overriding or vertual functions.

A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overriden) in the derived class. It tells the compiler to perform late binding where the compiler matches the object with the right called function and executes it during the runtime.

Note: Because overriding from derived classes hasn’t happened yet, the virtual call mechanism is disallowed in constructors. Also to mention that objects are built from the ground up or follows a bottom to top approach.

We have already seen multiple examples of virtual functions in class. So, let us see a real-life application of virtual functions:

Consider employee management software for an organization.
Let the code has a simple base class Employee, the class contains virtual functions like raiseSalary(), transfer(), promote(), etc. Different types of employees like Managers, Engineers, etc., may have their own implementations of the virtual functions present in base class Employee. 

In our complete software, we just need to pass a list of employees everywhere and call appropriate functions without even knowing the type of employee. For example, we can easily raise the salary of all employees by iterating through the list of employees. Every type of employee may have its own logic in its class, but we don’t need to worry about them because if raiseSalary() is present for a specific employee type, only that function would be called.

```c++
// C++ program to demonstrate how a virtual function
// is used in a real life scenario

class Employee {
public:
	virtual void raiseSalary()
	{
		// common raise salary code
	}

	virtual void promote()
	{
		// common promote code
	}
};

class Manager : public Employee {
	virtual void raiseSalary()
	{
		// Manager specific raise salary code, may contain
		// increment of manager specific incentives
	}

	virtual void promote()
	{
		// Manager specific promote
	}
};

// Similarly, there may be other types of employees

// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee* emp[], int n)
{
	for (int i = 0; i < n; i++) {
		// Polymorphic Call: Calls raiseSalary()
		// according to the actual object, not
		// according to the type of pointer
		emp[i]->raiseSalary();
	}
}
```
Like the ‘globalRaiseSalary()‘ function, there can be many other operations that can be performed on a list of employees without even knowing the type of the object instance. 
Virtual functions are so useful that later languages like Java keep all methods virtual by default.

### How does the compiler perform runtime resolution?

- vtable: A table of function pointers, maintained per class. 
- vptr: A pointer to vtable, maintained per object instance (see this for an example).

![image](https://user-images.githubusercontent.com/45400093/171595152-350628f0-c8c5-4eaf-a8ec-643fe59facf4.png)

The compiler adds additional code at two places to maintain and use vptr.

1. Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable of the class. 

2. Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is made, the compiler inserts code to first look for vptr using a base class pointer or reference (In the above example, since the pointed or referred object is of a derived type, vptr of a derived class is accessed). Once vptr is fetched, vtable of derived class can be accessed. Using vtable, the address of the derived class function show() is accessed and called.

Is this a standard way for implementation of run-time polymorphism in C++? 
The C++ standards do not mandate exactly how runtime polymorphism must be implemented, but compilers generally use minor variations on the same basic model.
