#include <iostream>

using namespace std;

class Node {
public:
  int id, score;
  string name;
  Node *nex;
  Node() {} // Default Constructot
  Node(int id, string name, int score) : id(id), name(name), score(score), nex(nullptr) {} // Constructot
};

class SubjectStatement {
private:
  Node *head;
public:
  SubjectStatement() : head(nullptr) {}
  
  void insert(int id, string name, int score) {
    Node *newNode = new Node(id, name, score);
    if (!head) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->nex) {
      temp = temp->nex; // Acsess to the last node
    }
    temp->nex = newNode;
  }

  void addToHead(int id, string name, int score) {
    Node *newNode = new Node(id, name, score);
    if (!head) {
      head = newNode;
      return;
    }
    /*
    Node *temp = head;
    head = newNode;
    newNode->nex = temp;
    */
    newNode->nex = head;
    head = newNode;
  }

  void deleteByID(int id) {
    if (!head) return;

    if (head->id == id) {
      Node *temp = head;
      head = head->nex;
      delete temp;
      return;
    }

    Node *current = head;
    while (current->nex && current->nex->id != id) {
      current = current->nex; // Traverse the list
    }

    if (current->nex) {
      Node *temp = current->nex;
      current->nex = current->nex->nex;
      cout << "Student With Name " << temp->name << " and ID: " << id << " Deleted Successfully." << endl;
      delete temp;
    }
    else {
      cout << "Student With ID: " << id << " doesn't EXIST." << endl;
    }
  }

  void deleteByName(string name) {
    if (!head) return;

    if (head->name == name) {
      Node *temp = head;
      head = head->nex;
      delete temp;
      cout << "Student With Name " << name << " Deleted Successfully." << endl;
      return;
    }

    Node *current = head;
    while (current->nex && current->nex->name != name) {
      current = current->nex;
    }

    if (current->nex) {
      Node *temp = current->nex;
      current->nex = current->nex->nex;
      delete temp;
      cout << "Student With Name [" << name << "] Deleted Successfully." << endl;
    }
    else {
      cout << "Student With Name [" << name << "] doesn't EXIST." << endl;
    }
  }

  bool isEmpty(){
    return head == NULL;
	}		

  void display() {
    Node *temp = head;
    while (temp) {
      cout << temp->id << "  | " << temp->score << "    | " << temp->name << endl;
      temp = temp->nex;
    }
  }

  bool searchID(int id) {
    if (!head) return false;

    Node *current = head;
    while (current->nex && current->nex->id != id) {
      current = current->nex; // Traverse the list
    }

    if (current->nex) {
      return true;
    }
    else {
      return false;
    }
  }

  int StdudentsCount() {
    Node *temp = head;
    int count = 0;
    while (temp) {
      temp = temp->nex;
      count++;
    }
    return count;
  }

  int getMinimumScore () {
    Node *temp = head;
    int minimum = INT_MAX;
    while (temp) {
      if (temp->score < minimum) minimum = temp->score;
      temp = temp->nex;
    }
    return minimum;
  }

  SubjectStatement copyList() {
    SubjectStatement copy;
    Node *temp = head;
    while (temp) {
      copy.insert(temp->id, temp->name, temp->score);
      temp = temp->nex;
    }
    return copy;
  }

  ~SubjectStatement() {
    while (head) {
      Node *temp = head;
      head = head->nex;
      delete temp;
    }
  }
};

int main() {
  SubjectStatement DataStructure;

  DataStructure.insert(1, "yusuf", 10);
  DataStructure.insert(2, "yusuf", 20);
  DataStructure.insert(3, "yusuf", 30);
  DataStructure.insert(4, "yusuf", 40);
  DataStructure.insert(5, "yusuf", 50);
  DataStructure.insert(6, "yusuf", 60);
  DataStructure.insert(7, "yusuf", 70);
  DataStructure.insert(8, "yusuf", 80);
  DataStructure.addToHead(9, "yusuf", 90);

  if (DataStructure.isEmpty() == 0) {
    cout << "The List is NOT EMPTY!\n";
  } else {
    cout << "The List is Empty.\n";
  }

  cout << "ID | Score | Name" << endl;
  DataStructure.display();
  cout << "===========================================\n";

  cout << "Student Count is: ";
  cout << DataStructure.StdudentsCount() << endl;

  cout << "-------------------------------------------\n";
  cout << "The Minimum Score is: ";
  cout << DataStructure.getMinimumScore() << endl;

  // cout << "-------------------------------------------\n";
  // cout << DataStructure.searchID(1) << endl;

  cout << "-------------------------------------------\n";
  DataStructure.deleteByID(1);
  cout << "-------------------------------------------\n";

  cout << "The List After Deleting Id no.1:\n";
  cout << "ID | Score | Name" << endl;
  DataStructure.display();
  cout << "===========================================\n";

  DataStructure.deleteByName("yusuf");

  // Name Doesn't Exist
  cout << "-------------------------------------------\n";
  DataStructure.deleteByName("mohamed");

  DataStructure.~SubjectStatement();

  cout << "-------------------------------------------\n";
  if (DataStructure.isEmpty() == 0) {
    cout << "NOT EMPTY!\n";
  } else {
    cout << "The List is Empty.\n";
  }
}
