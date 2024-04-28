#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//DSA Queues
//A queue is a data structure that can hold many elements.
#define CAPACITY 10


struct Queue{
    int queue[CAPACITY];
    int front;
    int size;
};

//enqueue
void enqueue(struct Queue *q , int element);
// dequeue
int dequeue(struct Queue *q);
void printQueue(struct Queue *q);
int peekq(struct Queue *q);
bool isEmptyq(struct Queue *q);
int sizeq (struct Queue *q);
int main(void){    
    struct Queue myqueue ={
        .front =0,
        .size = 0
    };
    enqueue(&myqueue,'A');
    enqueue(&myqueue,'B');
    enqueue(&myqueue,'C');
    printf("\n");
    printQueue(&myqueue);
    //printf("\n");
    //printf("%c dequeu\n",dequeue(&myqueue));
    printf("%c peek\n",peekq(&myqueue));
   // printf("isEmpty: %d\n", isEmptyq(&myqueue));
    printf("size:%d",sizeq);

    return 0;
}
//DSA Queues
//A queue is a data structure that can hold many elements.

//enqueue
void enqueue(struct Queue *q , int element){
    if(q->size == CAPACITY){
        printf("queue is full\n");
        return ;
    }
    q->queue[(q->front + q->size) % CAPACITY] = element;
    q->size++;
}
//dequeue

int dequeue(struct Queue *q){
    if(q->size == CAPACITY -1 ){
        printf("queue is Empty\n");
        return -1;
    }
    int item = q->queue[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return item;
}
//peek
int peekq(struct Queue *q){
    if(isEmptyq(q)){
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->queue[q->front];
}

// isEmpty
bool isEmptyq(struct Queue *q){
    return q->size == 0;
}
// size 
int sizeq (struct Queue *q){
    return q->size;
}


void printQueue(struct Queue *q){
    for (int i = 0 ; i < q->size ; i++){
        printf("%c\n",q->queue[(q->front + i) % CAPACITY]);
    }
    printf("\n");
}
/////////////stack
typedef struct Stack{
    int *stack;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capa){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->stack = (size_t*) malloc(capa * sizeof(size_t));
    newStack->top = -1;
    newStack->capacity = capa;
    return newStack;
}
/// push element
void push( Stack *s , int element ){
    if(s->top == s->capacity - 1){
        printf("stack is full\n");
        return;
    }
    s->stack[++s->top] = element;
   // printf("top:%d\ncapacity:%d\n",s->top,s->capacity);
    // printf("top:%d\n",++s->top);
}


// pop element 
int pop (Stack *s){
    if(s->top == -1){
        printf("Stack is empty\n");
        return -1 ;
    }
    return s->stack[s->top--];
}

// peakElement
int peek(Stack *s){
    if(s->top == -1){
        printf("stack is empty");
        return -1;
    }
    return s->stack[s->top];
}

// isEmpty

int isEmpty(Stack *s){
    return s->top == -1;
}

int size(Stack *s){
    return s->top + 1;
}



//print stack
void printStack(Stack *s){
    for(int i = 0 ;i <= s->top ; ++i){
        printf("%c\n",s->stack[i]);
    }
}










// search/insert and delet element from unsorted array;
//search 
int findNumber(int arr[],int n , int key){
    
    int i ;
    for(int i = 0 ; i < n ; i++){
        if (arr[i] == key)
        {
            return i;
        }
    }
        return -1;
}

//insert function
int  insertion(int arr[],int n , int insertNumber,int capacity){
    
    if(n >= capacity){
        return n;
    }

    arr[n] = insertNumber;

    return (n + 1);
    
}

// insert  element to an any pos;

void insert_by_pos (int arr[],int n , int num, int pos){

for(int i = n - 1  ; i >= pos ; i--){
    arr[i+1] = arr[i];
}
    arr[pos] = num;
}




// delet element of an array
// find the number
int find (int arr[],int n , int key){
    int i ;
    for ( i = 0 ; i < n ; i++){
        if(arr[i] == key)return i;
    }
    return -1;
}






int  deletElement (int arr[],int n ,int deletNumber){
    int pos = find(arr,n,deletNumber);
    int i ;
    for( i = pos; i < n - 1 ; i++){
            arr[i] = arr[i+1];
    }

    return n - 1;

}

