# Scope of Variables

In general, the scope is defined as the extent up to which something can be worked with. In programming also the scope of a variable is defined as the extent of the program code within which the variable can be accessed or declared or worked with. There are mainly two types of variable scopes: 

1. Local Variables
2. Global Variables

```c++
#include<iostream>
using namespace std;
 
// global variable
int gbl = 5;          // this variable "gbl" can be accessed from any part of the program and dies only with the end of the program

void fn()
{
    // local variable 1
    int lclfn = 7;     // this local variable can only be accessed within this function
}                        // it dies here at the end of function call

// main function
int main()
{
    fn();            // lclfn is created and destroyed during this function call
    
    // local variable 2
    int lcl1 = 5;       // this variable "lcl1" can only be accessed within the main function but dies with the end of the program
    
    // local variable 3
    {
      int lcl2 = 6;     // this is also a local variable
    }                     // But it dies right here
}
```
In this above code snippet,
- gbl is created before main function call, can be accessed anywhere throughout the program and dies with the end of the program
  - scope: anywhere in program
  - lifetime: till end of program
- lclfn is created and destroyed with the function call fn()
  - scope: only within function
  - lifetime: only during function call
  - NOTE: if the function is called again, a new local variable "lclfn" is created and the process repeats but this is different from the previous "lclfn"
- lcl1 is created when its declared and dies with the program
  - scope: only within main function
  - lifetime: till end of program (because a program ends with the main function)
- lcl2 is created and destoryed with the "{" and "}"
  -  scope: only within the block enclosed by "{" and "}"
  -  lifetime: dies with "}"

## Local Variables
Variables defined within a function or block are said to be local to those functions. (including main function)
- Anything between ‘{‘ and ‘}’ is said to inside a block.
- Local variables do not exist outside the block in which they are declared, i.e. they can not be accessed or used outside that block.
- **Declaring local variables**: Local variables are declared inside a block.
```c++
// CPP program to illustrate
// usage of local variables
#include<iostream>
using namespace std;

void func()
{
	// this variable is local to the
	// function func() and cannot be
	// accessed outside this function
	int age=18;
}

int main()
{
	cout<<"Age is: "<<age;
	
	return 0;
}
```
Ouput:
```
Error: age was not declared in this scope
```
The above program displays an error saying “age was not declared in this scope”. The variable age was declared within the function func() so it is local to that function and not visible to portion of program outside this function. 

**Rectified Program** : To correct the above error we have to display the value of variable age from the function func() only. This is shown in the below program:
```c++
// CPP program to illustrate
// usage of local variables
#include<iostream>
using namespace std;
 
void func()
{  
    // this variable is local to the
    // function func() and cannot be
    // accessed outside this function
    int age=18;
    cout<<age;
}
 
int main()
{
    cout<<"Age is: ";
    func();
     
    return 0;
}
```
Output
```
Age is: 18
```
## Global Variables
As the name suggests, Global Variables can be accessed from any part of the program.

- They are available through out the life time of a program.
- They are declared at the top of the program outside all of the functions or blocks.
- Declaring global variables: Global variables are usually declared outside of all of the functions and blocks, at the top of the program. They can be accessed from any portion of the program.
```c++

// CPP program to illustrate
// usage of global variables
#include<iostream>
using namespace std;
 
// global variable
int global = 5;
 
// global variable accessed from
// within a function
void display()
{
    cout<<global<<endl;
}
 
// main function
int main()
{
    display();
     
    // changing value of global
    // variable from main function
    global = 10;
    display();
}
```
Output
```
5
10
```
In the program, the variable “global” is declared at the top of the program outside all of the functions so it is a global variable and can be accessed or updated from anywhere in the program.  

### What if there exists a local variable with the same name as that of global variable inside a function?

Let us repeat the question once again. The question is : if there is a variable inside a function with the same name as that of a global variable and if the function tries to access the variable with that name, then which variable will be given precedence? Local variable or Global variable? Look at the below program to understand the question:

```c++
// CPP program to illustrate
// scope of local variables
// and global variables together
#include<iostream>
using namespace std;
 
// global variable
int global = 5;
 
// main function
int main()
{  
    // local variable with same
    // name as that of global variable
     
    int global = 2;
    cout << global << endl;
}
```
Look at the above program. The variable “global” declared at the top is global and stores the value 5 where as that declared within main function is local and stores a value 2. So, the question is when the value stored in the variable named “global” is printed from the main function then what will be the output? 2 or 5?

Usually when two variable with same name are defined then the compiler produces a compile time error. But if the variables are defined in different scopes then the compiler allows it.
Whenever there is a local variable defined with same name as that of a global variable then the compiler will give precedence to the local variable
How to access a global variable when there is a local variable with same name?

What if we want to do the opposite of above task. What if we want to access global variable when there is a local variable with same name? 
To solve this problem we will need to use the scope resolution operator. Below program explains how to do this with the help of scope resolution operator. 

```c++
// C++ program to show that we can access a global
// variable using scope resolution operator :: when 
// there is a local variable with same name
#include<iostream>
using namespace std;
  
// Global x 
int x = 0; 
   
int main()
{
  // Local x   
  int x = 10;
  cout << "Value of global x is " << ::x;
  cout<< "\nValue of local x is " << x; 
  return 0;
}
```
Output
```
Value of global x is 0
Value of local x is 10
```
