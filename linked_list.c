#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *next_node;
} node_s;

static node_s *__head= NULL;

int init( int data ){

    __head = malloc(sizeof(node_s));

    if (__head == NULL){
        printf("Memory allocation failed");
        return -1;
    }
    
    __head -> data = data;
    __head -> next_node = NULL;

    return 1;
}

 int add ( int data){
    node_s *cur;
    node_s *n= malloc(sizeof(node_s));
    if ( !n ){
        return -1;
    }
    cur = __head;
    n -> next_node = cur;
    n -> data = data ;
    __head = n;

    return 0;
 }


int exists(int data){
    for(node_s *cursor = __head;
    cursor != NULL ;
    cursor = cursor -> next_node){
        if (cursor -> data == data){
           return 1;
        }
        }


   return 0;

  }

int delete(int data) {
    node_s *p = NULL;
    node_s *c = __head;

    while (c != NULL) {
        if (c->data == data) {
            if (p == NULL) {
                // Deleting the head node
                __head = c->next_node;
            } else {
                p->next_node = c->next_node;
            }
            free(c);
            printf("deleted %d\n", data);
            return 1;
        }
        p = c;
        c = c->next_node;
    }
    return 0;  
}

  
int insert( int key, int data){
    node_s *k, *n;
    for( k = __head ;
         k != NULL ;
         k = k -> next_node){
        if ( k -> data == key){
           break;
        }
        }
        n = malloc( sizeof(node_s));

        n -> data = data;
        n -> next_node = k -> next_node;
        k -> next_node = n;

        return 1;
    
 }
  
void traverse(void) {
    for(node_s *cursor = __head;
        cursor != NULL ;
        cursor = cursor -> next_node){
            printf("%d\n", cursor -> data);
        }

        


 }