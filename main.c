#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


/// node structor
typedef struct Node{
    int data ;
    struct Node* next;
    struct Node* prev;
}Node;


///  fuction to create new node
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode){
        printf("memory cant alloc addres");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = newNode - 1 ;
    return newNode;
}


// next function for next node
void printListForward(Node* node){
    while(node){
        printf("%d-> " , node->data);
        node= node->next; 
    }
    printf("null\n");
}

///  prev function for prev node  
void printListBack(Node* Node){
    while(Node ){
        printf("%d-> " , Node->data);
        Node = Node->prev;
    }
    printf("null\n");
}


/// finde lowest node in link list

int findelowest( Node* Node ){
    int min_val = Node->data;
    struct Node* curentNode = Node->next;
    while(curentNode){
        if(curentNode->data < min_val){
            min_val = curentNode->data;
        }
        curentNode = curentNode->next;
    }
    return min_val;
}


/// delet node from link list 
Node* deletSpecificNode(Node* head , Node* nodeToDelete){
   
    if(head == nodeToDelete){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    Node* currentNode = head;

    while(currentNode->next && currentNode->next != nodeToDelete){
        currentNode = currentNode->next;
    }

    if(currentNode->next == NULL){
        return head;
    }

    Node* temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(temp);

    return head;
}
/// insert new node to node link list 
Node* insertNode(Node* haed , Node* newNode , int position){
    if(position == 1){
        newNode->next = haed;
        return newNode;
    }

    Node* currentNode = haed;
    
    for(int i = 1 ; i< position - 1 && currentNode != NULL;i++){
        currentNode = currentNode->next;
    }

    if(currentNode != NULL){
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    return haed;

}



int main (void) {
   
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(6);
    Node* node4 = createNode(9);
    
    Node* curentNode = node1;
    Node* start = node1;

    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
 
  //  int result = findelowest(node1);
  //  printf("minmum number in link list: %d \n",result);

    printf("Before deletion:\n");
    printListForward(node1);
    
   // deletSpecificNode(node1,node3);
    Node* newNode = createNode(97);
    insertNode(node1,newNode,3);


    printf("after deletion:\n");
    printListForward(node1);

  //  printListBack(node4);

  

  //  printf("%d\n" , curentNode->data);
    curentNode = curentNode->next;
    while(curentNode != start){
        curentNode= curentNode->next;
    } 
  //  printf("...\n");

   




    free(node1);
    free(node2);
    free(node3);
    free(node4);



    return 0;
}

// link list

// ///////////////////// doubl linke list ;


// typedef struct Node{
//     int data ;
//     struct Node* next;
//     struct Node* prev;
// }Node;

// Node* createNode(int data){
//     Node* newNode = (Node*) malloc(sizeof(Node));
//     if(!newNode){
//         printf("memory cant alloc addres");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     newNode->prev = newNode - 1 ;
//     return newNode;
// }

// void printListForward(Node* node){
//     while(node){
//         printf("%d-> " , node->data);
//         node= node->next; 
//     }
//     printf("null\n");
// }


// void printListBack(Node* Node){
//     while(Node ){
//         printf("%d-> " , Node->data);
//         Node = Node->prev;
//     }
//     printf("null\n");
// }

    // Node* node1 = createNode(3);
    // Node* node2 = createNode(5);
    // Node* node3 = createNode(6);
    // Node* node4 = createNode(9);

    // node1->prev = NULL;
    // node1->next = node2;
    // node2->prev = node1;
    // node2->next = node3;
    // node3->prev = node2;
    // node3->next = node4;
    // node4->prev = node3;
    // node4->next = NULL;


    // printListForward(node1);
    // printListBack(node4);


    // free(node1);
    // free(node2);
    // free(node3);
    // free(node4);


/// binary search 
int binarySearch(int arr[],int size,int target){
    int left = 0;
    int right = size - 1 ;

    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1 ;
}
//int target = 7;
// int result = binarySearch(numbers,length,target);

// if( result != -1){
//     printf("value %d is found index%d\n", target,result);
// }else{
//     printf("value %d not found\n" , target);
// }


/////liner search 

int linerSearch(int arr[],int size , int targetVal){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == targetVal){
            return i;
        }
    }
    return -1;
}



