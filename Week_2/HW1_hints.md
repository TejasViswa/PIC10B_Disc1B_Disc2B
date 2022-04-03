# HW1 Hints

## Constructor Initializer List - Does the argument variable shadow the member variable?
- Following code snippet is completely fine and it does exactly what you hope it should do:
  ```c++
  Square::Square(size_t size):data(size*size,0),size(size),magic_total((size*size*(size*size+1))/2){}
  ```
  The size in this constructor initializer list is actually the class member variable and is initialized to the value of the argument variable size.
- [Further Reference](https://stackoverflow.com/questions/6185020/initializing-member-variables-using-the-same-name-for-constructor-arguments-as-f)
