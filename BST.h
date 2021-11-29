/**
 * Author Cheick
 * Filename: BST.h
 * Date: Created on 11/03/21.
 * PURPOSE: This is a BST template demonstration.
 * Input: user input files names.
 * Output: BST functionalities: Insert, pre-order traversal, post-order traversal, in-order traversal,
 *         contain, remove, size, delete etc...
 */

#ifndef PROJECT_2_BST_H
#define PROJECT_2_BST_H

#include <string>
#include <sstream>

using namespace std;

template<class T>
class BST {

public:

    BST();                               // Constructor
    ~BST();                              // De-constructor
    BST(const BST &);                    // Copy constructors
    BST operator=(const BST &);          // Overloaded operator

    void insert(T);                      // Insert elements
    bool contains(T);                    // check if contain elements
    void remove(T);                      // remove elements from the list
    bool empty();                        // check if tree is empty
    int size();                          // get the size of the tree
    int getLeafCount();                  // return leaf count
    int getHeight();                     // return height of the tree
    int getLevel(T);                     // return the level of the tree
    string getInOrderTraversal();        // return the traversal order
    string getPreOrderTraversal();       // return the traversal pre-order
    string getPostOrderTraversal();      // return the traversal post order
    string getAncestors(T);              // return ancestors
    int getWidth();                      // return maximum level of a tree
private:
    struct Node {
        T data;                          // store data for the node
        Node *left;                      // store left node element
        Node *right;                     // store right node element
    };
    Node *root;                          // pointer to the root node


    void insert(Node *&, Node *&);        // private helper function to insert elements
    void remove(Node *&, T);              // private helper function to remove elements
    void makeDeletion(Node *&, T);        // private helper function to make deletion elements
    void destroyTree(Node *&);            // private helper function to destroy tree elements
    int getLeafCount(Node *&);            // private helper function to get the number of leaf elements
    int size(Node *&);                    // private helper function to get size of the tree elements
    int getHeight(Node *&);               // private helper function to get height of the tree elements
    string getInOrderTraversal(Node *&);  // private helper function to get in order traversal elements
    string displayPreOrder(Node *&);     // private helper function to get pre order traversal elements
    string getPostOrderTraversal(Node *&); //private helper function to get post order traversal elements
    string getAncestors(Node *&, T);       // private helper function to get ancestor elements
    bool contains(Node *&, T);             // private helper function to check if BST contain elements
    void makeCopy(Node *const &, Node *&); // private helper function to make copy elements
    int getLevel(Node *&, T);              // private helper function to get level of BST elements
    T removeRightMostNode(Node *ptr);      // private helper function to remove right most node
    int getWidth(Node *&, int);

};

/**
 * constructor to assign root to null pointer
 */
template<class T>
BST<T>::BST() {
    //assign root to null pointer
    root = nullptr;
}

/**
 * de-constructor to deallocate memory
 */
template<class T>
BST<T>::~BST() {
    //deallocating memory
    destroyTree(root);
}

/**
 * destroy the tree to deallocate memory
 * @param ptr assign node pointer
 */
template<class T>
void BST<T>::destroyTree(BST::Node *&ptr) {
    //check if the Node equal to null
    if (ptr != nullptr) {
        //destroy left side of tree
        destroyTree(ptr->left);
        //destroy right side of tree
        destroyTree(ptr->right);
        //delete tree
        delete ptr;
    }
    //point the root to null
    ptr = nullptr;
}
/**
 * function to return the width of a tree
 * @tparam Template functin
 * @return tree width
 */
template<class T>
int BST<T>::getWidth() {
    //declare width and maximum width
    int maxW = 0, width;
    //loop through element to count
    for (int i = 1; i <= getHeight(); i++) {
        //assign recursive call to width
        width = getWidth(root, i);
        //check if width is grater than maximum width
        if (width > maxW) {
            //assign width
            maxW = width;
        }
    }
    //return width
    return maxW;
}
/**
 * Helper function to return the width of a tree
 * @tparam Template
 * @param ptr pointer to elements
 * @param value index
 * @return result
 */
template<class T>
int BST<T>::getWidth(BST::Node *&ptr, int value) {
    //declare and assign variables
    int result;
    //check if root is equal to null
    if (ptr == nullptr)
        //return zero
        return 0;
    //check if index is equal to one
    if (value == 1)
        //return one
        return 1;
    //check if index is greater than one
    else if (value > 1)
        //assign call to recursive function
        result = getWidth(ptr->left, value - 1) + getWidth(ptr->right, value - 1);
    //return result
    return result;
}

