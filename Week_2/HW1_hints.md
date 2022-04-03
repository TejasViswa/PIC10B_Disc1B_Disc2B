# HW1 Hints

## Constructor Initializer List - Does the argument variable shadow the member variable?
- Following code snippet is completely fine and it does exactly what you hope it should do:
  ```c++
  Square::Square(size_t size):data(size*size,0),size(size),magic_total((size*(size*size+1))/2){}
  ```
  The size in this constructor initializer list is actually the class member variable and is initialized to the value of the argument variable size.
- [Further Reference](https://stackoverflow.com/questions/6185020/initializing-member-variables-using-the-same-name-for-constructor-arguments-as-f)

## Getting the index for your data vector:
- Your task is to convert the i and j index values(row and col indexes) of a matrix into a single index value for a vector. How do you do this? We need a function that does: f(i,j) -> index
- For a 3 by 3 matrix, i and j can take values between 0 to 2 but index value ranges between 0 to 8. eg: f(1,0) -> 3, f(2,1) -> 7
- Thought of a function yet? It should be: ind = size*i + j
- Now how do we get the reverse? Looking at the function, it looks like similar to how you represent a number with a quotient and remainder like: N = Q*P + R.
- Therefore, to get the reverse, we use division and modulo: i = ind//size & j = ind%size where // is integer division

## Debugging your code:
- Use the debugger... a lot. If you haven't used the debugger, then I don't believe that you have solved the question on your own.
- Test your code on the 3 by 3 square so that you have skip through lesser steps and if your code works for 3 by 3, it should also work for a 4 by 4 square.
- Look at the values of your variables(esp data vector) at each step and verify if they have the expected value. If not, then something in your code must be wrong.
