#include <stdio.h>
#include <stdlib.h>





int main(void){    
    
   

    return 0;
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

