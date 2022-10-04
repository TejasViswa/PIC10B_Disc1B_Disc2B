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

## Most common syntax for a class:

```c++
class className
{
  public:                                                                  
  // Functions that are expected to be called within the main program are generally public
  
  className(datatype1 _dataMem1, datatype2 _dataMem2): dataMem1(_dataMem1), dataMem2(_dataMem2) {}       // Constructor with initializer list
  
  void setDataMem1(datatype1 _dataMem1){ dataMem1 = _dataMem1; }             // Setter Function
  datatype1& getDataMem1(){return dataMem1;}                                 // Getter Function
  
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

## Example 1

```c++
#include <iostream>
#include <string>
using namespace std;

class Car
{
    public:
    // Functions that are expected to be called within the main program are generally public
  
    // Constructor with initializer list
    Car(string _brand, string _model, int _year): brand(_brand), model(_model), year(_year) {}

    void setDetails(string _brand, string _model, int _year)          // Setter Function
    {
        brand = _brand;
        model = _model;
        year = _year;
    }
    string& getBrand(){return brand;}                                 // Getter Function
    string& getModel(){return model;}                                 // Getter Function
    int& getYear(){return year;}                                      // Getter Function

    void display()                                                      // Printer Function
    {
      cout << "Car details: \n"
      << "Brand: " << brand << "\n"
      << "Model: " << model << "\n"
      << "Year: " << year << "\n";
    }
  
    private:
    // Data Members are usually private

    string brand;
    string model;
    int year;
    
};

int main()
{
    Car A("BMW","X5",1999);
    // This prints the car details
    A.display();
    // This also prints the car details
    cout << "Car details: \n"
    << "Brand: " << A.getBrand() << "\n"
    << "Model: " << A.getModel() << "\n"
    << "Year: " << A.getYear() << "\n";
    
    return 0;
}
```
## Example 2
```c++
#include <iostream>
#include <string>
using namespace std;

class Dog
{
    public:
    // Functions that are expected to be called within the main program are generally public
  
    Dog(string _name):name(_name){}

    void setName(string _name){name = _name;}         // Setter Function
    string& getName(){return name;}                   // Getter Function
    
    void display()                                    // Printer Function
    {
      cout << "Dog's details: \n"
      << "Name: " << name << "\n";
    }
    
    void giveTreat(int num)
    {
        switch(num)
        {
            case 1 : cout<< name << " is happy. \n";
                wagTail();
                break;
            case 2 : cout<< name << " is very happy. \n";
                wagTail();
                bark();
                break;
            default : wagTail();
                break;
        }
    }
    
    private:
    // Data Members are usually private

    string name;
    
    void bark()
    {
        cout<<"Woof! Woof! \n";
    }
    
    void wagTail()
    {
        cout<< name << " is wagging its tail! \n";
    }
    
};

int main()
{
    Dog D("Mylo");
    D.display();
    cout<<'\n';
    
    cout<<D.getName()<<" was given a treat \n";
    D.giveTreat(1);
    cout<<'\n';
    
    cout<<D.getName()<<" was given 2 treats \n";
    D.giveTreat(2);
    cout<<'\n';
    
    return 0;
}
```