/**
 * Copy constructor to copy elements
 */
template<class T>
BST<T>::BST(const BST &ptr) {
    //check if root is equal to null
    if (ptr.root == nullptr) {
        //assign root to null
        root = nullptr;
    } else {
        //create a root object
        root = new Node();
        //assign root to  equal pointer value
        root->data = ptr.root->data;
        //assign left root and right root to null
        root->left = root->right = nullptr;
        //call makecopy function to past in pointer root and root
        makeCopy(ptr.root, root);
    }
}

/**
 * the copy  function will copy one BST tree element to another
 * @tparam T value pass in
 * @param ref new BST
 * @param ptr copy element to ptr
 */
template<class T>
void BST<T>::makeCopy(BST::Node *const &ref, BST::Node *&ptr) {
    //check left side
    if (ref->left) {
        //assign pointer left to new node
        ptr->left = new Node();
        //copy elements
        ptr->left->data = ref->left->data;
        ptr->left->left = ptr->left->right = nullptr;
        //pass element to make copy function
        makeCopy(ref->left, ptr->left);
    }
    //check right side
    if (ref->right) {
        //assign pointer right to new node
        ptr->right = new Node();
        //copy elements
        ptr->right->data = ref->right->data;
        ptr->right->left = ptr->right->right = nullptr;
        //pass element to make copy function
        makeCopy(ref->right, ptr->right);
    }
}

/**
 * Overload operator
 * @return
 */
template<class T>
BST<T> BST<T>::operator=(const BST &ptr) {
    //check if root is equal to BST root
    if (root == ptr.root) {
        //return root
        return *this;
    }
    //destroy the tree
    this->destroyTree();
    //if BST root equal null
    if (ptr.root == nullptr) {
        //retunr BST
        return BST();
    }
    //assign root to new node
    root = new Node();
    //assign root value to BST value
    root->data = ptr.root->data;
    //assign root left value and right value to null
    root->left = root->right = nullptr;
    //call deletion function to deallocate memory
    makeDeletion(ptr.root, root);
    //return BST
    return *this;
}

/**
 * insert element in tree
 */
template<class T>
void BST<T>::insert(T item) {
    //create and assign a newnode object
    Node *newNode = new Node;
    //assing newnode value to item pass in
    newNode->data = item;
    //assign newNode left and right value to null
    newNode->left = newNode->right = nullptr;
    //call insert function to insert root and newnode element
    insert(root, newNode);
}

/**
 * This function will insert element in a BST tree
 * @tparam Template
 * @param ptr BST tree
 * @param newNode tree
 */
template<class T>
void BST<T>::insert(BST::Node *&ptr, BST::Node *&newNode) {
    //check if the tree is empty
    if (ptr == nullptr) {
        //point to newnode
        ptr = newNode;
        //else check if BST value is less than newNode value
    } else if (ptr->data > newNode->data) {
        //insert elements in left
        insert(ptr->left, newNode);
    } else {
        //else insert element in right
        insert(ptr->right, newNode);
    }
}

/**
 * the function will check if a BST tree contain certain value
 * @tparam Template
 * @param item value pass in to check
 * @return return true or false
 */
template<class T>
bool BST<T>::contains(T item) {
    //check if root root null pointer
    if (root == nullptr) {
        //return false
        return false;
    }
    //recursion call
    return contains(root, item);
}

/**
 * the helper recursive function to check if BST function contain value
 * @tparam Template
 * @param ptr Tree
 * @param value to check in the tree
 * @return
 */
template<class T>
bool BST<T>::contains(BST::Node *&ptr, T value) {
    //compare BST root value to the value pass in
    if (ptr->data == value) {
        //return true
        return true;
    }
    //check if BST data is higher than the value and left data is not equal to null
    if (ptr->data > value && ptr->left != nullptr) {
        //return function with left value and value pass in
        return contains(ptr->left, value);
    }
    //check if BST data is less than the value and left data is not equal to null
    if (ptr->data < value && ptr->right != nullptr) {
        //return function with left value and value pass in
        return contains(ptr->right, value);
    }
    //return false
    return false;

}

/**
 * this function will remove element from a BST tree
 * @tparam Template
 * @param item value to remove from the tree
 */
