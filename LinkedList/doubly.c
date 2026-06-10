#include "stdio.h"
#include "stdlib.h"

typedef struct Node Node;

struct Node {
    int data;
    Node* previous;
    Node* next;
};

Node* createNode(int element,Node* previous,Node* next){
    Node* node = (Node*)malloc(sizeof(Node));
    node->previous=previous;
    node->next=next;
    node->data=element;
    return node;
}

struct DoublyLinkedList{
    Node* first;
    Node* last;
};

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList* createDoublyLinkedList(){
    DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    dll->first=NULL;
    dll->last=NULL;
    return dll;
}


void insertAtBeginning(DoublyLinkedList* dll, int element){
    Node* newNode = createNode(element,NULL,dll->first);
    if(dll->last==NULL){
        dll->last=newNode;
    }
    if(dll->first){
        dll->first->previous=newNode;
    }
    dll->first = newNode;
}

void insertAtEnd(DoublyLinkedList* dll,int element){
    
    Node* node = createNode(element,dll->last,NULL);
    
    if(dll->first==NULL){
        dll->first = node;
    }
    dll->last->next = node;
    dll->last=node;
    return;
}

void insertAtPosition(DoublyLinkedList* dll,int index_1_order,int element){
    if(index_1_order==1){
        insertAtBeginning(dll,element);
        return;
    }
}

void printForwardTraversalData(DoublyLinkedList* dll){
    printf("NULL");
    Node* ptr = dll->first;
    while(ptr!=NULL){
        printf("->");
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("->NULL");
    printf("\n");
    return;
}

void printBackwardTraversalData(DoublyLinkedList* dll){
    printf("NULL");
    Node* ptr = dll->last;
    while(ptr!=NULL){
        printf("->");
        printf("%d",ptr->data);
        ptr=ptr->previous;
    }
    printf("->NULL");
    printf("\n");
    return;
}

int main(){
    DoublyLinkedList* dll = createDoublyLinkedList();

    insertAtBeginning(dll,23);
    insertAtBeginning(dll,32);
    insertAtBeginning(dll,10);
    insertAtEnd(dll,10);
    insertAtEnd(dll,100);
    insertAtBeginning(dll,45);
    insertAtEnd(dll,67);
    printForwardTraversalData(dll);
    printBackwardTraversalData(dll);

    return 0;
}