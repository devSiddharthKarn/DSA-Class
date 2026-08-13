#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int element){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data=element;
    newNode->next = NULL;
    return newNode;
}

typedef struct SLL{
    Node* first;
    Node* last;
} SLL;

SLL createSLL(){
    SLL sll;
    sll.first=NULL;
    sll.last=NULL;
    return sll;
}

void insertAtBeginning(SLL* sll,int element){
    
    Node* newNode = createNode(element);

    if(sll->first==NULL && sll->last==NULL){
        sll->first=newNode;
        sll->last=newNode;
    }else{
        newNode->next = sll->first;
        sll->first = newNode;
    }
    return;
}

void insertAtEnd(SLL* sll,int element){
    
    Node* newNode = createNode(element);

    if(sll->first==NULL && sll->last==NULL){
        sll->first =sll->last=newNode;
    }else{
        sll->last->next = newNode;
        sll->last = newNode;
    }
    return;
}

void printTraversalData(SLL* sll){
    Node* ptr = sll->first;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        printf("->");
        ptr=ptr->next;
    }
    printf("NULL");
    printf("\n");
}

void insertAtPosition(SLL* sll,int index_1_order , int element){
    if(index_1_order==1){
        insertAtBeginning(sll,element);
        return;
    }

    

    Node* ptr = sll->first;
    for(int i=1;i<index_1_order-1;i++){
        if(ptr==NULL){
            // need to insert at last
            insertAtEnd(sll,element);
            return;
        }
        ptr=ptr->next;
    }

    Node* newNode = createNode(element);
    newNode->next = ptr->next;
    ptr->next = newNode;
    return;
}

void deleteFromBeginning(SLL* sll){
    Node* tempAlloc = sll->first;
    if(tempAlloc==NULL){
        printf("Linked List is empty.Can't delete from Beginning");\
        return;
    }
    sll->first = sll->first->next;
    free(tempAlloc);
}

void deleteFromEnd(SLL* sll){
    Node* ptr = sll->first;
    if(ptr==NULL){
        printf("Linked List is Empty. Can't delete from the end");
        return;
    }
    if(ptr->next==NULL){
        sll->first=NULL;
        sll->last=NULL;
        free(ptr);
        return;
    }
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    Node* last = ptr->next;
    ptr->next=NULL;
    free(last);
    return;

}

void deleteFromPosition(SLL* sll,int index_1_order){
    if(index_1_order==1){
        deleteFromBeginning(sll);
        return;
    }

    Node* ptr = sll->first;
    for(int i=1;i<index_1_order-1;i++){
        if(ptr==NULL){
            // need to delete from the end
            deleteFromEnd(sll);
            return ;
        }
        ptr=ptr->next;
    }
    Node* tempAlloc = ptr->next;
    ptr->next = ptr->next->next;
    free(tempAlloc);
    return;
}

int findElementIn1OrderIndex(SLL* sll,int element){
    Node* ptr = sll->first;
    int index =1;
    while(ptr!=NULL){
        if(ptr->data==element) return index;
        ptr=ptr->next;
        index++;
    }
    return -1;
}

int main(){
    SLL sll = createSLL();
    printTraversalData(&sll);
    insertAtBeginning(&sll,2);
    printTraversalData(&sll);
    insertAtEnd(&sll,3);
    printTraversalData(&sll);
    insertAtPosition(&sll,2,2);
    printTraversalData(&sll);
    deleteFromBeginning(&sll);
    printTraversalData(&sll);
    deleteFromBeginning(&sll);
    printTraversalData(&sll);
    deleteFromEnd(&sll);
    printTraversalData(&sll);
    insertAtPosition(&sll,3,1);
    printTraversalData(&sll);
    deleteFromPosition(&sll,1);
    printTraversalData(&sll);
    insertAtBeginning(&sll,23);
    insertAtEnd(&sll,34);
    insertAtPosition(&sll,2,1);
    int index = findElementIn1OrderIndex(&sll,1);
    if(index==-1){
        printf("Element not found");
    }else{
        printf("Element has been found at %d index in the Linked List",index);
    }
    
    return 0;
}