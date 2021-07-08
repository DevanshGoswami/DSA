#include <iostream>

using namespace std;

struct Node {
  int data; 
  Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};

void printList(Node *head){
    Node *current = head; 
    
    while( current != NULL ){
        cout<<current->data<<" "; 
        current = current->next;
    }
    
    cout<<endl;
}

int searchList(Node *head, int x){
    int position = 1;
    Node *current = head; 
    
    while( current!=NULL ){
        if(current->data == x){
            return position;
        }
        
        else{
            current = current->next;
            position++;
        }
    }
    
    return -1;
}

Node *insertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int x){
    
    Node *temp = new Node(x);
    
    if(head == NULL){
        return temp; 
    }
    
    Node *current = head;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = temp;
    
    return head;
}

Node *deleteAtHead( Node *head ){
    
    if( head == NULL ) {
        return head;
    }
    
    if( head->next == NULL ){
        delete head;
        
        return NULL; 
    }
    
    Node *temp = head->next; 
    
    delete head;
    
    return temp;
    
}

Node *deleteAtEnd(Node *head){
    if(head == NULL){
        return head; 
    }
    
    Node *current = head; 
    Node *temp; 
    
    while(current->next->next != NULL){
        current = current->next; 
    }
    
    delete (current->next);
    
    current->next = NULL;
    
    return head; 
}

Node *insertAtN(Node *head, int n, int x){
    
    Node *current = head; 
    int position = 1; 
    
    while(position != n-1){
        current = current->next; 
        position++;
    }
    
    Node *temp = new Node(x);
    
    temp->next = current->next;
    
    current->next = temp;
    
    return head;
}

Node *sortedInsert(Node *head, int x){
    
    Node *temp = new Node(x);
    
    if(head == NULL){
        return temp;
    }
    
    if(head->data > x){
        temp->next = head; 
        return temp;
    }
    
    Node *current = head;
    
    while(current->next->data < x && current->next != NULL){
        current = current->next; 
    }
    
    temp->next = current->next; 
    
    current->next = temp;
    
    return head; 
}

void printMiddleOfList(Node *head){
    Node *slow = head; 
    Node *fast = head; 
    
    if(head == NULL){
        cout<<"Empty List";
    }
    
    if(head->next->next == NULL){
        cout<<head->next->data; 
    }
    
    while(fast!=NULL && fast->next!= NULL){
        slow = slow->next; 
        fast = fast->next->next;
    }
    
    cout<<slow->data; 
    cout<<endl;
}

void printNthNodeFromEnd(Node *head, int n){
 
   
   Node *first = head; 
   Node *second = head; 
   
   int i = 0;
   
   while(i<n){
       second = second->next; 
       i++;
   }
   
   while(second != NULL){
       second = second->next;
       first = first->next;
   }
   
   cout<<first->data<<endl;
}

Node *reverseLinkedList(Node *head){
    Node *current = head;
    Node *previous = NULL;
    
    while(current != NULL){
       Node *following = current->next; 
       current->next = previous;
       previous = current; 
       current = following; 
    }
    
    return previous;
}

Node *removeDuplicatesSortedLL(Node *head){
    Node *current = head; 
    
    if(head == NULL){
        return NULL;
    }
    
    while(current->next != NULL && current != NULL){
        if(current->data == current->next->data){
            Node *temp = current->next->next;
            delete (current->next);
            current->next = temp;
        }
        else{
           current = current->next;   
        }
    }
    
    return head; 
}


int main()
{
    
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    
    
    printList(head);
    
    cout<<searchList(head, 20)<<endl;
    cout<<searchList(head, 50)<<endl;
    
    head = insertAtBegin(head, 5);
    
    printList(head);
    
    head = insertAtEnd(head, 40);
    
    printList(head);
    
    head = deleteAtHead(head);
    
    printList(head);
    
    head = deleteAtEnd(head);
    
    printList(head);
    
    head = insertAtN(head, 3, 25);
    
    printList(head);
    
    head = sortedInsert(head, 15);
    
    printList(head);
    
    printMiddleOfList(head);
    
    printNthNodeFromEnd(head, 1);
    
    head = reverseLinkedList(head);
    
    printList(head);
    
    head = reverseLinkedList(head);
    
    printList(head);
    
    head = sortedInsert(head,15);
    
    head = sortedInsert(head,15);
    
    head = sortedInsert(head, 25);
    
    printList(head);
    
    head = removeDuplicatesSortedLL(head);
    
    printList(head);
    
    return 0;
}
