# Move Constructor

[lvalues vs rvalues](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c)

[Move Semantics](https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners)

[Move Constructors](https://en.cppreference.com/w/cpp/language/move_constructor)

Example 1:
```c++
// C++ program to implement
// the above approach

// for std::string
#include <string>

// for std::cout
#include <iostream>

// for EXIT_SUCCESS macro
#include <cstdlib>

// for std::vector
#include <vector>

// for std::move()
#include <utility>

// Declaration
std::vector<std::string> createAndInsert();

// Driver code
int main()
{
	// Constructing an empty vector
	// of strings
	std::vector<std::string> vecString;

	// calling createAndInsert() and
	// initializing the local vecString
	// object
	vecString = createAndInsert();

	// Printing content of the vector
	for (const auto& s : vecString) {
		std::cout << s << '\n';
	}

	return EXIT_SUCCESS;
}

// Definition
std::vector<std::string> createAndInsert()
{
	// constructing a vector of
	// strings with an size of
	// 3 elements
	std::vector<std::string> vec;
	vec.reserve(3);

	// constructing & initializing
	// a string with "Hello"
	std::string str("Hello");

	// Inserting a copy of string
	// object
	vec.push_back(str);

	// Inserting a copy of an
	// temporary string object
	vec.push_back(str + str);

	// Again inserting a copy of
	// string object
	vec.push_back(std::move(str));

	// Finally, returning the local
	// vector
	return vec;
}

```
Output:
```
Hello
HelloHello
Hello
```
Example 2:
```c++
// C++ program to implement
// the above concept

// for std::cout & std::endl
#include <iostream>

// for std::move()
#include <utility>

// for std::string
#include <string>

// for EXIT_SUCCESS macro
#include <cstdlib>

// foo() taking a non-const lvalue
// reference argument
void foo(std::string& str);

// foo() taking a const lvalue
// reference argument
void foo(const std::string& str);

// foo() taking a rvalue
// reference argument
void foo(std::string&& str);

// baz() taking a const lvalue
// reference argument
void baz(const std::string& str);

// baz() taking a non-const lvalue
// reference argument
void baz(std::string& str);

// bar() taking a non-const lvalue
// reference argument
void bar(std::string& str);

// constObjectCallFunc() taking a
// rvalue reference argument
void constObjectCallFunc(std::string&& str);

// Driver code
int main()
{
	// foo(std::string&& str) will
	// be called
	foo(std::string("Hello"));

	std::string goodBye("Good Bye!");

	// foo(std::string& str) will be called
	foo(goodBye);

	// foo(std::string&& str) will be called
	foo(std::move(goodBye + " using std::move()"));

	std::cout << "\n\n\n";

	// move semantics fallback
	// baz(const std::string& str) will be called
	baz(std::string("This is temporary string object"));

	// baz(const std::string& str) will be called
	baz(std::move(std::string(
		"This is temporary string object using std::move()")));

	std::cout << "\n\n\n";

	std::string failToCall("This will fail to call");

	/*
	Reasons to fail bar() call -
		1. No rvalue reference implementation
		available		 // First Preference
		2. No const lvalue reference implementation
		available // Second Preference
		3. Finally fails to invoke bar() function
	*/
	// bar(std::move(failToCall));
	// Error : check the error message for more
	// better understanding
	std::cout << "\n\n\n";

	const std::string constObj(
		"Calling a std::move() on a const object usually has no effect.");
	// constObjectCallFunc(std::move(constObj));
	// Error : because of const qualifier
	// It doesn't make any sense to steal or
	// move the resources of a const object

	return EXIT_SUCCESS;
}

void foo(const std::string& str)
{
	// do something
	std::cout << "foo(const std::string& str) : "
			<< "\n\t" << str << std::endl;
}

void foo(std::string& str)
{
	// do something
	std::cout << "foo(std::string& str) : "
			<< "\n\t" << str << std::endl;
}

void foo(std::string&& str)
{
	// do something
	std::cout << "foo(std::string&& str) : "
			<< "\n\t" << str << std::endl;
}

void baz(const std::string& str)
{
	// do something
	std::cout << "baz(const std::string& str) : "
			<< "\n\t" << str << std::endl;
}

void baz(std::string& str)
{
	// do something
	std::cout << "baz(std::string& str) : "
			<< "\n\t" << str << std::endl;
}

void bar(std::string& str)
{
	// do something
	std::cout << "bar(std::string&& str) : "
			<< "\n\t" << str << std::endl;
}

void constObjectCallFunc(std::string&& str)
{
	// do something
	std::cout << "constObjectCallFunc(std::string&& str) : "
			<< "\n\t" << str << std::endl;
}

```
Output:
```
foo(std::string&& str) : 
    Hello
foo(std::string& str) : 
    Good Bye!
foo(std::string&& str) : 
    Good Bye! using std::move()



baz(const std::string& str) : 
    This is temporary string object
baz(const std::string& str) : 
    This is temporary string object using std::move()
```
[Move Semantics Example Reference](https://www.geeksforgeeks.org/stdmove-in-utility-in-c-move-semantics-move-constructors-and-move-assignment-operators/?ref=rp)
[noexcept](https://stackoverflow.com/questions/28627348/noexcept-and-copy-move-constructors)
