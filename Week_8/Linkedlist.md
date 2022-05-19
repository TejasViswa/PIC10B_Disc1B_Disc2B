# Linked List

[Difference between vector and linked list](https://thispointer.com/difference-between-vector-and-list-in-c/)

## Function to find size of linked list:
```c++
// This function returns size of linked list
int findSize(struct Node *node)
{
   int res = 0;
   while (node != NULL)
   {
       res++;
       node = node->next;
   }
   return res;
}
```

## Rotate a doubly linked list by N:
```c++
#include<iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node* pre;
	Node(int data)
	{
		this->data=data;
		pre=NULL;
		next=NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}
void insertAtTail(Node* &head, int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}
void display(Node* head)
{
	while(head!=NULL)
	{
		cout << head->data << "-->";
		head=head->next;
	}
	cout << "NULL\n";
}

void rotateByN(Node* &head, int pos)
{
	// return without any changes if position is 0.
	if(pos==0) return;

	// Finding last node.
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	// making the list circular.
	temp->next=head;
	head->pre=temp;

	// move head and temp by the given position.
	int count=1;
	while(count<=pos)
	{
		head=head->next;
		temp=temp->next;
		count++;
	}

	// now again make list un-circular.
	temp->next=NULL;
	head->pre=NULL;
}
int main()
{
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n=2;
	cout << "\nBefore Rotation : \n";
	display(head);
	rotateByN(head,n);
	cout << "\nAfter Rotation : \n";
	display(head);
	cout << "\n\n";

	return 0;
}

```
## Reverse a linked list

- Iterative Approach
```c++
// Iterative C++ program to reverse a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* Function to reverse the linked list */
	void reverse()
	{
		// Initialize current, previous and next pointers
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;
			// Reverse current node's pointer
			current->next = prev;
			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}
```
Output:
```
Given linked list
85 15 4 20 
Reversed Linked list 
20 4 15 85
```
- Recursive Approach
```c++
// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	Node* reverse(Node* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		/* reverse the rest list and put
		the first element at the end */
		Node* rest = reverse(head->next);
		head->next->next = head;

		/* tricky step -- see the diagram */
		head->next = NULL;

		/* fix the head pointer */
		return rest;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

```
Output:
```
Given linked list
85 15 4 20 
Reversed Linked list
20 4 15 85
```
## Detect Loops in a linked List without any additional modifications or containers

- Floyd's cycle detection algorithm
	
	The algorithm is to start two pointers, slow and fast from head of linked list. We move slow one node at a time and fast two nodes at a time. If there is a loop, then they will definitely meet. This approach works because of the following facts.

	1) When slow pointer enters the loop, the fast pointer must be inside the loop. Let fast pointer be distance k from slow.

	2) Now if consider movements of slow and fast pointers, we can notice that distance between them (from slow to fast) increase by one after every iteration. After one iteration (of slow = next of slow and fast = next of next of fast), distance between slow and fast becomes k+1, after two iterations, k+2, and so on. When distance becomes n, they meet because they are moving in a cycle of length n.

	For example, we can see in below diagram, initial distance is 2. After one iteration, distance becomes 3, after 2 iterations, it becomes 4. After 3 iterations, it becomes 5 which is distance 0. And they meet.
```c++
// C++ program to detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

int detectLoop(Node* list)
{
	Node *slow_p = list, *fast_p = list;

	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			return 1;
		}
	}
	return 0;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head;
	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	return 0;
}
```
Output:
```
Loop found
```
## Remove Loop after detection

- Method 1
	
	(Check one by one) We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. We also know that this common point is one of the loop nodes. Store the address of this in a pointer variable say ptr2. After that start from the head of the Linked List and check for nodes one by one if they are reachable from ptr2. Whenever we find a node that is reachable, we know that this node is the starting node of the loop in Linked List and we can get the pointer to the previous of this node.

- Method 2
	
	This method is also dependent on Floyd’s Cycle detection algorithm.
	-	Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
	-	Count the number of nodes in loop. Let the count be k.
	-	Fix one pointer to the head and another to a kth node from the head.
	-	Move both pointers at the same pace, they will meet at loop starting node.
	-	Get a pointer to the last node of the loop and make next of it as NULL.
![image](https://user-images.githubusercontent.com/45400093/169273259-c7314277-48ce-4af0-9170-fbea86b4ce58.png)

```c++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Function to remove loop. */
void removeLoop(struct Node*, struct Node*);

/* This function detects and removes loop in the list
If loop was there in the list then it returns 1,
otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
	struct Node *slow_p = list, *fast_p = list;

	// Iterate and find if loop exists or not
	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		/* If slow_p and fast_p meet at some point then there
		is a loop */
		if (slow_p == fast_p) {
			removeLoop(slow_p, list);

			/* Return 1 to indicate that loop is found */
			return 1;
		}
	}

	/* Return 0 to indicate that there is no loop*/
	return 0;
}

/* Function to remove loop.
loop_node --> Pointer to one of the loop nodes
head --> Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
	struct Node* ptr1 = loop_node;
	struct Node* ptr2 = loop_node;

	// Count the number of nodes in loop
	unsigned int k = 1, i;
	while (ptr1->next != ptr2) {
		ptr1 = ptr1->next;
		k++;
	}

	// Fix one pointer to head
	ptr1 = head;

	// And the other pointer to k nodes after head
	ptr2 = head;
	for (i = 0; i < k; i++)
		ptr2 = ptr2->next;

	/* Move both pointers at the same pace,
	they will meet at loop starting node */
	while (ptr2 != ptr1) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	// Get pointer to the last node
	while (ptr2->next != ptr1)
		ptr2 = ptr2->next;

	/* Set the next node of the loop ending node
	to fix the loop */
	ptr2->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	// Print the list after loop removal
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

struct Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Driver Code
int main()
{
	struct Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	cout << "Linked List after removing loop \n";
	printList(head);
	return 0;
}

```
Output:
```
Linked List after removing loop 
50 20 15 4 10 
```

- Method 3

	(Optimized Method 2: Without Counting Nodes in Loop) 
We do not need to count number of nodes in Loop. After detecting the loop, if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

```c++
// C++ program to detect and remove loop
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

// Function to detect and remove loop in a linked list that
// may contain loop
void detectAndRemoveLoop(Node* head)
{
	// If list is empty or has only one node without loop
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	// Move slow and fast 1 and 2 steps ahead respectively.
	slow = slow->next;
	fast = fast->next->next;

	// Search for loop using slow and fast pointers
	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	/* If loop exists */
	if (slow == fast) {
		slow = head;

		// this check is needed when slow and fast both meet
		// at the head of the LL eg: 1->2->3->4->5 and then
		// 5->next = 1 i.e the head of the LL
		if (slow == fast)
			while (fast->next != slow)
				fast = fast->next;
		else {
			while (slow->next != fast->next) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		/* since fast->next is the looping point */
		fast->next = NULL; /* remove loop */
	}
}

/* Driver program to test above function*/
int main()
{
	Node* head = newNode(50);
	head->next = head;
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head;

	detectAndRemoveLoop(head);

	printf("Linked List after removing loop \n");
	printList(head);

	return 0;
}

```
Output:
```
Linked List after removing loop 
50 20 15 4 10
```
