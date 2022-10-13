# Sorting and Algorithms

This file is to only serve as general theory for the three sorts that professor has already explained

## Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. 

The algorithm maintains two subarrays in a given array.

- The subarray which already sorted. 
- The remaining subarray was unsorted.

In every iteration of the selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Lets consider the following array as an example: arr[] = {64, 25, 12, 22, 11}

- First pass:
  - For the first position in the sorted array, the whole array is traversed from index 0 to 4 sequentially. The first position where 64 is stored presently, after traversing whole array it is clear that 11 is the lowest value.
    - `  64   	   25   	   12   	   22   	   11   `
  - Thus, replace 64 with 11. After one iteration 11, which happens to be the least value in the array, tends to appear in the first position of the sorted list.
    - `  11   	   25   	   12   	   22   	   64   `
- Second Pass:
  - For the second position, where 25 is present, again traverse the rest of the array in a sequential manner.
    - `  11   	   25   	   12   	   22   	   64   `
  - After traversing, we found that 12 is the second lowest value in the array and it should appear at the second place in the array, thus swap these values.
    - `  11   	   12   	   25   	   22   	   64   `
- Third Pass:
  - Now, for third place, where 25 is present again traverse the rest of the array and find the third least value present in the array.
    - `  11   	   12   	   25   	   22   	   64   `
  - While traversing, 22 came out to be the third least value and it should appear at the third place in the array, thus swap 22 with element present at third position.
    - `  11   	   12   	   22   	   25   	   64   `
- Fourth pass:
  - Similarly, for fourth position traverse the rest of the array and find the fourth least element in the array 
  - As 25 is the 4th lowest value hence, it will place at the fourth position.
    - `  11   	   12   	   22   	   25   	   64   `
- Fifth Pass:
  - At last the largest value present in the array automatically get placed at the last position in the array
  - The resulted array is the sorted array.
    - `  11   	   12   	   22   	   25   	   64   `

General solution:

- Initialize minimum value(min_idx) to location 0.
- Traverse the array to find the minimum element in the array.
- While traversing if any element smaller than min_idx is found then swap both the values.
- Then, increment min_idx to point to the next element.
- Repeat until the array is sorted.

## Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

Input: arr[] = {5, 1, 4, 2, 8}

- First Pass: 
  - Bubble sort starts with very first two elements, comparing them to check which one is greater.
    - ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
    - ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
    - ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
    - ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
- Second Pass: 
  - Now, during second iteration it should look like this:
    - ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
    - ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
    - ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    - ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
- Third Pass: 
  - Now, the array is already sorted, but our algorithm does not know if it is completed.
  - The algorithm needs one whole pass without any swap to know it is sorted.
    - ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    - ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    - ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
    - ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 

General solution:

- Run a for loop and recursion to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1
- If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on
- Print the sorted array

## Merge Sort

The Merge Sort algorithm is a sorting algorithm that is based on the Divide and Conquer paradigm. In this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.

Think of it as a recursive algorithm continuously splits the array in half until it cannot be further divided. This means that if the array becomes empty or has only one element left, the dividing will stop, i.e. it is the base case to stop the recursion. If the array has multiple elements, split the array into halves and recursively invoke the merge sort on each of the halves. Finally, when both halves are sorted, the merge operation is applied. Merge operation is the process of taking two smaller sorted arrays and combining them to eventually make a larger one.

To know the functioning of merge sort, lets consider an array arr[] = {38, 27, 43, 3, 9, 82, 10}

- At first, check if the left index of array is less than the right index, if yes then calculate its mid point
  - ![image](https://user-images.githubusercontent.com/45400093/195530701-b9acdf38-927e-43bc-bffd-35729cdf7d14.png)
- Now, as we already know that merge sort first divides the whole array iteratively into equal halves, unless the atomic values are achieved.
- Here, we see that an array of 7 items is divided into two arrays of size 4 and 3 respectively.
  - ![image](https://user-images.githubusercontent.com/45400093/195530833-27603cce-3d32-43dd-8b75-90958e275549.png)
- Now, again find that is left index is less than the right index for both arrays, if found yes, then again calculate mid points for both the arrays.
  - ![image](https://user-images.githubusercontent.com/45400093/195531202-df236c51-5cd1-4f58-8429-32cb3ca20477.png)
- Now, further divide these two arrays into further halves, until the atomic units of the array is reached and further division is not possible.
  - ![image](https://user-images.githubusercontent.com/45400093/195531402-833898ca-dcb2-4b71-9d04-ed767238a4d3.png)
- After dividing the array into smallest units, start merging the elements again based on comparison of size of elements
- Firstly, compare the element for each list and then combine them into another list in a sorted manner.
  - ![image](https://user-images.githubusercontent.com/45400093/195531507-41b99eee-4c6d-4e55-b6ba-6f81285fec2c.png)
- After the final merging, the list looks like this:
  - ![image](https://user-images.githubusercontent.com/45400093/195531622-c8b724be-55df-4c93-9f9f-4d58a16f8bc8.png)

The following diagram shows the complete merge sort process for an example array {38, 27, 43, 3, 9, 82, 10}. 

If we take a closer look at the diagram, we can see that the array is recursively divided into two halves till the size becomes 1. Once the size becomes 1, the merge processes come into action and start merging arrays back till the complete array is merged.

![image](https://user-images.githubusercontent.com/45400093/195531787-453a5ded-b08b-47e3-95cd-fd7f840d6374.png)

General solution:

MergeSort(arr[], l,  r)
If r > l

- Find the middle point to divide the array into two halves: 
  - middle m = l + (r – l)/2
- Call mergeSort for first half:   
  - Call mergeSort(arr, l, m)
- Call mergeSort for second half:
  - Call mergeSort(arr, m + 1, r)
- Merge the two halves sorted in steps 2 and 3:
  - Call merge(arr, l, m, r)
