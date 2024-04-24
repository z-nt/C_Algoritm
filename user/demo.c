#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node{
    size_t  age;
    char    *name;
    
}Node;

Node* createList(size_t age , char *name){
   Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode){
        printf("cant malloc memory");
        exit(1);
    }
    newNode->age = age;
    newNode->name = name;
    return newNode;
}

void printuser(Node* node){

     printf("%d\n",node->age);
     printf("%s\n",node->name);
 
    printf("null\n");
}





int main(){

    char *kian = "kian";
    Node* node1 = createList(26,kian);
   
    

    printuser(node1);



    return 0;
}