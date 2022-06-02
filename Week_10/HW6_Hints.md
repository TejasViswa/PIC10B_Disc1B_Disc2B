# Some useful theory for HW

## Call the constructor for base class in constructor initialization list

When you call the constructor for the derived class, the first thing the compiler calls is the constructor for the base class. Therefore, you need to call the constructor for the base class within the derived class constructor initialization list because calling the base class within the constructor initialization list makes sure that it is the first constructor that is called before the derived class constructor. Calling it within the body of the derived class constructor is not okay because then the compiler will try to call the default constructor of the base class first and then the derived class constructor(which may not be what you want to do). And also, in cases where the default constructor is not defined, the compiler gives you an error.

So, in short, following is what the compiler tries to do:

Base class constructor -> Derived class constructor

Always.
Even if you don't call the base class constructor within the derived class constructor's initialization list. In this case, the compiler calls the default base class constructor instead because it does not know how to parse the arguments it receives for the derived class constructor for the base class constructor.

Hence, you need to always do the following:

```c++
derived_class_constructor (some_arguments) : base_class_constructor(some_arguments) {
  // function body (maybe throw some exceptions here if some conditions are violated)
}
```
[Further Reading](https://stackoverflow.com/questions/23647409/error-base-class-constructor-must-explicitly-initialize-parent-class-construct)

## throwing exceptions of type logic_error

When you call the constructors of the derived classes, you may need to throw some exceptions when some conditions are violated and the format can be similar to the following:

```c++
if(some condition is violated){
  throw std::logic_error("the logical error here");
}
```
Remember that within your main routine, there is a try-catch sequence which can handle such exceptions when thrown. The std::logic_error class has a what argument (basically, the string that you passed in to mention what logical error it is) which can be accessed using the what() function. Also, the std::cerr is an ostream class similar to std::cout used to output error messages to an error window(if there is one) else to the console window.(Here, it basically does the same as std::cout)

## Constructor for UprightRectangle

You have been given a single point on the top left and the length and breadth of the rectangle. Using this information, you can generate 4 points in total (top-left + 3 more points) that are needed for the vector of points for the Polygon constructor. Remember you can access the x and y values of the top-left point (You can create 3 additional point instances). Within the curly braces, make sure you take care of the conditions that violate the mentioned rule by throwing exception.

## Center, Perimeter and Area for UprightRectangle

Using vectices[0] and vertices[2], you can generate length and breadth of the rectangle. Use them appropriately.


The remaining tasks are straightforward
