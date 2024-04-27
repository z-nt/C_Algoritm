#include <stdio.h>

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


int main(void){    
    


    return 0;
}