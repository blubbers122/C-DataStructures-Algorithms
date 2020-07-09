#include <iostream>

using namespace std;

class LinkedList {
private:

  typedef struct node{
    int data;
    node* next;
    node* prev;
  }* nodePtr;

  nodePtr head;
  nodePtr tail;
  nodePtr n;
  int length;

public:
  LinkedList() {
    head = NULL;
    n = NULL;
    tail = NULL;
    length = 0;
  }

  void addToFront(int value) {
    n = new node;
    n->data = value;
    n->prev = NULL;
    // if this is first value added to list
    if (head == NULL) {
      n->next = NULL;
      head = n;
      tail = n;
    }
    else {
      head->prev = n;
      n->next = head;
      head = n;
    }
    cout << value << " was added to the front." << endl;
    length++;
  }

  void addToTail(int value) {
    n = new node;
    n->data = value;
    n->next = NULL;
    // if this is first value added to list
    if (head == NULL) {
      n->prev = NULL;
      head = n;
      tail = n;
    }
    else {
      tail->next = n;
      n->prev = tail;
      tail = n;
    }
    cout << value << " was added to the tail." << endl;
    length++;
  }

  void printForward() {
    cout << "Forward:\n";
    n = head;
    if (n == NULL) {
      cout << "List is empty.\n";
    }
    while (n != NULL) {
      cout << n->data << endl;
      n = n->next;
    }
  }

  void printBackward() {
    cout << "Backwards:\n";
    n = tail;
    if (n == NULL) {
      cout << "List is empty.\n";
    }
    while (n != NULL) {
      cout << n->data << endl;
      n = n->prev;
    }
  }

  void printLength() {
    cout << "Length: " << length << endl;
  }

  void deleteNode(int numToDelete) {
    n = head;
    while (n != NULL) {
      if (n->data == numToDelete) {
        if (head == n) {
          head = n->next;
        }
        if (tail == n) {
          tail = n->prev;
        }
        if (n->prev != NULL) {
          n->prev->next = n->next;
        }
        if (n->next != NULL) {
          n->next->prev = n->prev;
        }
        delete n;
        cout << numToDelete << " was deleted.\n";
        length--;
        return;
      }
      n = n->next;
    }
    cout << numToDelete << " was not found in the list." << endl;
  }
};

int main() {
  LinkedList list;
  list.addToFront(2);
  list.addToFront(7);
  list.addToFront(8);
  list.addToFront(90);
  list.addToFront(56);
  list.addToFront(4);
  list.addToFront(3);
  list.addToFront(6);
  list.printLength();
  list.printForward();
  list.printBackward();
  list.deleteNode(90);
  list.printForward();
  list.printBackward();
  list.printLength();

  return 0;
}
