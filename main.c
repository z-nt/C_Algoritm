#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>








int main (void){

int numbers[] = {7,9,6,4,1,2,3,8,10,5};
int numbers_2[] = {1,2,3,4,5,6,7,8,9,10};

    


return 0 ;
}

// dice roll simulator

int dice_roll(int dice){
    srand(time(NULL));
    int roll = rand() %  dice ;
    printf("%d",roll);

}


//string append with dynamic memory allocation

  char string_append(char *string , char *sequens){
       
    int slen = strlen(string);
    int sequenlen = strlen(sequens);
    int size = sequenlen + slen + 1;

        // printf("%d\n",slen);
        // printf("%d\n",sequenlen);
        // printf("%d\n",size);


    char *s = calloc(size , sizeof(char));
    

    for(int i = 0 ; i <  size ; i++){
        s[i] = sequens[i]; 
    }
    for( int j = 0 ; j < size ; j++){
        s[j  + sequenlen] = string[j];
        s[j] = '\0';
    }
    free(s);
    return *s;
}

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