/// merged sort without recursion
void merge(double left [] , int leftSize , double right [] , int rightSize,double result[])
{
    int i = 0;
    int j = 0;
    int k = 0;

        while( i < leftSize && j < rightSize){
            if(left[i] < right[j]){
                result[k++] = left[i++];
            }else{
                result[k++] = right[j++];
            }

        }
            while(i < leftSize){
            result[k++] = left[i++];
        }
            while(j < rightSize){
            result[k++] = right[j++];
        }
}

void mergeSort_withoutR(double arr[], int length){
    
    int step = 1;
    
    while (step < length){
        for(int i = 0 ; i < length ; i += 2 * step){
            int leftSize = step;
            int rightSize = step;
            if(i + step >= length) leftSize = length - i;
            if(i + 2 *step >= length )rightSize = length - i - step;

            double left[leftSize];
            double right[rightSize];

            for(int j = 0 ; j < leftSize ; j++){
                left[j] = arr[i + j];
            }
            for(int j = 0 ; j < rightSize ; j++){
                right[j] = arr[i + step + j];
            }

            double merged[leftSize + rightSize];
            merge(left,leftSize,right , rightSize,merged);

            for(int j = 0 ; j < leftSize + rightSize ; j++){
                arr[i + j] = merged[j];
            }
        }
    }
}







////merg to array with recarsiun

void mergeE(double arr[], int start , int mid,int end){
    int i , j ,k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    double left[n1],right[n2];

    for(i = 0 ; i < n1 ; i++)
        left[i] = arr[start + i];
    for(j=0 ;  j < n2;j++)
        right[j] = arr[mid + 1 + j];
    
    i= 0 ;
    j = 0 ;
    k =start;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1 ){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}




void mergeSort(double arr[], int start , int end){
    if(start < end){
        int mid = (start + end) / 2 ;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid + 1 , end);
      //  merge(arr, start , mid , end);
    }
}


/// counting sort array
void counting_sort(int arr[], int n){
    int max_val = arr[0];
    for(int i = 0 ; i < n ;i++){
        if(arr[i] > max_val){
            max_val = arr[i];
        }
    }
    int count[max_val+1];
    for(int i = 0 ; i <= max_val;i++){
        count[i] = 0;
    }
    for(int i = 0 ; i < n ; i++){
        count[arr[i]]++;
    }
    int index = 0;
    for(int i = 0 ; i <= max_val;i++){
        while(count[i]> 0){
            arr[index++]=i;
            count[i]--;
        }
    }



}
// quicke sort array 

int partition(int arr[], int low , int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high ; j++){
            if(arr[j]  <= pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
    int temp = arr[i + 1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int arr[] , int low , int high){
    if(low < high){
        int pivoitIndex = partition(arr,low,high);
        quicksort(arr,low,pivoitIndex -1 );
        quicksort(arr,pivoitIndex + 1,high);
    }


}

/// insert sort
void inserting_sort(int *arr , int n){

    for(int i = 1 ; i < n ; i++){
        int insertIndex = i;
        int currentvalue = arr[i];
        int j = i - 1;

        while( j >= 0 && arr[j] > currentvalue){
            arr[j+1] = arr[j];
            insertIndex = j;
            j--;
        }
        arr[insertIndex]= currentvalue;
    }
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]=%d\n",i , arr[i]);
    }
}



/// slection sort array with swap values

void selection_sort_swap(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
      int min_index = i;
        for(int j = i + 1; j < n ; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }     
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }
    printf("sorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
}



/// slection sort array
//The Selection Sort algorithm finds the lowest value in an array and moves it to the front of the array.
void selection_sort(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
      int min_index = i;
        for(int j = i + 1; j < n ; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }     
        int min_value = arr[min_index];
        for(int k = min_index ; k > i ; k--){
            arr[k] = arr[k - 1];
        }
        arr[i] = min_value;
    }
    printf("sorted array: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
}





//Bubble Sort is an algorithm that sorts an array from the lowest value to the highest value.
/// bubble sort in
void bubble_sort(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < (n-i-1); j++){
                if( arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
        }

    }
for(int i = 0 ; i < n ; i++){
    printf("arr[%d]=%d\n",i,arr[i]);
}

}


//Search, insert and delete in an unsorted array

void edit_arr(int arr[],int length);


