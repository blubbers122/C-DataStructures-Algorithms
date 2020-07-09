#include <iostream>

using namespace std;

class LinkedList {
private:

  typedef struct node{
    int data;
    node* next;
  }* nodePtr;

  nodePtr head;
  nodePtr current;
  nodePtr temp;

public:
  LinkedList() {
    head = NULL;
    current = NULL;
    temp = NULL;
  }

  void AddNode(int addData) {
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if (head != NULL) {
      current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = n;
    }
    else {
      head = n;
    }
  }

  void DeleteNode(int delData) {
    nodePtr delPtr = NULL;
    current = head;
    temp = head;
    while (current != NULL && current->data != delData) {
      temp = current;
      current = current->next;
    }
    if (current == NULL) {
      cout << delData << " was not in the list.\n";
      delete delPtr;
    }
    else {
      delPtr = current;
      current = current->next;
      temp->next = current;
      if (delPtr == head) {
        head = head->next;
        temp = NULL;
      }
      delete delPtr;
      cout << delData << " was deleted.\n";
    }
  }

  void PrintList() {
    current = head;
    cout << "List contents:\n";
    while (current != NULL) {
      cout << current->data << endl;
      current = current->next;
    }
  }

  void PrintSum() {
    current = head;
    int sum = 0;
    while (current != NULL) {
      sum += current->data;
      current = current->next;
    }
    cout << "The sum of the data in your list is " << sum << endl;
  }
};

int main() {
  LinkedList list;
  list.AddNode(3);
  list.AddNode(5);
  list.AddNode(7);
  list.PrintList();
  list.DeleteNode(3);
  list.PrintList();
  list.AddNode(23);
  list.PrintList();
  list.PrintSum();

  return 0;
}
