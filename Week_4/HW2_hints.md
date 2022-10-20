# HW2 hints

## == and < operator
- How do we check if two rationals are equal?
- Remember that all Rationals are stored in their simplified version so there is no need to bother comparing Rationals with same ratio but different num and den. All rationals that have the same ratio have the same num and den. So use that to your advantage when you define '=='
Check if the num and den of the two rationals are equal.

- How do we check if one if less than the other?
- This is slightly more tricky But the following hint to your advantage:
To compare a/b and c/d, remember we can cross multiply the denominators to the other side as:
a*d and c*b and perform the comparison.

## Task 8
```c++
Rational r(1, 2);
std::cout << (1 + r) << std::endl;
```
- What happens when we try and execute the above code?
- The compiler says that the above call is ambiguous because the compiler has two possible condidates which are equally likely. Now both the candidate functions are equally likely because it is just as easy for the compiler to implicitly cast the 1 into a Rational and add the two Rationals or implicitly cast the r into a double and do the addition. We can prevent one of these coversions by using a certain keyword in front of a certain function so that the function call is no longer ambiguous and only prints 3/2 (Rational addition). Think about that
