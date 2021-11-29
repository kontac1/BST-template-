# BST-template-
Implement a BST template class and write a client program to test it
Class specification (BST.h):
The following public functions must be defined in the BST template class. 

Constructor - Creates an empty BST of given element types.
Destructor - Removes all elements from the BST.
Copy constructor - Create a copy of the BST passed in as a parameter.
Overloaded assignment operator - Assigns the BST passed in as a parameter to an existing BST.
insert - Inserts the element passed in as a parameter into the BST. Assume no duplicate values. Must use recursion.
contains - Searches the BST to determine if a given value is present. Returns true if so, else false. Must use recursion.
remove - Removes the specified value from the BST. 
empty - Determines if BST is empty. Returns true if so, else false.
size - Returns the count of nodes in the BST.
getLeafCount - Returns the count of nodes in the BST that do not have any children.
getHeight - Returns height of the BST. The height is the number of levels it contains. An empty BST has a height of 0. A BST with 1 element has the height of 1.
getLevel - Returns the level of a node in the BST. If the node with the given value is not present in the BST, returns -1.
getInOrderTraversal - Returns a string of elements in the order specified by the in-order traversal of the BST. Must use recursion.
getPreOrderTraversal - Returns a string of elements in the order specified by the pre-order traversal of the BST. Must use recursion.
getPostOrderTraversal - Returns a string of elements in the order specified by the post-order traversal of the BST. Must use recursion.
getAncestors - Returns a string of elements that are the ancestor(s) of the given node. The most immediate ancestor will be the first in the list. If the value is not present in the BST, returns an empty string.

Test driver (p2.cpp):
Implement the driver program to thoroughly test the functionality of the BST.

Ask the user for the file names to read.
Reads the integers or strings from the file, and insert them into the BST in the order they appear
Note that the integer file being read should contain an integer on each line. The integers may be positive, negative, or zero. 
Note that the string file being read should contain a string on each line. Spaces can be included in the strings.
Gets the string from the traversal functions and displays them to the user to verify that they return expected values.
Thoroughly test the functionality of the remaining methods, for example:
Verify contains functionality by checking that some elements are present, but not others. See "Test files" section for info on what can be assumed to be included and not.
Verify remove functionality by removing some elements and that BST is modified as expected. Remove the elements that are noted in the "Test files" section.
Verify that insert functionality still works as expected after remove modified the BST. Insert the elements that are noted in the "Test files" section.
Verify that getLevel returns expected values in a known BST.
Verify that getAncestors returns expected values in a known BST.
As you add and remove elements, verify that size, empty, getHeight, and getLeafCount return expected values.
