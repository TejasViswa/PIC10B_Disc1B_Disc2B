# Binary Search Trees

## Find minimum value node in binary search Tree
```c++
//C++ program to find minimum value node in binary search Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

/* Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). */
struct node* insert(struct node* node, int data)
{
/* 1. If the tree is empty, return a new,
	single node */
if (node == NULL)
	return(newNode(data));
else
{
	/* 2. Otherwise, recur down the tree */
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	/* return the (unchanged) node pointer */
	return node;
}
}

/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int minValue(struct node* node)
{
struct node* current = node;

/* loop down to find the leftmost leaf */
while (current->left != NULL)
{
	current = current->left;
}
return(current->data);
}

/* Driver Code*/
int main()
{
struct node* root = NULL;
root = insert(root, 4);
insert(root, 2);
insert(root, 1);
insert(root, 3);
insert(root, 6);
insert(root, 5);

cout << "\n Minimum value in BST is " << minValue(root);
getchar();
return 0;
}

```
## Find floor of value
```c++
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

Node *floor(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
} 

int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=17;
	
	cout<<"Floor: "<<(floor(root,17)->key);
}
```
## Sum of numbers between root to node
```c++
// C++ program to find sum of
// all paths from root to leaves
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
};

// function to allocate new node with given data
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

// Returns sum of all root to leaf paths.
// The first parameter is root
// of current subtree, the second
// parameter is value of the number formed
// by nodes from root to this node
int treePathsSumUtil(node *root, int val)
{
	// Base case
	if (root == NULL) return 0;

	// Update val
	val = (val*10 + root->data);

	// if current node is leaf, return the current value of val
	if (root->left==NULL && root->right==NULL)
	return val;

	// recur sum of values for left and right subtree
	return treePathsSumUtil(root->left, val) +
		treePathsSumUtil(root->right, val);
}

// A wrapper function over treePathsSumUtil()
int treePathsSum(node *root)
{
	// Pass the initial value as 0
	// as there is nothing above root
	return treePathsSumUtil(root, 0);
}

// Driver code
int main()
{
	node *root = newNode(6);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->right->right = newNode(4);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	cout<<"Sum of all paths is "<<treePathsSum(root);
	return 0;
}


```
## Depth of binary tree
```c++
// C++ program to find height of full binary tree
// using preorder
#include <bits/stdc++.h>
using namespace std;

// function to return max of left subtree height
// or right subtree height
int findDepthRec(char tree[], int n, int& index)
{
	if (index >= n || tree[index] == 'l')
		return 0;

	// calc height of left subtree (In preorder
	// left subtree is processed before right)
	index++;
	int left = findDepthRec(tree, n, index);

	// calc height of right subtree
	index++;
	int right = findDepthRec(tree, n, index);

	return max(left, right) + 1;
}

// Wrapper over findDepthRec()
int findDepth(char tree[], int n)
{
	int index = 0;
	findDepthRec(tree, n, index);
}

// Driver program
int main()
{
	// Your C++ Code
	char tree[] = "nlnnlll";
	int n = strlen(tree);

	cout << findDepth(tree, n) << endl;

	return 0;
}
```