void edit_arr(int arr[], int length){

int num = 10;

int temp = arr[0];

    for(int i = 0  ; i < length ; i++){
        if (arr[i] != num) arr[length + 1] = num;
    }

}


void concat(char a[],char b [],char c[], int n1, int n2) {

    int i = 0;
    for (i; i < n1 ; i++){
        c[i] = a[i];
    }
    for(int j = 0 ; j < n2 ; j++){
        printf("%d\n",i);
        c[i++] = b[j];
        printf("%d\n",i);
    }
    c[i] = '\0';
}



// void concat(char a[],char b [],char c[], int n1, int n2);

// char *string_append(char *string , char *sequens){
       
//     int slen = strlen(string);
//     int sequenlen = strlen(sequens);
//     int size = sequenlen + slen + 1;
//         // printf("%d\n",slen);
//         // printf("%d\n",sequenlen);
//         // printf("%d\n",sizcvc,cve);


//     char *s = malloc(size * 4);
    

//     for(int i = 0 ; i <  size ; i++){
//         s[i] = string[i]; 
//     }
//     for( int j = 0 ; j < size ; j++){
//         s[j  + sequenlen] = sequens[j];
//     }
//     s[size + 1] = '\0';
//     // free(s);
//     return s;
// }



// dice roll simulator

int dice_roll(int dice){
    srand(time(NULL));
    int roll = rand() %  dice ;
    printf("%d",roll);

}


//string append with dynamic memory allocation



///counting the vowels in a string

int count_vowels(char *s){
        int slen = strlen(s);
        int Counter = 0;
        char vowels [] = {'A','U','I','E','B'};
        for(int i = 0 ; i < slen ; i ++){
            if(s[i] == vowels[i]) Counter++;
        }
        return Counter;
}



/////// find the minmum number in array
int min_number( int arr[],int length){
    int temp = arr[0];
    for (int i = 0 ; i < length ; i++){
        if (temp > arr[i]) temp = arr[i];
    }
    return temp;
}
// int result = min_number(numbers,10);

/////// find the maximum number in array
int max_number(int arr[],int length){
    int temp = arr[0];
    for(int i = 0 ; i < length ; i++){
        if(temp < arr[i]) temp = arr[i];
    }
    return temp;
}
//int result = max_number(numbers,10);

/// count the sum value of arrays
int sum_valus(int arr[],int length){
    int sum = 0;
    for (int i = 0 ; i < length ; i++){
        sum = sum + arr[i];
    }
    return sum;

}
//int result = sum_valus(numbers,10);

///revers an array
void revers_arr(int arr[],int length){
    int temp = arr[0];
    for(int i = (length / 2) ; i >= 0    ; i--){
            temp = arr[i ];
             arr[i] = arr[length - i - 1];
            arr[length - i - 1 ] = temp;
    }

}




///check if a string is palingdrome

void string_palingDrome( char *s){
 int slen = strlen(s);
 for(int i = 0 ; i < (slen /2 )  ; i++ ){
        if(s[i] == s[slen-i-1]){
            printf("string is palingDrome\n");
        }else{
            printf("is not\n");
        }
 }
}


//compute of avrage an array 

int avrage_array(int arr[], int length){
int sum= 0;
double average = 0 ;

    for(int i = 0 ; i < length ; i++){
        sum = sum + arr[i];
    }
    printf("%d\n",sum);
   
    average = sum / length;

    return average;
}


///conver celsuis to fahrenheit

void celsuis_to_fahrenheit(){
    double c;
    double F;
    double start , step , end;

    printf("Enter the C temp:\n");
    scanf("%lf",&c);


    printf("Enter start Point:\n");
    scanf("%lf",&start);

    printf("Enter end point:\n");
    scanf("%lf",&end);

    printf("Enter the step: \n");
    scanf("%lf",&step);

    F = (c * 1.8 ) + 35;

    for(c = start ; c <= end; c += step){
        printf("F:%2.lf               C:%2.lf\n",F,c);    
    }
}
//computing the fibonacci sequence
int comput_fibo(int length){

int num1 = 1;
int num2 = 2;
int fib;

    for(int i = 0 ; i < length ; i++){
            fib = num1 + num2;
            num1 = num2;
            num2 = fib;
    }
    return fib;
}
