#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define HASH_SET_SIZE 10

typedef struct  Node {
     char* value ;
     struct Node* next;   
}Node;

Node* myHash[HASH_SET_SIZE] = {NULL};

int hashFunc(const char* value){
    int sum = 0;
    for(int i = 0 ; value[i] != '\0';i++){
        sum+= value[i];
    }
    return sum % HASH_SET_SIZE;
}


void add(const char* name){
    int index = hashFunc(name);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->value = (char*)malloc(strlen(name)+1);

    strcpy(newNode->value , name);
    newNode->next = NULL;
    if(myHash[index] == NULL){
        myHash[index] = newNode;
    }else{
        Node* current = myHash[index];
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}


int contains(const char* value){
    int index = hashFunc(value);
    Node* current = myHash[index];
    while (current != NULL)
    {
        if(strcmp(current->value,value)==0){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void freehash(){
    for(int i = 0 ; i < HASH_SET_SIZE ; i++){
        Node* current = myHash[i];
        while(current != NULL ){
            Node* temp = current;
            current = current->next;
            free(temp->value);
            free(temp);
        }
    }
}

int main(void){
    add("Kian");
    add("Erfan");
    add("Mobin");
    add("Nima");

for(int i = 0 ; i < HASH_SET_SIZE ; i++){
    printf("Bucket: %d: ",i);
    Node* current = myHash[i];
    while(current != NULL){
        printf("%s -> ",current->value);
        current = current->next;
    }
    printf("NULL\n");
}

printf("\nKian:%s\n",contains("Kian")? "true" : "false");






freehash();



    return 0 ;
}
