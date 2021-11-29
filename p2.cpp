/**
 * Author Cheick
 * Filename: BST.h
 * Date: Created on 11/03/21.
 * PURPOSE: This is a BST template demonstration.
 * Input: user input files names.
 * Output: BST functionalities: Insert, pre-order traversal, post-order traversal, in-order traversal,
 *         contain, remove, size, delete etc...
 */

#include <iostream>
#include "BST.h"
#include <fstream>

using namespace std;

/**
 * Function to try BST functionalities with an integer file
 */
void IntegerFileBinerySearchTree();
/**
 * Function to try BST functionalities with an string file
 */
void stringFileBinerySearchTree();

int main() {
    //print welcome message
    cout << "\nWelcome to the BST experiment project. This program will allow you to test BST functionalities\nsuch as"
            " Inset in the tree, delete from the tree, search element in the tree, print post order\ntraversal, print "
            "in-order traversal, print pre-order traversal and more." << endl << endl;
    //call function
    IntegerFileBinerySearchTree();
    stringFileBinerySearchTree();
    //print new line
    cout << endl;
    //display thank you message
    cout << "Thank you for using BST program." << endl;

    return 0;
}
/**
 * This function will read and integer file content and test BST functionalities such as Insert, pre-order
 * traversal, post-order traversal, in-order traversal, contain, remove, size, delete etc...
 */
void IntegerFileBinerySearchTree() {

    //declaring variables and assigning variables
    string filename;
    int number;
    BST<int> bst;

    //print BST status before insert elements
    cout << "******************************" << endl;
    cout << "* INTEGER BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl << endl;
    cout << "** CREATE BST **" << endl;
    cout << "# of node:   " << bst.size() << endl;
    cout << "# of leaves: " << bst.getLeafCount() << endl;
    cout << "BST height:  " << bst.getHeight() << endl;
    cout << "BST empty?   " << bst.empty() << endl << endl;

    //collect and store infile name:
    cout << "Enter integer infile: ";
    cin >> filename;
    //pass infile name to infile reader and open infile
    ifstream infile(filename.data());
    if (infile.is_open()) {
        //loop through file elements
        while (infile >> number) {
            //insert elements
            bst.insert(number);
        }
        // print BST stats after insertion
        cout << "** TEST INSERT **" << endl;
        cout << "Inserting in this order " << bst.getPreOrderTraversal() << endl;
        cout << "# of nodes:   " << bst.size() << endl;
        cout << "# of leaves:  " << bst.getLeafCount() << endl;
        cout << "tree height:  " << bst.getHeight() << endl;
        cout << "tree empty?   " << bst.empty() << endl;
        cout << "Tree Width is " << bst.getWidth() << endl << endl;
        //test traversal
        cout << "** TEST TRAVERSALS **" << endl;
        cout << "pre-order:  " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:   " << bst.getInOrderTraversal() << endl;
        cout << "post-order: " << bst.getPostOrderTraversal() << endl << endl;
        //test level of elements with ancestors
        cout << "** TEST LEVEL & ANCESTORS **" << endl;
        cout << "level(40): " << bst.getLevel(5) << ", ancestors(40): " << bst.getAncestors(40) << endl;
        cout << "level(20): " << bst.getLevel(9) << ", ancestors(20): " << bst.getAncestors(20) << endl;
        cout << "level(10): " << bst.getLevel(10) << ", ancestors(10): " << bst.getAncestors(10) << endl;
        cout << "level(30): " << bst.getLevel(30) << ", ancestors(30): " << bst.getAncestors(30) << endl;
        cout << "level(60): " << bst.getLevel(60) << ", ancestors(60): " << bst.getAncestors(60) << endl;
        cout << "level(50): " << bst.getLevel(50) << ", ancestors(50): " << bst.getAncestors(50) << endl;
        cout << "level(70): " << bst.getLevel(70) << ", ancestors(70): " << bst.getAncestors(70) << endl
             << endl;
        //test tree contain certain element or not and print values
        cout << "** TEST CONTAINS **" << endl;
        cout << "contains(20): " << bst.contains(20) << endl;
        cout << "contains(40): " << bst.contains(40) << endl;
        cout << "contains(10): " << bst.contains(10) << endl;
        cout << "contains(70): " << bst.contains(70) << endl;
        cout << "contains(99): " << bst.contains(99) << endl;
        cout << "contains(-2): " << bst.contains(-2) << endl;
        cout << "contains(59): " << bst.contains(59) << endl;
        cout << "contains(43): " << bst.contains(43) << endl << endl;
        //test remove element from tree
        cout << "** TEST REMOVE **" << endl;
        cout << "Removing in this order: " << bst.getInOrderTraversal() << endl;
        bst.remove(20);
        bst.remove(40);
        cout << "# of nodes:  " << bst.size() << endl;
        cout << "# of leaves: " << bst.getLeafCount() << endl;
        cout << "tree height: " << bst.getHeight() << endl;
        cout << "tree empty?  " << bst.empty() << endl;
        cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:    " << bst.getInOrderTraversal() << endl;
        cout << "post-order:  " << bst.getPostOrderTraversal() << endl << endl;
        //test insertion new element
        cout << "** TEST INSERT (again) **" << endl;
        bst.insert(-2);
        bst.insert(-22);
        cout << "Inserting in this order: " << bst.getInOrderTraversal() << endl;
        cout << "# of nodes:  " << bst.size() << endl;
        cout << "# of leaves: " << bst.getLeafCount() << endl;
        cout << "tree height: " << bst.getHeight() << endl;
        cout << "tree empty?  " << bst.empty() << endl;
        cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:    " << bst.getInOrderTraversal() << endl;
        cout << "post-order:  " << bst.getPostOrderTraversal() << endl << endl;
    } else {
        //print error message if file is not found
        cout << "cannot open infile. Please try again " << endl;
    }
}
/**
 * This function will read and string file content and test BST functionalities such as Insert, pre-order
 * traversal, post-order traversal, in-order traversal, contain, remove, size, delete etc...
 */