template<class T>
void BST<T>::remove(T item) {
    //create a temporary node to hold elements
    Node *temp;
    //check if root is equal to null
    if (root == nullptr) {
        //return null
        return;
    }
    //check if root value is equal to the value to be remove
    if (root->data == item) {
        //if left value is equal to null
        if (root->left == nullptr) {
            //assign temporary node to right value
            temp = root->right;
            //delete root
            delete root;
            //assign root to temporary node
            root = temp;
            //if right value is equal to null
        } else if (root->right == nullptr) {
            //assign temporary node to left value
            temp = root->left;
            //delete root
            delete root;
            //assign root to temporary node
            root = temp;
        } else {
            //check if left and right value is equal to null
            if (root->left && root->right == nullptr) {
                //assign left and right to right
                root->left->right = root->right;
                //assign root to temporary node
                temp = root;
                //assign root to left value
                root = root->left;
                //delete root
                delete temp;
            } else {
                //else assign root value to removerightMostNode function with left value as argument
                root->data = removeRightMostNode(root->left);
            }
        }
        //return null
        return;
    }
    //call remove function with root and item to be remove
    remove(root, item);

}

/**
 * the private helper function to remove element from BST tree
 * @tparam Template
 * @param ptr BST tree
 * @param item item to be remove
 */
template<class T>
void BST<T>::remove(BST::Node *&ptr, T item) {
    //declare and assign a bool variable
    bool rem = false;
    //if left value and right value equal item or right right value equal item
    if ((ptr->left && ptr->right->data == item) || (ptr->right && ptr->right->data == item)) {
        //call makedeletion function with the pointer and the item
        makeDeletion(ptr, item);
        //assign bool variable to true
        rem = true;
        //return null
        return;
    }
    //check if bool varaible is equal to false
    if (rem == false) {
        //check if BST value is less than item to be remove and left value
        if (ptr->data > item && ptr->left) {
            //call remove function with left value and item to be remove
            remove(ptr->left, item);
            //check right value
        } else if (ptr->right) {
            //call remove function with the right value and item to be remove as argument
            remove(ptr->right, item);
        }
    }
}

/**
 * the function will delete elements in a BST tree
 * @tparam Template
 * @param ptr to tree elements
 * @param item to delete
 */
template<class T>
void BST<T>::makeDeletion(BST::Node *&ptr, T item) {
    //if left value and right value equal item
    if (ptr->left && ptr->left->data == item) {
        //create a node temp to be assign to the left value
        Node *temp = ptr->left;
        //check if left and right value of temp
        if (!temp->left && !temp->right) {
            //delete temp
            delete temp;
            //assing BST TO NULL
            ptr->left = nullptr;
        }
            //check if left value
        else if (temp->left && !temp->right) {
            //create a temporary node and assign it to temp left value
            Node *tempPtr = temp->left;
            //delete temp
            delete temp;
            //assing BST left value to tempPtr
            ptr->left = tempPtr;
            //check the right value of temp
        } else if (!temp->left && temp->right) {
            //creat a temporary node to be assign to the right value of temp
            Node *newNode = temp->right;
            //delete temp
            delete temp;
            //assign BST left value to newNode
            ptr->left = newNode;
        } else {
            //check if left and right value are not equal to null
            if (temp->left->right == nullptr) {
                //assign left and right value to right value
                temp->left->right = temp->right;
                //assign bst left value to temp left value
                ptr->left = temp->left;
                //delete temp
                delete temp;
            } else {
                //assign temp value to removeRightMostNode with temp left value as argument
                temp->data = removeRightMostNode(temp->left);
            }
        }
    } else {
        //create temp node and assign to right value
        Node *temp = ptr->right;
        //check if left value and right value is null
        if (!temp->left && !temp->right) {
            //delete temp
            delete temp;
            //assign right value null
            ptr->right = nullptr;
            //check left value
        } else if (temp->left && !temp->right) {
            //declare and assign newNode Node to temp left value
            Node *newNode = temp->left;
            //delete temp
            delete temp;
            //assign right value to newNode
            ptr->right = newNode;
            //check right value
        } else if (!temp->left && temp->right) {
            //declare and assign q Node to temp left value
            Node *q = temp->right;
            //delete temp
            delete temp;
            //assign right value to q
            ptr->right = q;
        } else {
            //check left and right value is equal to null
            if (temp->left->right == nullptr) {
                //assign temp left and right to right value
                temp->left->right = temp->right;
                //assign right vale to temp left value
                ptr->right = temp->left;
                //delete temp
                delete temp;
            } else {
                //assign temp node value to removeRightMostNode function with temp left value
                temp->data = removeRightMostNode(temp->left);
            }
        }
    }
}

