#include <stdio.h>
#include <string.h>
#include <stdbool.h>

///conver celsuis to fahrenheit




int main (void){

int numbers[] = {7,9,6,4,1,2,3,8,10,5};
int numbers_2[] = {1,2,3,4,5,6,7,8,9,10};



return 0 ;
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



