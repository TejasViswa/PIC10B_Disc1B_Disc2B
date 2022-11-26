# HW5 Hints

## Task #1
You need a node pointer that points to the root initially. Then some form of iteration to go through all the nodes (either using iteration - loops or using recursion) based on certain conditions.
Now, if you choose to go Prof's way ie: to use a loop, then you use a while(n) loop meaning to keep searching until there are no more nodes (that's why its while(n)). And within the while loop, you have bunch of if conditions to change this node pointer n to root->left or root->right based on whether the node's value that it is pointing to is less than or greater than the value you are searching for. If found, then return true, if not found even after the loop, then you know it is false.

## Task #2
std::swap comes in handy. Remember swap function basically swaps all your member variables.

## Task #3
Prof's hints are really sufficient for this one, ie: Understand and make use of traverse_node's implementation with approriate changes. Note that ~Tree needs delete_tree.

## Task #5
Prof's hints are really sufficient for this one as well. Its really similar to far_left

## Task #6
Remember for this one, the only two ways to meaningfully(cases where node does exist) increment a BST iterator is either:
- Going to the far left of the current node's right node
- Keep climbing up parent nodes until you reach a node that is indeed greater than the current node (make use of loop like while)
(It does sound like I am repeating Prof's hints but it is honestly that simple)
Vice versa for your decrement.
