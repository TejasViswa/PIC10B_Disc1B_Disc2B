# Move Constructor

[lvalues vs rvalues](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c)

[Move Semantics](https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners)

```c++
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
 
struct A
{
    std::string s;
    int k;
    A() : s("test"), k(-1) { }
    A(const A& o) : s(o.s), k(o.k) { std::cout << "move failed!\n"; }
    A(A&& o) noexcept :
           s(std::move(o.s)),       // explicit move of a member of class type
           k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
    { }
};
 
A f(A a)
{
    return a;
}
 
struct B : A
{
    std::string s2;
    int n;
    // implicit move constructor B::(B&&)
    // calls A's move constructor
    // calls s2's move constructor
    // and makes a bitwise copy of n
};
 
struct C : B
{
    ~C() { } // destructor prevents implicit move constructor C::(C&&)
};
 
struct D : B
{
    D() { }
    ~D() { }          // destructor would prevent implicit move constructor D::(D&&)
    D(D&&) = default; // forces a move constructor anyway
};
 
int main()
{
    std::cout << "Trying to move A\n";
    A a1 = f(A()); // return by value move-constructs the target
                   // from the function parameter
    std::cout << "Before move, a1.s = " << std::quoted(a1.s)
        << " a1.k = " << a1.k << '\n';
    A a2 = std::move(a1); // move-constructs from xvalue
    std::cout << "After move, a1.s = " << std::quoted(a1.s)
        << " a1.k = " << a1.k << '\n';
 
    std::cout << "Trying to move B\n";
    B b1;
    std::cout << "Before move, b1.s = " << std::quoted(b1.s) << "\n";
    B b2 = std::move(b1); // calls implicit move constructor
    std::cout << "After move, b1.s = " << std::quoted(b1.s) << "\n";
 
    std::cout << "Trying to move C\n";
    C c1;
    C c2 = std::move(c1); // calls copy constructor
 
    std::cout << "Trying to move D\n";
    D d1;
    D d2 = std::move(d1);
}
```
[Move Constructors](https://en.cppreference.com/w/cpp/language/move_constructor)
