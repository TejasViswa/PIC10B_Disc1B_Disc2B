# Solution for Conceptual Style Questions in HW1


I'll first talk about questions 1-3 (these code snippets do not involve the optimization stage and are relatively straightforward calculations)

## Question 1:
- All slots are filled and it is a magic square (although it being a magic square does not affect the number of function calls):
- First function call is within see_magic_potential and is always true for all the snippets.        - 1

Let us look at the function structure:
```c++
if (row end and not magic row)
{ return }
if (slots are filled)
{ ~ do something ~ }
else
{   if(slot is empty)
    {   for(i goes from 1 to 9)
        {   if(i is not already used)
            {   fill
                recursive function call to next slot
                reset
            }
        }
    }
    else
    {  recursive function call to next slot  }
}
```

- If you notice, even if a slot is filled there is a function call to next slot. This means that if all slots are filled, then its 9 X 1 calls           - 9
- Therefore, we have 1+9 calls = 10 calls

How to think of this visually:

```
1  +  4   9   2   3   5   7   8   1   6 
1  +  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
```

## Question 2:

- In this question, first two slots are free:
```
1  +  _   _   2   3   5   7   8   1   6 
```
- In this scenario, only two cases are possible:
```
1  +  4   9   2   3   5   7   8   1   6 
1  +  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1               =       10
```
- And after this scenario, to reach the next scenario, the function call has to go back to the second call:
```
1  +  9   _   2   3   5   7   8   1   6 
      1
1  +  9   4   2   3   5   7   8   1   6 
      1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1               =        9
```
- Therefore, when the next number is used an additional number of 9 function calls is also added.
- Total = 10+9 = 19

## Question 3:

- In this question, first three slots are free:
```
1  +  _   _   _   3   5   7   8   1   6 
```
- In this scenario, six cases (3x2x1) are possible: (but note that the number of function calls are different)
Case 1:
```
1  +  2   4   9   3   5   7   8   1   6 
1  +  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1               =       10
```
Case 2:
- To reach this case, the control has to go to the third function call overall:
```
1  +  2   9   _   3   5   7   8   1   6 
              1
1  +  2   9   4   3   5   7   8   1   6 
              1 + 1 + 1 + 1 + 1 + 1 + 1 + 1           =         8
```
Case 3:
- To reach this case, the control has to go to the second function call overall:
```
1  +  4   _   2   3   5   7   8   1   6 
      1
1  +  4   2   9   3   5   7   8   1   6 
      1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1               =         9
```
Case 4:
- To reach this case, the control has to go to the third function call overall:
```
1  +  4   9   _   3   5   7   8   1   6 
              1
1  +  4   9   2   3   5   7   8   1   6 
              1 + 1 + 1 + 1 + 1 + 1 + 1 + 1            =         8
```
Case 5:
- To reach this case, the control has to go to the second function call overall:
```
1  +  9   _   _   3   5   7   8   1   6 
      1
1  +  9   2   4   3   5   7   8   1   6 
      1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1                =         9
``` 

Case 6:
- To reach this case, the control has to go to the third function call overall:
```
1  +  9   4   _   3   5   7   8   1   6 
              1
1  +  9   4   2   3   5   7   8   1   6 
              1 + 1 + 1 + 1 + 1 + 1 + 1 + 1            =         8
```
- Total = 10+8+9+8+9+8 = 52

- What is the pattern you noticed?

## Question 4:

- Now, these questions involve row optimization:

- What this means is had there been no optimization, we would've had two scenarios but now realize that the second scenario is not possible because the row does not add upto magic_total so we essentially have only 1 scenario:
(The other scenario is 4 9 6 ..... and (4+9+6) != 15)
```
1  +  4   9   2   3   5   7   8   1   6 
1  +  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1                 =       10
```
Total = 10

- Note that unlike the previous scenario when an optimization is done, there is no additional function call

## Question 5:

- What do you think the answer to this should be? There can be in total 3X2 scenarios but optimization is applied at the end of each row so all but one scenario remains which is:
(The other scenario is 4 9 6 ..... and (4+9+6) != 15 and so on but notice that at the end of row, there is only 1 number that can work and anything number will not work)
```
1  +  4   9   2   3   5   7   8   1   6 
1  +  1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1                 =       10
```
- Total = 10

- Therefore, the answer is 10 again

## Question 6:

- Now, you use the concepts you learned in all the previous questions to solve this and figure out the answer.
