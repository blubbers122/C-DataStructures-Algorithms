#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Hash {
private:
  typedef struct node{
    string name;
    node* next;
  }* nodePtr;

  static const int tableSize = 26;
  nodePtr table[tableSize];
  nodePtr n;
  nodePtr cursor;
  int count;

  int hasher(string key) {
    int first = (int)key[0];
    // make sure key starts with letter
    if (first < 65 || first > 122 || first > 90 && first < 97) {
      return -1;
    }
    // capitals
    else if (first < 91) {
      return first - 65;
    }
    // lowercase
    else {
      return first - 97;
    }
  }

public:
  Hash() {
    for(int i = 0; i < tableSize; i++) {
      table[i] = new node;
      table[i]->name = "empty";
      table[i]->next = NULL;
    }
    count = 0;
  }

  void addToTable(string name) {
    int index = hasher(name);
    if (index < 0) {
      cout << "Couldn't add item to table.\n";
      return;
    }
    if (table[index]->name == "empty") {
      table[index]->name = name;
    }
    else {
      n = new node;
      n->name = name;
      n->next = NULL;
      cursor = table[index];
      while (cursor->next != NULL) {
        cursor = cursor->next;
      }
      cursor->next = n;
    }
    count++;
  }

  void printTable() {
    for (int i; i < tableSize; i++) {
      cursor = table[i];
      while (cursor != NULL) {
        cout << cursor->name << " ";
        cursor = cursor->next;
      }
      cout << "\n";
    }
  }

  void printCount() {
    cout << "There are " << count << " items in the table.\n";
  }

  ~Hash() {
    nodePtr temp;
    for (int i = 0; i < tableSize; i++) {
      temp = table[i];
      cursor = table[i];
      while (cursor != NULL) {
        cout << "deleting " << cursor->name << endl;
        cursor = cursor->next;
        delete temp;
        temp = cursor;
      }
    }
  }
};

int main() {
  Hash hash;
  hash.addToTable("Apple");
  hash.addToTable("Acorn");
  hash.addToTable("cherry");
  hash.addToTable("Cucumber");
  hash.addToTable("34");
  hash.addToTable("coke");
  hash.addToTable("orange");
  hash.addToTable("Carrot");
  hash.printTable();
  hash.printCount();
  return 0;
}
