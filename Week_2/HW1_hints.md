# HW1 Hints

## Task 1 - Constructor
- Your constructor should initialize size, data and magic_total with an initializer list and shouldn't do anything else.
- Data is a vector that should be initialized with `sz*sz` number of zeros (How do you do initialize a vector this way?) and magic_total is initialized with the formula that is given.
### Constructor Initializer List - Does the argument variable shadow the member variable?
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

## Task 2 and Task 3 - Set and Get
- Set and Get basically have the same code but they only differ on the basis of return types - set is return by reference and get is return by value.
- Refer this - [Return by Reference](https://github.com/TejasViswa/PIC10B_Disc1B_Disc2B/blob/main/Week_1/Ret_by_ref.md)
### Getting the index for your data vector:
- Your task is to convert the i and j index values(row and col indexes) of a matrix into a single index value for a vector. How do you do this? We need a function that does: f(i,j) -> index
- For a 3 by 3 matrix, i and j can take values between 0 to 2 but index value ranges between 0 to 8. eg: f(1,0) -> 3, f(2,1) -> 7
- Think of a function that can do this.
- Once you think of a simple function that can get the required index, you just use that index to return the value/reference. eg: `return data[index]` for both the set and get functions.

## Task 4 - Print
- Your print function simply iterates through your data vector (preferably with a normal iteration based for-loop [`for(size_t i =0,N=data.size();i<N;++i)`] so that you know the index instead of a range-based for-loop [`for(unsigned int val:data]` - Why?(Think))) and then prints it out as a matrix (not as a single vector). How do you do this?
- When you reach the end of a row, you also print new line (`\n`) and how do you detect that you reached a new line? (Hint: use the `%` operator with size to find if the iterating value is a multiple of size)
- Additionally, you also print out `*` if the value within the data vector is a 0 (use an if-statement).

## Task 5 - is_magic
- Part 1
    - For the uniqueness check, loop through data vector and check if its already part of an unordered set (You could maybe use the find function), if it is then its not unique else add this element to your set.
    ```c++
  std::unordered_set<unsigned int> checkingSet;
  // Checking if all elements in data are unique
  iterate through data vector {
      if (checkingSet.find(val) != checkingSet.end()){ // This means that val [element of data vector] was found within checkingSet (You could also use count function)
          ~ Do something ~ // Hint: This means that val is not unique and what should you do when val is not unique?
      }
      else
          ~ Do something ~ // Hint: This means that val is unique. [You could make use of the insert function as checkingSet.insert(val)]
  }
  ```
- Part 2
  -  Get row sum and column sum for each row and column (you could make use of `%` operator) and check if they equal magic_total. Make use of the get function that you previously defined.
  - Remember that there is only 1 right diagonal and 1 left diagonal for any square. Use appropriate if conditions(find the pattern) to extract the diagonal sums.
  - All in all, you could write an efiicient code with just two for-loops which are nested and do all these checks.
    - How do you do this?
    ```c++
    for(iterate with a variable i from 0 to size-1)
    { 
        reset col_sum, row_sum variables
        for(iterate with a variable j from o to size-1)
        {
            add to row_sum, the value at ith row and jth column // Hint: use get function
            add to col_sum, the value at jth row and ith column // Hint: use get function
            if(condition for right diagonal element)
                add to rdiag_sum, the value at ith row and jth column // Hint: use get function
            if(condition for left diagonal element)
                add to ldiag_sum, the value at ith row and jth column // Hint: use get function
        }
        Check if row_sum and col_sum are equal to magic_total
    }
    Check if rdiag_sum and ldiag_sum are equal to magic_total
    ```
## Task 6 - row_has_magic_total
- Similar to the checking if row_sum is equal to magic_total but simpler. Here, you have to check for only 1 particular row and not all rows.

## Task 7 - see_magic_potential
- Iterate through data vector and fill up used_up set with the values of data vector
- Make sure you add all the unique non-zero values that already exist in the data vector to your used_up set
- Call help_see_magic_potential function with slots_considered as 0 and used_up set

## Task 8 - help_see_magic_potential
Follow the structure below:
### Structure for the help_see_magic_potential function:
```c++
if(exceeded last slot)
{
    if (it is a magic square)
    {
        print the square
    }
    // Remember there is no else here because once all slots are filled and it is not a magic square, there are no more lines to execute in this function, the control flow just returns to the previous function call without printing anything just like it should
}
else // slots are remaining
{
    if (slot is empty)
    {
        for-loop through 1 to size*size (including size*size)
        {
            [Insert your logic to handle this]
            [Remember you also need to check if value is not in used_up set and only then fill the data vector and used_up set]
            [Once you fill the data vector, you will need a recursive function call to go the next slot and a reset (set the value at data vector to zero and erase that value from used_up set) below that]
        }
    }
    else // slot is not empty, you shouldn't do anything in this slot, just go to the next slot
    {
        Go to next slot (hint: use recursion (call the function again with slot_considered+1 ))
    }
}
```
- Remember slot-considered is your index and the value that you insert at that slot is not the same.
- Make sure you also insert the row optimization part

## Debugging your code:
- Use the debugger... a lot. Its hard to solve it otherwise.
- Test your code on the 3 by 3 square so that you have skip through lesser steps and if your code works for 3 by 3, it should also work for a 4 by 4 square.
- Look at the values of your variables(esp data vector) at each step and verify if they have the expected value. If not, then something in your code must be wrong.
