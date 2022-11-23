# HW4 Hints

## Task #5
- You should be able to loop through an empty linked list
```c++
LinkedList ll {}; // There's a lot of ways to make an empty list
for(auto it = ll.begin(); it! = ll.end(); ++it )
{ std::cout<<*it<<" ";
}
std::cout<<std::endl;
```
- Now remember if control has to enter within the for loop then ll.begin()!=ll.end(). But for empty list, is this true? Why ot why not?
- What is first and last for ll?
- Then what do you think should end() or rend() should be? (Remember its not okay to deference a nullptr (cannot use `->` or `*`) but its okay to return it)

## Task #6
- Make use of Prof's functions (maybe push_back?)

## Task #7
- Although you are passing by value, the compiler decides whether to perform copy or move semantics based on whether rvalue or lavlue is passed in.
- Not a lot of code is required here (Not even self-assignment)
- And prof has given an additional snippet called "A single assignment operator" which can be used to check your function.
```c++
LinkedList ll1 {1,2,3,4,5,6};
LinkedList ll2 = ll1; \\ This is copy constructor NOT assignment 
LinkedList ll3 = std::move(ll1); \\ This is move constructor NOT assignment

LinkedList ll4;
ll4 = ll1; \\ This is copy assignment
LinkedList ll5;
ll5 = std::move(ll1); \\ This is move assignment
```
- If the constructor is called even though you perform an assignment then a [copy elision](https://en.cppreference.com/w/cpp/language/copy_elision) is taking place. It is an optimization performed by your compiler.
