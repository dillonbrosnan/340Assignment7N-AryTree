Compiled with DevC++

This is an n ary tree header and cpp file that allows us to create a tree with multiple
children, not just a binary tree, where each node can only have up to two children.

The basic structure is that each GeneralTree has a starting point node, with a pointer
to its potential sibling and its potential children. For example the first generalTree
created would look like:

.->0
|
V
a->.->0
|  |
V  V
0  b->c->0
   |  |
   V  V
   0  0

where each 0 is NULL