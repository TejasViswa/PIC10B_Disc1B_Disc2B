# Classes and Objects

A class is defined in C++ using keyword class followed by the name of class. The body of class is defined inside the curly brackets and terminated by a semicolon at the end.

```c++
class className
{
  Access Specifier:    // Public, private or Protected
  
  Data Member;         // Variables
  
  Member Function() {} // Methods
  
};                     // Class Name ends with semicolon
```

Most common syntax for a class:

```c++
class className
{
  public:                                                                  
  // Functions that are expected to be called within the main program are generally public
  
  className(datatype1 _dataMem1, datatype2 _dataMem2): dataMem1(_dataMem1), dataMem2(_dataMem2) {}       // Constructor with initializer list
  
  void setDataMem1(datatype1 _dataMem1){ dataMem1 = _dataMem1 }             // Setter Function
  datatype1& getDataMem1(){return dataMem1}                                 // Getter Function
  
  void display()                                                            // Printer Function
  { std::cout << "className with data members: \n"
    << "dataMem1: " << dataMem1 << "\n"
    << "dataMem2: " << dataMem2 << "\n";
  }
  
  // Insert other public functions here. Usually these are functions that require user interaction/input.
  
  private:
  // Data Members are usually private
  
  datatype1 dataMem1;                                                       
  datatype2 dataMem2;
  
  // Insert other private functions here. Usually these are functions that do not require user interaction/input.
};
```
