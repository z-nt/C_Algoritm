#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("cant access memory");
        exit(1);
    }
    newNode->data =data;
    newNode->prev = newNode - 1;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* node){
    while(node){
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("null\n");
}

void backList(Node* node){
    while (node)
    {
        printf("%d -> ",node->data);
        node = node->prev;
    }
    
}


int findminNode(Node* node){
    int min_val= node->data;
    struct Node* currentNode = node->next;
    while(currentNode){
        if(currentNode->data  < min_val){
            min_val = currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return min_val;
}


Node* deleteNode(Node* head , Node* dltNode){
    if(head == dltNode){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    Node* current = head;

    while(current->next && current->next != dltNode){
        current = current->next;
    }
    if(current->next == NULL){
        return head;
    }

    Node* temp  = current->next;
    current->next = current->next->next;
    free(temp);

    return head;

}

Node* insertNode(Node* head , Node* newNode , int pos){
    if(pos == 1 ){
        newNode->next = head;
        return newNode;
    }

    Node* current  = head;

    for(int i = 1 ; i < pos - 1 && current != NULL;i++){
        current = current->next;
    }
    if(current != NULL){
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;

}



int main(void){
   Node* node1 = createNode(5);
   Node* node2 = createNode(6);
   Node* node3 = createNode(7);
   Node* node4 = createNode(8);
   
   
   node1->prev= NULL;
   node1->next = node2;
   node2->next = node3;
   node2->prev = node1;
   node3->next = node4;
   node3->prev = node2;
   node4->prev = node3;
   node4->next = NULL;


    //printList(node1);
    //printf("\n");
    //backList(node4);
    //printf("min val in nodes:%d",findminNode(node1));
    //deleteNode(node1,node3);
    printf("\n");
   Node* newNode = createNode(98);
    insertNode(node1,newNode,3);
    printList(node1);


    free(node1);
    free(node2);
    free(node3);
    free(node4);


    return 0;
}