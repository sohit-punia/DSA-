/*
//Q1 REVERSE A LINKED LIST:-


 Node* reverseLinkedList(Node* head){

    if(head == NULL || head->next == NULL){
            return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    while(curr != NULL){
        forward = curr->next; // ye taki aage ki LL lost na ho
        curr->next = prev; //LL ko peeche point karwa diya taki reverse ho ske
        prev = curr;// ab prv ko aage badha diya
        curr = forward; // curr ko aage badha diya
        //ye order important h dhyan se
    }
    return prev;
 }

 void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
 }


 int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}

//Q2 REVERSE LL (APPROCH 2 BY RECURSION)

void reverse( Node* &head , Node* curr , Node* prev){
    //base case 
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverse(head , forward ,curr);
    curr->next = prev;
}
Node* reverseLinkedList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head , curr , prev);
    return head;

}

//Q3 MIDDLE OF LINKED LIST :-


int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

 Node* findMiddleElement(Node* head){
    int len = getLength(head);
    int ans = len/2;

    Node* temp = head;
    int cnt=0;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;

     IN INT MAIN ()- 
     // Finding the middle element
    Node* middle = findMiddleElement(head);
    if (middle) {
        cout << "Middle Element: " << middle->data << endl;
    } else {
        cout << "List is empty!" << endl;
    }


//Q4 REVERSE LENKED LIST IN K GROUPS :- IMP HAI MICROSOFT ME AAYA H

 Node* kReverse(Node* head , int k){
    //base case
    if(head == NULL){
     return head;   
    }
    //step 1 reverse first k elements
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt =0;
    while(curr != NULL && cnt <k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    //step 2: recursion dekhlega aage ka 
    if(next != NULL){
        head->next = kReverse(next , k);
    }
    //step 3 return head of reversed linked list
    return prev;
 }

 //Q5 IS THIS LIST IS CIRCULAR RETURN TRUE OR FALSE:-

 bool isCircularList(Node* head){
    //empty list
    if(head == NULL){
        return true;
    }
    Node* temp = head ->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    else{
        return false;
    }

}

//Q6 DETECT CYCLR IN LINKED LIST :-

*** FLOYD'S CYCLE DETECTION ALGORITHIM ***

 Node* floydDetectLoop(Node* head){

    if(head == NULL){
        return NULL ;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast ->next;
        if(fast != NULL){
            fast = fast ->next;
        }
        if(slow == fast ){
            cout<<"cycle is present at "<<slow->data <<endl;
            return slow;
        } 
        slow = slow->next;  
    }
    return NULL;

 }

 //NOW CYCLE IS DETECTED NOW FIND STARTING NODE OF THE LOOP :-
 //Q7 IF THERE IS CYCLE THEN FIND THE STARTING NODE OF THE CYCLE :-
//EXPLANATION :-
the point where slow and fast meet is intercation point we put slow at head , fast ast interaction point now they move eith one step when thwy meet is the startint point of node 

#include <iostream>
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

 void createLoop(Node* head, int pos) {
    if (pos == -1) return; // No loop

    Node* temp = head;
    Node* loopStart = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos) {
            loopStart = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopStart; // Creating a loop
}
Node* floydDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;  // Move slow by 1 step
        fast = fast->next->next; // Move fast by 2 steps

        if(slow == fast){
            cout << "Cycle is present at " << slow->data << endl;
            return slow;  // Return the meeting point
        }
    }
    return NULL;
}

Node* getStartNode(Node* head){
    if (head == NULL) {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    if (intersection == NULL) {
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = intersection;  // Reset fast to intersection

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

 void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
 }


 int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
   Node* head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);
   head->next->next->next->next = new Node(5);

   // Print the original linked list (without loop)
   cout << "Original Linked List: ";
   printList(head);

   // Creating a loop at position 2 (1-based index)
   createLoop(head, 2);

   // Detect if a cycle is present
   Node* intersection = floydDetectLoop(head);
   if (intersection) {
       cout << "Cycle detected at node with value: " << intersection->data << endl;
       
       // Find the start node of the cycle
       Node* startNode = getStartNode(head);
       cout << "Cycle starts at node with value: " << startNode->data << endl;
   } else {
       cout << "No cycle detected." << endl;
   }

    return 0;
}

//Q8 REMOVE CYCLE FROM LINKED LIST:-

#include <iostream>
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

 Node* floydDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;  // Move slow by 1 step
        fast = fast->next->next; // Move fast by 2 steps

        if(slow == fast){
            cout << "Cycle is present at " << slow->data << endl;
            return slow;  // Return the meeting point
        }
    }
    return NULL;
}

 Node* getStartNode(Node* head){
    if (head == NULL) {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    if (intersection == NULL) {
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = intersection;  // Reset fast to intersection

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

  Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* startOfLoop = getStartNode(head);
    if(startOfLoop == NULL){
        return head;

    }
    Node* temp = startOfLoop;
    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp ->next = NULL;
    return head;
  }

 void createLoop(Node* head, int pos) {
    if (pos == -1) return; // No loop

    Node* temp = head;
    Node* loopStart = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos) {
            loopStart = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopStart; // Creating a loop
}

 void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
 }


 int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Creating a loop at position 2 (1-based index)
    createLoop(head, 2);

    // Detect cycle
    Node* intersection = floydDetectLoop(head);
    if (intersection) {
        cout << "Cycle detected at node with value: " << intersection->data << endl;

        // Find and print the start node of the cycle
        Node* startNode = getStartNode(head);
        cout << "Cycle starts at node with value: " << startNode->data << endl;

        // Remove the loop
        head = removeLoop(head);

        // Print linked list after removing loop
        cout << "Linked List after removing cycle: ";
        printList(head);
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}


//Q9 REMOVE DUPLICATES FROM SORTED / UNSORTED LINKED LIST:-
1) SORTED LL 

Node* uniqueSortList(Node* head){
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
            
        }
        else{
            //not equal
            curr = curr->next;
        }
    }
    return head;
 }
    //UNSORTED ABHI NHI KIYA H 


 //Q10 SORT 0'S , 1'S , 2'S IN LINKED LIST:-
 
   Node* sortList(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp ->data == 0){
            zeroCount++;
        }
        else if(temp ->data == 1){
            oneCount++;
        }
        else if(temp ->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }
    temp =head;
    while(temp != NULL){
        if(zeroCount != 0){
                temp->data = 0;
                zeroCount--;
            }
        else if(oneCount != 0){
                temp->data = 1;
                oneCount--;
            }
        else if(twoCount != 0){
                temp->data = 2;
                twoCount--;
            }
        temp = temp->next;

    }
    return head;
  }

//Q11 MERGE TWO SORTED LINKED LIST :-
  



*/