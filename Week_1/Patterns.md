# Creating Patterns with for-loops

1. Lets start simple. Lets print the following pattern:
    ```
    1
    1
    1
    1
    ```
    To print the above pattern, a simple for loop with n=4 is sufficient:
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      cout<<1;
      cout<<'\n';
    }
    ```
2. Now, let us add another layer to the pattern:
    ```
    1 1 1 1
    1 1 1 1
    1 1 1 1
    1 1 1 1
    ```
    To print the above pattern, a nested for loop with n=4 is sufficient:
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        cout<<1<<" ";
      }
      cout<<'\n';
    }
    ```
3. Lets make the pattern a little less boring:
    ```
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    ```
    To print the above pattern, we change only the cout statement with j+1:
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        cout<<j+1<<" ";
      }
      cout<<'\n';
    }
    ```
4. Now, a triangle instead:
    ```
    1
    1 2 
    1 2 3
    1 2 3 4
    ```
    To print the above pattern, we change only the terminating condition of j to i+1 instead of n:
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < i+1; ++j){
        cout<<j+1<<" ";
      }
      cout<<'\n';
    }
    ```
5. A triangle on the other side:
    ```
          1
        1 2 
      1 2 3
    1 2 3 4
    ```
    To print the above pattern, we add an additional decremental loop for the whitespaces/blanks and remove the whitespace after cout<<j+1:
    ### NOTE: Decremental loop with size_t that reaches -1 will possibly give you an infinte loop because any unsigned int with value of -1 is given the max int value instead. (Internally, there is a modulo operator that works as (n%max_int) which forces the value between 0 to max_int and avoids any negative number)
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      for(size_t b = n-i; b > 0; --b){
        cout<<" ";
      }
      for(size_t j = 0; j < i+1; ++j){
        cout<<j+1;
      }
      cout<<'\n';
    }
    ```
6. A triangle in the middle:
    ```
          1
        1   2 
      1   2   3
    1   2   3   4
    ```
    To print the above pattern, we add an additional whitespace after cout<<j+1:
    ```c++
    int n = 4;
    for(size_t i = 0; i < n; ++i){
      for(size_t b = n-i; b > 0; --b){
        cout<<" ";
      }
      for(size_t j = 0; j < i+1; ++j){
        cout<<j+1<<" ";
      }
      cout<<'\n';
    }
    ```
    
## Pattern A:
```
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
```

To print the above pattern, we write code similar to pattern 5 and add an additional decremental for loop:

```c++
int n = 4;
for(size_t i = 0; i < n; ++i){
  for(size_t b = n-i; b > 0; --b){
    cout<<"  "; // There are 2 whitespaces here
  }
  for(size_t j = 0; j < i+1; ++j){
    cout<<j+1<<" "; // There is 1 whitespace after every digit
  }
  for(size_t k = i; k > 0; --k){
    cout<<k<<" "; // There is 1 whitespace after every digit
  }
  cout<<'\n';
}
```
    
## Pattern B:
```
      1
    0 1
  1 0 1
0 1 0 1
```

To print the above pattern, we write code similar to pattern 5 and add additional conditions:

```c++
int n = 4;
for(size_t i = 0; i < n; ++i){
  for(size_t b = n-i; b > 0; --b){
    cout<<"  "; // There are 2 whitespaces here
  }
  for(size_t j = 0; j < i+1; ++j){
    cout<<((i%2)==(j%2))<<" "; // There is 1 whitespace after every digit
  }
  cout<<'\n';
}
```
