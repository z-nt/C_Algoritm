#include <stdio.h>
///revers an array
void revers_arr(int arr[],int length){
    int temp = arr[0];
    for(int i = (length - 1) ; i >= 0    ; i--){
            temp = arr[length  -  1];
            temp = arr[i];
            arr[length - i - 1] = temp;
    }

}


int main (void){

int numbers[] = {7,9,6,4,1,2,3,8,10,5};
int numbers_2[] = {1,2,3,4,5,6,7,8,9,10};

 revers_arr(numbers_2,10);

for(int i = 0 ; i < 10 ; i ++){
    printf("arr[%d]=%d\n", i ,numbers_2[i]);
}
    return 0;
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






