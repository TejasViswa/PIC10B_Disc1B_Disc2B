# Uniform Initialization

```c++
//
//  main.cpp
//  TA
//
//  Created by Tejas Viswanath on 5/12/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Widget {
public:
    Widget(){}
    Widget(int i){}
    Widget(int i, bool b){}
    Widget(int i, double d){}
    //Widget(std::initializer_list<long double> il);
    Widget(const Widget& w){}
    Widget(Widget&& w){}
    Widget& operator=(const Widget& w){return *this;}
    //operator float() const;
    //Widget(std::initializer_list<bool> il);
    //Widget(std::initializer_list<std::string> il);
private:
    // int x(0); // error because compiler won't be able to differentiate between variable and function
};

int main() {
    // Distinguish between () and {} when creating objects.
    {
    // Initialization
    
    int x(0);  // initializer is in parentheses [constructor initialization]
    // This is invalid for non static data members
    int y = 0; // initializer follows "=" [c-like initialization]
    int z{ 0 };// initializer is in braces [uniform initialization]
    // int z = { 0 };
    
    cout<<"x:"<<x<<endl;
    cout<<"y:"<<y<<endl;
    cout<<"z:"<<z<<endl;
    
    // The '=' assignment makes a difference for user defined objects
    
    Widget w1;      // call default constructor
    Widget w2 = w1; // not an assignment; calls copy ctor
    w1 = w2;        // an assignment; calls copy operator=
    }
    {
    // To address the confusion of multiple initialization syntaxes, as well as the fact that they don’t cover all initialization scenarios, C++11 introduces uniform initialization: a single initialization syntax that can be used anywhere and express everything. “Uniform initialization” is a concept and “Braced initialization” is a syntactic construct.
    // Braced initialization lets you sepcify the initial contents of a container:
    
    vector<int> v{ 1, 3, 5 }; // v's initial content is 1, 3, 5
    cout<<"v:";
    for(int ele : v){
        cout<<ele<<" ";
    }
    cout<<endl;
    
    // Default initialization with braces
    int a{0}; // This is equivalent to int a = 0;
    cout<<"a:"<<a<<endl;
    // which cannot be done with int a(0) for classes
    
    // Can also be used for uncopyable objects called atomics
    std::atomic<int> ai1{ 0 }; // fine
    std::atomic<int> ai2(0); // fine
    //std::atomic<int> ai3 = 0; // error! depending on compiler
    cout<<"ai1:"<<ai1<<endl;
    cout<<"ai2:"<<ai2<<endl;
    }
    {
    // A novel feature of braced initialization is that it prohibits implicit narrowing conver‐ sions among built-in types. If the value of an expression in a braced initializer isn’t guaranteed to be expressible by the type of the object being initialized, the code won’t compile:
    double x=3.5, y=6.1, z=7.8;
    // int sum1{ x + y + z }; // error! sum of doubles may not be expressible as int
        
    // Initialization using parentheses and “=” doesn’t check for narrowing conversions, because that could break too much legacy code:
        int sum2(x + y + z); // okay (value of expression // truncated to an int)
        cout<<"sum2:"<<sum2<<endl;
        int sum3 = x + y + z; // ditto
        cout<<"sum3:"<<sum3<<endl;
        
    }
    {
    //A side effect of C++’s rule that anything that can be parsed as a declaration must be interpreted as one. So, we inadvertently end up declaring a function instead. The root of the problem is that if you want to call a con‐ structor with an argument, you can do it like this,
    Widget w1(10); // call Widget ctor with argument 10
    //but if you try to call a Widget constructor with zero arguments using the analogous syntax, you declare a function instead of an object:
    Widget w2(); // declares a function named w2 that returns a Widget!
    // Functions can’t be declared using braces for the parameter list, so default- constructing an object using braces doesn’t have this problem:
    Widget w3{}; // calls Widget ctor with no args
    }
    
    // Braced initialization can be used in the widest variety of contexts, it prevents implicit narrowing conversions, and it’s immune to C++’s parse. But...
    {

        // without initializer list

        // Lets say you have a class like the following:
//        class Widget {
//        public:
//          Widget(int i, bool b);  // ctors not declaring
//          Widget(int i, double d);// std::initializer_list params
//          ...
//        };
        Widget w1(10, true);    // calls first ctor
        Widget w2{10, true};    // also calls first ctor
        Widget w3(10, 5.0);     // calls second ctor
        Widget w4{10, 5.0};     // also calls second ctor
        
        // This code is completely fine
    }
    {
        // with initializer list
//        class Widget {
//        public:
//          Widget(int i, bool b);  // ctors not declaring
//          Widget(int i, double d);// std::initializer_list params
//          Widget(std::initializer_list<long double> il); // added
//          ...
//        };
        Widget w1(10, true);// uses parens and, as before, calls first ctor
        Widget w2{10, true};// uses braces, but now calls std::initializer_list ctor(10 and true convert to long double)
        Widget w3(10, 5.0); // uses parens and, as before, calls second ctor
        Widget w4{10, 5.0};// uses braces, but now calls std::initializer_list ctor (10 and 5.0 convert to long double)
        
    
    // Even what would normally be copy and move construction can be hijacked by std::initializer_list constructors:
//    class Widget {
//    public:
//      Widget(int i, bool b);
//      Widget(int i, double d);
//      Widget(std::initializer_list<long double> il);
//      operator float() const; // added
//    ... };
    Widget w5(w4);  // uses parens, calls copy ctor
    Widget w6{w4};  // uses braces, calls std::initializer_list ctor (w4 converts to float, and float // converts to long double)
    Widget w7(std::move(w4)); // uses parens, calls move ctor
    Widget w8{std::move(w4)}; // uses braces, calls std::initializer_list ctor (for same reason as w6)
    }
    {
    // Compilers’ determination to match braced initializers with constructors taking std::initializer_lists is so strong, it prevails even if the best-match std::ini tializer_list constructor can’t be called. For example:
//    class Widget {
//       public:
//         Widget(int i, bool b);                   // as before
//         Widget(int i, double d);                 // as before
//    Widget(std::initializer_list<bool> il); // element type is now bool
//    ... };                                   // no implicit conversion funcs
    Widget w{10, 5.0};      // error! requires narrowing conversions
    //Here, compilers will ignore the first two constructors (the second of which offers an exact match on both argument types) and try to call the constructor taking a std::initializer_list<bool>. Calling that constructor would require converting an int (10) and a double (5.0) to bools. Both conversions would be narrowing (bool can’t exactly represent either value), and narrowing conversions are prohibited inside braced initializers, so the call is invalid, and the code is rejected.
    }
    {
    // Only if there’s no way to convert the types of the arguments in a braced initializer to the type in a std::initializer_list do compilers fall back on normal overload resolution. For example, if we replace the std::initializer_list<bool> construc‐ tor with one taking a std::initializer_list<std::string>, the non- std::initializer_list constructors become candidates again, because there is no way to convert ints and bools to std::strings:
        
//        class Widget {
//           public:
//             Widget(int i, bool b);               // as before
//             Widget(int i, double d);             // as before
//std::initializer_list element type is now std::string
//             Widget(std::initializer_list<std::string> il);
//             ...                          // no implicit conversion funcs
//         };
        Widget w1(10, true);    // uses parens, still calls first ctor
        Widget w2{10, true};    // uses braces, now calls first ctor
        Widget w3(10, 5.0);     // uses parens, still calls second ctor
        Widget w4{10, 5.0};     // uses braces, now calls second ctor
        
    }
    {
        // What if you get {{}}?
        
        Widget w1;
        Widget w2{};
        // Both of these are default constructors
        // But..
        Widget w3{{}}; // This calls list constructor with empty list
        Widget w4({}); // Same as this
    }
    {
        // So why does all this matter?
        
        vector<int> v1(10, 20); // use non-std::initializer_list vector: create 10-element std::vector, all elements have value of 20
        vector<int> v2{10, 20}; // use std::initializer_list ctor: create 2-element std::vector, element values are 10 and 20
        // This creates confusion when creating templates

    }
    return 0;
}

```
