/*
//SINGLY LINKED LIST :-

**Q1 INSERTION AT HEAD:-

#include<iostream>
using namespace std;

// Node structure
struct Node {
   int data;
   Node* next;

   // Constructor
   Node(int val) {
       data = val;
       next = nullptr;
   }
};

  void insertionAtHead(Node* &head , int d){
   //new node creation
   Node *temp = new Node(d);
   temp ->next = head;
   head = temp;
  }
  
  void display(Node* head){
    Node* temp =head;
    while(temp != nullptr){
      cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

  }

   int main() {
      Node* head = nullptr; // Initialize an empty linked list

    insertionAtHead(head, 10);
    insertionAtHead(head, 20);
    insertionAtHead(head, 30);

    cout << "Linked List: ";
    display(head);

    return 0;
    
}

**Q2 END INSERTION :-

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert at tail
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a new node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Printing the initial list
    print(head);

    // Inserting at the tail
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);

    // Printing the updated list
    print(head);

    return 0;
}


// Q3 INSERTION AT ANY POSTION :-

void insertAtAnyPoint(Node* head , int position , int d){
    Node* temp = head;
    int cnt =1;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }
    //creating a node for data d
     Node* nodetoinsert = new Node(d);
     nodetoinsert ->next = temp->next;
     temp->next = nodetoinsert;
}

//Q4 DELETION OF NODE:-

//function to delete the node:-
void deleteNode(int position , Node* &head){
//delete first or start node:-
 if(position == 1){
    Node* temp = head;
    head = head->next ;
    //meamory free of first node
    temp->next = NULL;
    delete temp;
 }
 else{
    //delete at any postion 
        Node* curr = head;  //curr means current node , prev means previous node
        Node* prev = NULL;

        int cnt =1;
        while(cnt < position ){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
 }
}

//** DOWBLY LINKED LIST :----- 

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev; // Added for Doubly Linked List

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Traversing a linked list
void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Gives length of Linked List
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len;
}

void deleteNode(int position, Node* &head, Node* &tail) {
    // Deleting the first node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        
        // If the list becomes empty
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // If list is now empty, update tail as well
        }

        temp->next = NULL;
        delete temp;
    }
    else {
        // Deleting a middle or last node
        Node* curr = head;
        int cnt = 1;

        while (cnt < position && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Invalid position!\n";
            return;
        }

        // If deleting the last node
        if (curr->next == NULL) {
            tail = curr->prev; // Update tail to new last node
            tail->next = NULL;
            curr->prev = NULL;
            delete curr;
            return;
        }

        // Deleting a middle node
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}


// Insert at Head
void insertAtHead(Node* &tail, Node* &head, int d) {
    // Empty list
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp; // Fixed the missing prev pointer
        head = temp;
    }
}

// Insert at Tail
void insertAtTail(Node* &tail, Node* &head, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert at a Specific Position
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    // Insert at Start
    if (position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at Last Position
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    // Creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Main Function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtTail(tail, head, 25);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

     insertAtPosition(tail, head, 1, 101);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteNode(7, head , tail);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    return 0;
}












*/