/**
 * this function will remove the right most Node of the BST tree
 * @tparam Template
 * @param ptr tree
 * @return value remove
 */
template<class T>
T BST<T>::removeRightMostNode(Node *ptr) {
    //while right value
    while (ptr->right->right)
        //assign node to right
        ptr = ptr->right;
    //assign value to right value
    T val = ptr->right->data;
    //temporary node and assign to the right and left value
    Node *x = ptr->right->left;
    //delete right value
    delete ptr->right;
    //assign right value to x
    ptr->right = x;
    //return value
    return val;
}

/**
 * the function will check if a BST try is empty or not
 * @tparam Template
 * @return  true or false
 */
template<class T>
bool BST<T>::empty() {
    //check is root is null
    if (root == nullptr) {
        //return true
        return true;
    } else {
        //return false
        return false;
    }
}

/**
 * the function will return the size of the tree
 * @tparam Template
 * @return return size
 */
template<class T>
int BST<T>::size() {
    //return size function with root
    return size(root);
}

/**
 * Private helper function to return size of the tree
 * @tparam Template
 * @param ptr tree
 * @return reuturn size
 */

template<class T>
int BST<T>::size(BST::Node *&ptr) {
    //check if root is equal to null
    if (ptr == nullptr) {
        //return 0
        return 0;
    } else {
        //return size function with left value plus right value plus one
        return (size(ptr->left) + size(ptr->right) + 1);
    }
}

/**
 * the function will return the number of leaf in BST tree
 * @tparam Template
 * @return the number of left whenever function is call
 */
template<class T>
int BST<T>::getLeafCount() {
    //return getLeaf function with root
    return getLeafCount(root);
}

/**
 * Private helper function to count te leaf of the tree
 * @tparam Template
 * @param ptr tree
 * @return number of leaf
 */
template<class T>
int BST<T>::getLeafCount(BST::Node *&ptr) {
    //check if root is equal to null
    if (ptr == nullptr) {
        //return 0
        return 0;
        //check if right and right value is equal to null an
    } else if (ptr->right == nullptr && ptr->left == nullptr) {
        //return 1
        return 1;
    } else {
        //return getLeafunction with sum of left and right value
        return getLeafCount(ptr->left) + getLeafCount(ptr->right);
    }
}

/**
 * Returns height of the BST.
 * @tparam Template
 * @return return height
 */

template<class T>
int BST<T>::getHeight() {
    //return getheight function with root as argument
    return getHeight(root);
}

/**
 * Private helper function to get the height of a tree
 * @tparam Template
 * @param ptr tree
 * @return height of a tree
 */
template<class T>
int BST<T>::getHeight(BST::Node *&ptr) {
    //check if root is not equal to null
    if (ptr == nullptr) {
        //return 0
        return 0;
    } else {
        //assigh left height to getheight function with left value as argument
        int leftH = getHeight(ptr->left);
        //assigh right height to getheight function with right value as argument
        int rightH = getHeight(ptr->right);
        //if left height is higher or equal to right height
        if (leftH >= rightH) {
            //return left height plus one
            return leftH + 1;
        } else {
            //return right height plus one
            return rightH + 1;
        }
    }
}

/**
 * Returns a string of elements in the order specified by the pre-order traversal of the BST.
 * @tparam Template
 * @return string element
 */
template<class T>
string BST<T>::getPreOrderTraversal() {
    //return displayPreOrder elements with root as argument
    return displayPreOrder(root);
}

/**
 * private helper function to return string elements in order specified by the pre-order traversal of the BST.
 * @tparam Template
 * @param ptr tree
 * @return string element
 */
template<class T>
string BST<T>::displayPreOrder(BST::Node *&ptr) {
    //create a string builder object
    stringstream ss;
    //if root is not equal null
    if (ptr != nullptr) {
        //pass BST value in the string builder
        ss << ptr->data << " ";
        //past function left element in the string builder
        ss << displayPreOrder(ptr->left);
        //past function right element in the string builder
        ss << displayPreOrder(ptr->right);
    }
    //return string builder
    return ss.str();

}
/**
 * function to return in-order traversal of a tree
 * @tparam Template
 * @return  in-order traversal
 */
template<class T>
string BST<T>::getInOrderTraversal() {
    //return getInOrder elements with root as argument
    return getInOrderTraversal(root);
}
/**
 * Helper fucntion to return in-order traversal of a tree
 * @tparam Template
 * @param ptr to element
 * @return in-order traversal
 */
