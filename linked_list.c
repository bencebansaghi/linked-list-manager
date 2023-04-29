#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
char data[10];
struct node *pNext;
} Node;

int isEmpty(Node *head){
    if(head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

Node *addToBeginning(Node *head, char str[]){
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(ptr->data,str);
    ptr->pNext=head;
    return ptr;
}

Node *addToEnd(Node *head, char str[]){
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(ptr->data, str);
    ptr->pNext = NULL;
    if (head == NULL) {
        return ptr;
    }
    else {
        Node *current = head;
        while (current->pNext != NULL) {
            current = current->pNext;
        }
        current->pNext = ptr;
        return head;
    }
}

void print(Node *head){
    if(isEmpty(head)){
        printf("The list is empty.\n");
        return;
    }
    printf("Printing...\n");
    Node *current = head;
    int pos=1;
    do {
        printf("Node position %d: %s\n",pos,current->data);
        pos++;
        current = current->pNext;
    } while (current != NULL);
}

int size(Node *head){
    if(isEmpty(head)){
        return 0;
    }
    Node *current = head;
    int size=0;
    do {
        size++;
        current = current->pNext;
    } while (current != NULL);
    return size;
}

Node *tail(Node *head){
    if(isEmpty(head)){
        return NULL;
    }
    Node *current = head;
        while (current->pNext != NULL) {
            current = current->pNext;
        }
        return current;
}

Node *get_node(Node *head, int pos){
    Node *current = head;
        for(int i=1;i<pos;i++) {
            if(current==NULL){
                return NULL;
            }
            current = current->pNext;
        }
        return current;
}

Node *deleteFirst(Node *head){
    if(isEmpty(head)||isEmpty(head->pNext)){
        return NULL;
    }
    Node *newHead=head->pNext;
    free(head);
    return newHead;
}

Node *deleteLast(Node *head){
    if(isEmpty(head)||isEmpty(head->pNext)){
        return NULL;
    }
    Node *current = head;
    while (current->pNext->pNext != NULL) {
        current = current->pNext;
    }
    Node *deleted = current->pNext;
    current->pNext=NULL;
    free(deleted);
    return head;
}

int find(Node *head, char *str){
    if(isEmpty(head)){
        return 0;
    }
    Node *current=head;
    int place=1;
    while(current!=NULL){
        if(strcmp(current->data,str)==0){
            return place;
        }
        current=current->pNext;
        place++;
    }
    return 0;
}



Node *reverse(Node *head){
    int listSize = size(head);
    Node **nodeList = malloc(listSize * sizeof(Node*));
    Node *current = head;
    for(int i = 0; i < listSize; i++){
        nodeList[i] = current;
        current = current->pNext;
    }

    for(int i = 0; i < listSize; i++){
        current = nodeList[listSize - i - 1];
        if (i == listSize - 1){
            current->pNext = NULL;
        }
        else{
            current->pNext = nodeList[listSize - i - 2];
        }
    }
    Node *newHead = nodeList[listSize - 1];
    free(nodeList);
    return newHead;
}

char *toString(Node *head){
    if(isEmpty(head)){
        return "NULL";
    }
    char *str=(char*) malloc(size(head)*17+1);
    str[0]='\0';
    Node *current=head;
    while(current!=NULL){
        strcat(str,"(");
        strcat(str,current->data);
        strcat(str,")");
        strcat(str," -> ");
                if (current->pNext==NULL){
            strcat(str,"NULL");
        }
        current=current->pNext;
    }
    return str;
}

void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->pNext;
        free(current);
        current = next;
    }
}