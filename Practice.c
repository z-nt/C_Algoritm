#include <stdio.h>
///1-find the minimum number in an array
int find_minimum(int *arr){
    int size = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[0];
    for(int i = 0 ; i < size ; i++){
        if(temp < arr[i]){
            temp = arr[i];
            return temp;
        } 
    }
}

//find the maximum number in an array
int find_maximum(int *arr){
      int size = sizeof(arr) / sizeof(arr[0]);
        int temp = arr[0];
    for(int i = 0 ; i < size ; i++){
        if(temp > arr[i]){
            return temp;
        }else{
            temp = arr[i];
            return temp;
        }
    }
}
//revers an array
void reversArr(int *arr){
     int size = sizeof(arr) / sizeof(arr[0]);
        int temp=arr[0];
    for(int i = 0;i < size - 1 ; i++){
        temp = arr[i];
        arr[i] = arr[size- i - 1];
        arr[size - i - 1 ] = temp;
    }
}





int main(void){
int numbers[] = {1,2,3,4,5,6,7,8,9};
    reversArr(numbers);
    for(int i = 0 ; i < 9 ; i++){
        printf("arr[%d]=%d\n",i,numbers[i]);
    }

    return 0;
}