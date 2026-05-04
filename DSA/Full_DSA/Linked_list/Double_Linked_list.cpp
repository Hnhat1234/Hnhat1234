#include <bits/stdc++.h>

using namespace std;

class Node{
 public:
  int data;
  Node *next;
  Node *prev;
  Node(){
    data = 0;
    next = NULL;
    prev = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};
class LinkedList{
  Node *head;
  int len;

 public:
  LinkedList(){
    len = 0;
    head = NULL;
  }
  void Insert(int data){
    Node *newNode = new Node(data);

    if (head == NULL){
      head = newNode;
      len += 1;
      return;
    }

    Node *temp = head;
    newNode->next = this->head;
    temp->prev = newNode;

    this->head = newNode;
    len += 1;
  }

  void Insert(int data, int position){
    if (position > len){
       cout << "Invalid insert position";
       return;
    }
    Node *newNode = new Node(data);
    Node *temp1 = head;
    Node *temp2;
    int counter = position;
    while (counter > 0){
       temp2 = temp1;
       temp1 = temp1->next;
       counter--;
    }
    if (position == 0){
       if (head == NULL){
         head = newNode;
         len += 1;
         return;
       }

       Node *temp = head;
       newNode->next = this->head;
       temp->prev = newNode;
       this->head = newNode;
       len += 1;
       return;
    }
    temp2->next = newNode;
    newNode->next = temp1;
    newNode->prev = temp2;
    len += 1;
  }

  void Delete(int position){
    if (len < position - 1){
      cout << "Invalid delete position";
      return;
    }
    int counter = position;

    Node *deleteNode = head;
    Node *prev = NULL;
    while (counter > 0){
      prev = deleteNode;
      deleteNode = deleteNode->next;
      counter--;
    }
    if (deleteNode->next == NULL || prev == NULL){
      prev->next = NULL;
      delete deleteNode;
      deleteNode = nullptr;
      len -= 1;
      return;
    }
    Node *upper = deleteNode->next;
    prev->next = upper;

    delete deleteNode;
    deleteNode = nullptr;

    len -= 1;
  }

  void Print(){
    Node *temp = head;
    if (temp == NULL){
      cout << "There are currently no list" << '\n';
      return;
    }

    while (temp != NULL){
      cout << temp->data << "->";
      temp = temp->next;
    }
  }
};

int main(){
   LinkedList a;
   a.Insert(4);
   a.Insert(3);
   a.Insert(2);
   a.Insert(1);

   a.Insert(1, 4);

   a.Print();
   cout << '\n';
}
