#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// static global variable
static struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}


void insertAtEnd ( int data )
{
  struct Node * new_node = malloc(sizeof(struct Node));
  new_node -> data = data;
  new_node -> next = NULL;
  
  struct Node * temp = head;
  while ( temp -> next != NULL ){
    temp = temp -> next;
  }
  
  temp -> next = new_node;
}

void insertAfterValue ( int target , int data )
{
  struct Node * temp = head;

  
  while ( temp != NULL && temp -> data != target){
    temp = temp -> next;
  }
  
  struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
}


void findMiddle()
{
  struct Node * slow = head;
  struct Node * fast = head;
  
  while ( fast != NULL && fast -> next != NULL ){
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  
  printf("The Middle node is %d: ", slow -> data);
  
}

void detectCycle()
{
  struct Node * slow = head;
  struct Node * fast = head;
  
  while ( fast != NULL && fast -> next != NULL ){
    slow = slow -> next;
    fast = fast -> next -> next;
    
    
    if ( slow == fast )
    printf("Cycle detected");
  }
  
  printf("No cycle detected");
  
  
}

void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtEnd(5);
    printList();  // Output: 3 -> 2 -> 1 -> NULL
    findMiddle();
    printf("\n");
    detectCycle();
    return 0;
}
