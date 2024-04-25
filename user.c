#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node{
    size_t  age;
    char    *name;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createList(size_t age , char *name){
   Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode){
        printf("cant malloc memory");
        exit(1);
    }
    newNode->age = age;
    newNode->name = name;
    newNode->prev = newNode - 1 ;
    newNode->next = NULL;
    return newNode;
}

void printuser(Node* node){
    while(node){
     printf("age:_%d\n",node->age);
     printf("name:_%s\n",node->name);
        node = node->next;
    }
 
    printf("null\n");
}


void printBack(Node* node){
    while(node){
        printf("age:_%d\n",node->age);
        printf("name:_%s\n",node->name);
        node = node->prev;
    }
    printf("null\n");
}

int findeLowest (Node* node){
    size_t min_val = node->age;

    struct Node* currentNode = node->next;
    while(currentNode){
        if(currentNode->age < min_val) min_val = currentNode->age;

        currentNode = currentNode->next;
    }
    return min_val;
}

Node* deleteUser(Node* head , Node* deletusr){
  
    if(head == deletusr){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    Node* currentNode = head;
    while(currentNode->next && currentNode->next !=  deletusr ){
        currentNode = currentNode->next;
         printf("%s",currentNode->name);
    }

    if(currentNode->next == NULL){
        return head;
    }


    Node* temp = currentNode->next;   
    currentNode->next = currentNode->next->next;
    free(temp);

    return head;
}

Node* insertionUser(Node* head , Node* newNode , size_t pos){
    
    if(pos == 1){
        newNode->next = head;
        return newNode;
    }

    Node* currentNode = head;
    
    for(int i = 0 ; i < pos - 1 && currentNode != NULL ; i++ ){
        currentNode = currentNode->next;
    }

    if(currentNode != NULL){
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }


    return head;





}
int main(){

    char *kian =  "kian";
    char *erfan = "erfan";
    char *mobin = "mobin";
    char *nima =  "nima ";

    Node* node1 = createList(26,kian);

    Node* node2 = createList(27,erfan);
    
    Node* node3 = createList(28,mobin);

    Node* node4 = createList(29,nima);
    char *amo = "amo";
    Node* node5 = createList(29,amo);
   
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
    
    // printf("befor Delete:\n");
    // printuser(node1);
    // printf("\n");
    deleteUser(node1,node3);
    insertionUser(node1,node5,3);
    // printf("\n");
    // printf("after Delete:\n");
     printuser(node1);

    //printf("\n");
    //printBack(node4);
    // printf("min:%d\n", findeLowest(node1));

    return 0;
}