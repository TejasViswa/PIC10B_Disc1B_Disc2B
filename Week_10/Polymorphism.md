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
