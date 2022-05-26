# Some Theory on Binary Search Trees

## Tree Traversal

Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse them, trees can be traversed in different ways. Following are the generally used ways for traversing trees.

![image](https://user-images.githubusercontent.com/45400093/170457562-da97b82b-4477-434a-8c19-f9f5b8aa0b38.png)

Depth First Traversals: 

- Inorder (Left, Root, Right) : 4 2 5 1 3 
- Preorder (Root, Left, Right) : 1 2 4 5 3 (Used for copying BST)
- Postorder (Left, Right, Root) : 4 5 2 3 1 (Used for deleting BST)

Breadth-First or Level Order Traversal: 1 2 3 4 5 

```c++
// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

//Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left subtree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}

```
Output:
```
Preorder traversal of binary tree is
1 2 4 5 3 
Inorder traversal of binary tree is
4 2 5 1 3 
Postorder traversal of binary tree is
4 5 2 3 1

```

## Convert normal BST to balanced BST

Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
Examples :
```c++
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
```
A Simple Solution is to traverse nodes in Inorder and one by one insert into a self-balancing BST like AVL tree. Time complexity of this solution is O(n Log n) and this solution doesn’t guarantee 
An Efficient Solution can construct balanced BST in O(n) time with minimum possible height. Below are steps. 
 

- Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
- Build a balanced BST from the above created sorted array using recursive approach. This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.
Below is the implementation of above steps.

```c++
// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

/* This function traverse the skewed binary tree and
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (root==NULL)
		return;

	// Store nodes in Inorder (which is sorted
	// order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
				int end)
{
	// base case
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	/* Using index in Inorder traversal, construct
	left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
	// Store nodes of given BST in sorted order
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	printf("Preorder traversal of balanced "
			"BST is : \n");
	preOrder(root);

	return 0;
}

```
Output:
```
Preorder traversal of balanced BST is : 
7 5 6 8 10 
```
