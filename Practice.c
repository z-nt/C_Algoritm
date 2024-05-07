#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
int find_maximum(int *arr,int size){
      printf("%d\n",size);
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
void reversArr(int *arr,int len){
      
    int temp=arr[0];
    for(int i = (len / 2 ) ; i >=0 ; i--){
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
//5-check if a string is a palingdrome
bool is_paling = false;
int is_palingdrome(char *string){
    int slen = strlen(string);
    for(int i = 0 ; i < (slen / 2); i++){
        if(string[i] == string[slen - i - 1]){
            return is_paling = true;
        }else{
        return  is_paling = false;
        }
    }
}

//6-sum the valus in an array
int sum_valu(int *arr , int len){
    int sum =0;
    for(int i = 0 ; i < len ; i++){
        sum += arr[i];
    }
    return sum;
}
//7-compute the average of an array
int avrrage_arr(int *arr , int len){
    int sum =0;
    for(int i = 0 ; i < len ; i++){
        sum += arr[i];
    }
    return sum / len;
}

//8-conver celsius to fahrenheit
void convert_c(){
    double C,F,Start,Step,End;

    printf("Enter the C temp:\n");
    scanf("%lf",&C);

    printf("Enter start point:\n");
    scanf("%lf",&Start);

    printf("Enter stap :\n");
    scanf("%lf",&Step);

    printf("Enter end point:\n");
    scanf("%lf",&End);

    F = (C * 1.8) + 35;
    for(C = Start ; C <= End ; C += Step){
        printf("%2.lf     %2.lf\n",F,C);
    }
}

//9-computing the fibonacci sequence

int fibo(int len){
    int item1 = 0;
    int item2 = 1;
    int fib;
    for(int i = 0 ; i < len ; i++){
        fib = item2 + item1;
        item1 = item2 ;
        item2 = fib;
    }
    return fib;
}
//10-counting the vowels in a string
int count_vowles(char *string){
    int slen = strlen(string);
    int count = 0;
    char vowels[] = {'A','B','C','D'};
    for(int i = 0 ; i < slen ; i++){
        if(string[i] == vowels[i]) count++;
    }
    return count;

}




int main(void){
   

    return 0;
}