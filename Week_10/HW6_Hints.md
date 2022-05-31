# Some useful thoery for HW

## Call the constructor for base class in constructor initialization list

When you call the constructor for the derived class, the first thing the compiler calls is the constructor for the base class. Therefore, you need to call the constructor for the base class within the derived class constructor initialization list because calling the base class within the constructor initialization list makes sure that it is the first constructor that is called before the derived class constructor. Calling it within the body of the derived class constructor is not okay because then the compiler will try to call the default constructor of the base class first and then the derived class constructor(which may not be what you want to do). And also, in cases where the default constructor is not defined, the compiler gives you an error.

So, in short, following is what the compiler tries to do:

Base class constructor -> Derived class constructor

How to ensure that happens?, do the following:

```c++
derived_class_constructor (some arguments) : base_class_constructor(some_arguments) {
  // function body (maybe throw some exceptions here if some conditions are violated)
}
```
