// def = Tree is non-liner(hierarchical) data structure ,,which has many levels
// logical repreastion
                          
//            A
/*           / \
            B   C
           / \ / \
          D  E F  H

inorder==dbeafch
pre==abdecfh
post==debfhcap

it will grow from top to bottom 
parent node == the immatate predesar of a node 
child node == the immatate sacreacor of a node
sibling == childern of same parent node
depth == number of vartises from root node
height == count of vartises from root node to leaf

*******************binary tree ******************
in this tree each node can have 2 or less then 2 childern
The number of nodes possable at any level i 
            is 2^i

the maxumum number of nodes at the height h = (2^h+1)-1

Types of binary tree

1)full/proper/strict
=It is a binary tree where each node contains eather 0 or 2 childern 

2)complete binary tree
= if all the levels are completely filled (expect possibly the last level)
  and last level has nodes as left as possible ,,fill the last level from left to right

3)perfect binary tree
= if all the internal nodes having two childern and all the leaf nodes are at same level

4)degenerate binary tree
= all the internal nodes has only 1 node
*/  