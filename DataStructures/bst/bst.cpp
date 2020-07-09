#include <iostream>
#include <string>

using namespace std;

class BST {
private:
  typedef struct node {
    int data;
    int count;
    node* left;
    node* right;
  }* nodePtr;

  nodePtr root;

  nodePtr _addNode(nodePtr cursor, int value) {
    if (cursor == NULL) {
      cursor = new node;
      cursor->data = value;
      cursor->left = NULL;
      cursor->right = NULL;
      cursor->count = 1;
    }
    else if (value < cursor->data) {
      cursor->left = _addNode(cursor->left, value);
    }
    else if (value > cursor->data) {
      cursor->right = _addNode(cursor->right, value);
    }
    else {    
      cursor->count++;
    }
    return cursor;
  }

  void _printTree(nodePtr cursor) {
    if (cursor == NULL) {
      return;
    }
    //prints every left most leaf first
    _printTree(cursor->left);
    cout << cursor->data << " ";
    _printTree(cursor->right);
  }

  nodePtr _deleteNode(nodePtr cursor, int value) {
    nodePtr temp;
    //handles the case of the value not being in the tree
    if (cursor == NULL) {
      cout << value << " wasn't in the tree." << endl;
      return NULL;
    }
    // refines search to the left
    else if (value < cursor->data) {
      cursor->left = _deleteNode(cursor->left, value);
    }
    // refines search to the right
    else if (value > cursor->data) {
      cursor->right = _deleteNode(cursor->right, value);
    }
    // if node to be deleted has 2 children
    else if (cursor->left && cursor->right) {
      temp = findMin(cursor->right);
      cursor->data = temp->data;
      cursor->right = _deleteNode(cursor->right, cursor->data);
    }
    else {
      temp = cursor;
      if (cursor->left == NULL) {
        cursor = cursor->right;
      }
      else if (cursor->right == NULL) {
          cursor = cursor->left;
      }
      delete temp;
    }
    return cursor;
  }

  nodePtr findMin(nodePtr cursor) {
    if(cursor == NULL)
        return NULL;
    else if(cursor->left == NULL)
        return cursor;
    else
        return findMin(cursor->left);
  }

public:
  BST() {
    root = NULL;
  }

  void addNode(int value) {
    root = _addNode(root, value);
  }

  void printTree() {
    _printTree(root);
    cout << "\n";
  }

  void deleteNode(int value) {
    root = _deleteNode(root, value);
  }
};

int main() {
  BST bst;
  bst.addNode(5);
  bst.addNode(4);
  bst.addNode(9);
  bst.addNode(3);
  bst.addNode(1);
  bst.addNode(7);
  bst.printTree();
  bst.deleteNode(0);
  bst.printTree();
  return 0;
}
