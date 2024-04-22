#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define swaap true
#define notswaap false









int main (void) {
int  numbers[] = {4,4,4,5,5,2,2,1,1,2,3,4,5,7,7,7};
int length = 16;
  



    return 0;
}


/// counting sort array
void counting_sort(int arr[], int n){
    int max_val = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > max_val ) max_val = arr[i];

    int count[max_val + 1];

    for(int i = 0;  i < n ; i++){
        count[i] = 0;
    }
    for(int i = 0;i <= max_val;i++){
        count[arr[i]]++;
    }
     int index = 0;
    for(int i = 0; i <= max_val; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
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






/// bubble sort in
void bubble_sort(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
        swaap;
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