void stringFileBinerySearchTree(){

    //declaring and assigning variables
    string filename,line;
    BST<string> bst;

    //test BST stats before insertion
    cout << "******************************" << endl;
    cout << "* STRING BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl << endl;
    cout << "** CREATE BST **" << endl;
    cout << "# of node:   " << bst.size() << endl;
    cout << "# of leaves: " << bst.getLeafCount() << endl;
    cout << "BST height:  " << bst.getHeight() << endl;
    cout << "BST empty?   " << bst.empty() << endl << endl;
    //collect and store file name
    cout << "Enter string infile: ";
    cin >> filename;

    //open infile
    ifstream infile(filename.data());
    //check if infile is open
    if (infile.is_open()) {
        //loop through elements
        while (infile >> line) {
            //insert elements in BST
            bst.insert(line);
        }
        //Test BST stats after insertion
        cout << "** TEST INSERT **" << endl;
        cout << "Inserting in this order " << bst.getPreOrderTraversal() << endl;
        cout << "# of nodes:   " << bst.size() << endl;
        cout << "# of leaves:  " << bst.getLeafCount() << endl;
        cout << "tree height:  " << bst.getHeight() << endl;
        cout << "tree empty?   " << bst.empty() << endl;
        cout << "Tree Width is " << bst.getWidth() << endl << endl;
        //test printing traversal
        cout << "** TEST TRAVERSALS **" << endl;
        cout << "pre-order:  " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:   " << bst.getInOrderTraversal() << endl;
        cout << "post-order: " << bst.getPostOrderTraversal() << endl << endl;
        //test printing level and ancestors
        cout << "** TEST LEVEL & ANCESTORS **" << endl;
        cout << "level(mary): " << bst.getLevel("mary") << ", ancestors(mary): "
             << bst.getAncestors("mary") << endl;
        cout << "level(gene): " << bst.getLevel("gene") << ", ancestors(gene): "
             << bst.getAncestors("gene") << endl;
        cout << "level(bea):  " << bst.getLevel("bea") << ", ancestors(bea):  "
             << bst.getAncestors("bea") << endl;
        cout << "level(jen):  " << bst.getLevel("jen") << ", ancestors(jen):  "
             << bst.getAncestors("jen") << endl;
        cout << "level(sue):  " << bst.getLevel("sue") << ", ancestors(sue):  "
             << bst.getAncestors("sue") << endl;
        cout << "level(pat):  " << bst.getLevel("pat") << ", ancestors(pat):  "
             << bst.getAncestors("pat") << endl;
        cout << "level(uma):  " << bst.getLevel("uma") << ", ancestors(uma):  "
             << bst.getAncestors("uma") << endl << endl;
        //test if tree contain values and print elements
        cout << "** TEST CONTAINS **" << endl;
        cout << "contains(mary): " << bst.contains("mary") << endl;
        cout << "contains(gene): " << bst.contains("gene") << endl;
        cout << "contains(bea):  " << bst.contains("bea") << endl;
        cout << "contains(uma):  " << bst.contains("uma") << endl;
        cout << "contains(yan):  " << bst.contains("yan") << endl;
        cout << "contains(amy):  " << bst.contains("amy") << endl;
        cout << "contains(ron):  " << bst.contains("ron") << endl;
        cout << "contains(opal): " << bst.contains("opal") << endl << endl;
        //test removing elements from a BST tree
        cout << "** TEST REMOVE **" << endl;
        cout << "Removing in this order: " << bst.getInOrderTraversal() << endl;
        bst.remove("mary");
        bst.remove("uma");
        cout << "# of nodes:  " << bst.size() << endl;
        cout << "# of leaves: " << bst.getLeafCount() << endl;
        cout << "tree height: " << bst.getHeight() << endl;
        cout << "tree empty?  " << bst.empty() << endl;
        cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:    " << bst.getInOrderTraversal() << endl;
        cout << "post-order:  " << bst.getPostOrderTraversal() << endl << endl;
        //Test insertion new element
        cout << "** TEST INSERT (again) **" << endl;
        bst.insert("cheick");
        bst.insert("Ronal");
        cout << "Inserting in this order: " << bst.getInOrderTraversal() << endl;
        cout << "# of nodes:  " << bst.size() << endl;
        cout << "# of leaves: " << bst.getLeafCount() << endl;
        cout << "tree height: " << bst.getHeight() << endl;
        cout << "tree empty?  " << bst.empty() << endl;
        cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
        cout << "in-order:    " << bst.getInOrderTraversal() << endl;
        cout << "post-order:  " << bst.getPostOrderTraversal() << endl << endl;
    } else {
        //print error message if file is not found
        cout << "\nError: (File not found) Please try again!" << endl;
    }
}
