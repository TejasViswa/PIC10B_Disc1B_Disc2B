# HW1 Hints

## Constructor Initializer List - Does the argument variable shadow the member variable?
- Following code snippet is completely fine and it does exactly what you hope it should do:
  ### Note: This is NOT the complete constructor. Your constructor should also initialize data and magic_total variables
  ```c++
  Square::Square(size_t size):size(size){}
  ```
  The size in this constructor initializer list is actually the class member variable and is initialized to the value of the argument variable size.
- [Further Reference](https://stackoverflow.com/questions/6185020/initializing-member-variables-using-the-same-name-for-constructor-arguments-as-f)
- Although the above code snippet is fine, it is generally preferred to use a different name in your function definition in your .cpp implementation. For eg:
  ```c++
  Square::Square(size_t sz):size(sz){}
  ```
  Its fine if the argument variable name is different in your function declaration(variable name is size) in .hpp file and function definition(variable name is sz) in .cpp file.

## Getting the index for your data vector:
- Your task is to convert the i and j index values(row and col indexes) of a matrix into a single index value for a vector. How do you do this? We need a function that does: f(i,j) -> index
- For a 3 by 3 matrix, i and j can take values between 0 to 2 but index value ranges between 0 to 8. eg: f(1,0) -> 3, f(2,1) -> 7
- Think of a function that can do this.

## For the is_magic function:
- For the uniqueness check, loop through data vector and check if its already part of an unordered set (You could maybe use the find function), if it is then its not unique else add this element to your set.
- Get row sum and column sum for each row and column (you could make use of modulo operator) and check if they equal magic_total. Make use of the get function that you previously defined.
- Remember that there is only 1 right diagonal and 1 left diagonal for any square. Use appropriate if conditions to extract the diagonal sums.

## Within the see_magic_potential:
- Initialize slots_considered and used_up set
- Make sure you add all the unique non-zero values that already exist in the data vector to your used_up set
- Call help_see_magic_potential function

## Structure for the help_see_magic_potential function:
- if exceeded last slot:
  - if it is a magic square:
    - print the square
- else
  - if slot is empty
    - for-loop through 1 to size*size
      - [Insert your logic to handle this]
  - else
    - Go to next slot (hint: use recursion)

Make sure you also insert the row optimization part

## Debugging your code:
- Use the debugger... a lot. If you haven't used the debugger, then I don't believe that you have solved the question on your own.
- Test your code on the 3 by 3 square so that you have skip through lesser steps and if your code works for 3 by 3, it should also work for a 4 by 4 square.
- Look at the values of your variables(esp data vector) at each step and verify if they have the expected value. If not, then something in your code must be wrong.