template<class T>
string BST<T>::getInOrderTraversal(BST::Node *&ptr) {
    //create a string builder object
    stringstream ss;
    //if root is not equal null
    if (ptr != nullptr) {
        //past function left element in the string builder
        ss << getInOrderTraversal(ptr->left);
        //pass BST value in the string builder
        ss << ptr->data << " ";
        //past function right element in the string builder
        ss << getInOrderTraversal(ptr->right);
    }
    //return string builder object
    return ss.str();
}
/**
 * Function to return post order traversal
 * @tparam Template
 * @return post order traversal
 */
template<class T>
string BST<T>::getPostOrderTraversal() {
    //return getPostOrder elements with root as argument
    return getPostOrderTraversal(root);
}
/**
 * Helper function to return post order traversal
 * @tparam Template
 * @param ptr to element
 * @return post order traversal
 */
template<class T>
string BST<T>::getPostOrderTraversal(BST::Node *&ptr) {
    //create a string builder object
    stringstream ss;
    //if root is not equal null
    if (ptr != nullptr) {
        //past function left element in the string builder
        ss << getPostOrderTraversal(ptr->left);
        //past function right element in the string builder
        ss << getPostOrderTraversal(ptr->right);
        //pass BST value in the string builder
        ss << ptr->data << " ";
    }
    //return string builder
    return ss.str();
}

/**
 * Returns a string of elements that are the ancestor(s) of the given node.
 * @tparam Template
 * @param key to find ancestors of
 * @return string element of ancestors
 */
template<class T>
string BST<T>::getAncestors(T key) {
    //declare a string variable to assign to getAncestor function with root and key
    string ancestors = getAncestors(root, key);
    //if ancestor equal null
    if (ancestors == "") {
        //return string function
        return string();
    } else {
        //return string element of ancestors
        return ancestors.substr(1);
    }
}

/**
 * private helper function to Returns a string of elements that are the ancestor(s) of the given node.
 * @tparam Template
 * @param key to find ancestors of
 * @return string element of ancestors
 */
template<class T>
string BST<T>::getAncestors(BST::Node *&ptr, T key) {
    //create a string builder object
    stringstream ss;
    //check if BST value is equal to the key
    if (ptr->data == key) {
        //pass nothing to the string builder object
        ss << " ";
        //return string builder object
        return ss.str();
    }
    //check left side of the tree
    if (ptr->left) {
        //declare a temporary and assign it ot getancestor function with left and key value
        string temp = getAncestors(ptr->left, key);
        //if temporary string is not equal to null
        if (temp != "") {
            //pass elements to the string builder
            ss << temp << " " << ptr->data;
            //return string builder
            return ss.str();
        }
    }
    //check right side of the tree
    if (ptr->right) {
        //declare a temporary and assign it ot getancestor function with right and key value
        string temp = getAncestors(ptr->right, key);
        //if temporary string is not equal to null
        if (temp != "") {
            //pass elements to the string builder
            ss << temp << " " << ptr->data;
            //return string builder
            return ss.str();
        }
    }
    //return string builder function
    return std::string();

}

/**
 * Returns the level of a node in the BST. If the node with the given value is not present in the BST, returns -1
 * @tparam Template
 * @param item to get level in the tree
 * @return Returns the level of a node
 */
template<class T>
int BST<T>::getLevel(T item) {
    //return getlevel elements with root and node as argument
    return getLevel(root, item);
}

/**
 * private helper function to Returns the level of a node in the BST.
 * @tparam Template
 * @param ptr tree
 * @param item node
 * @return Returns the level of a node
 */
template<class T>
int BST<T>::getLevel(BST::Node *&ptr, T item) {
    //declaring level variable and assign to -1
    int level = -1;
    //if left value is equal to item
    if (ptr->data == item) {
        //return 0
        return 0;
    }
    //check right value
    if (ptr->left) {
        //assign level to getlevel function with left and item value as argument
        level = getLevel(ptr->left, item);
    }
    //check if level is equal to -1 and right value
    if (level == -1 && ptr->right) {
        //assign level to getlevel function with right and item value as argument
        level = getLevel(ptr->right, item);
    }
    //check if level is equal to -1
    if (level == -1) {
        //return -1
        return -1;
    }
    //return level plus 1
    return level + 1;
}


#endif //PROJECT_2_BST_H
