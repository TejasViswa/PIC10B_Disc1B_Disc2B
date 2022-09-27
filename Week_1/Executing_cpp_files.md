# Executing C++ Files

Our programs are represented by source code
- Source code is expressed in human-readable text files
- We typically have three kinds of source code
  - Header files (headers) – generally used more than once when building an executable
    - eg: .h, .hpp, .hh, etc.
  - Source files (source) – generally used only once
    - eg: .c, .cpp, .cxx, .C, etc.
  - Resource files (resources) – used only once to represent special non-executable information
    - eg: icons, images, translations for I18N, etc.
 
- Following is an example of a header file (for function declaration), source file (for function definition) and main source file (main.cpp)
```c++
//  hello.h
//=========
#ifndef HELLO_H_INC
#define HELLO_H_INC
#include <iostream>

void print_hello();

#endif
```
```c++
//  hello.cpp
//===========
#include "hello.h"

void print_hello()
{
  std::cout<< "Hello!" << std::endl;
}
```
```c++
//  main.cpp
//==========
#include "hello.h"

int main(){
  print_hello();
  return 0;
}
```
- Builds are accomplished by compilation and linking as human-readable text files must be converted to binary machine language
<img width="697" alt="image" src="https://user-images.githubusercontent.com/45400093/192631126-ddd3424c-f8e4-4d77-89e3-93621b80de46.png">

### Compilation
- The process of converting human-readable source code into binary object files
- From a high-level perspective, there are four stages of compilation:
  - Lexical analysis
  - Syntax analysis
  - Semantic analysis
  - Code generation
- In C++, we typically generate one object file for each source file
### Linking
- The process of combining object files and binary libraries to make a working program
