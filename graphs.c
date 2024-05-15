#include <stdio.h>

void printgraphs(int matrix[4][4],int size){
    for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                printf("%d",matrix[i][j]);
            }
            printf("\n");
    }
}

void printContection(int matrix[4][4] , char vertexdata[4] , int size){

    for(int i = 0 ; i < size ; i++){
        printf("%c: ",vertexdata[i]);
        for(int j = 0 ; j < size ; j++){
            if (matrix[i][j])
            {
                printf("%c  " ,vertexdata[j]);
            }
            
        }
        printf("\n");
    }




}



int main(void){
    char vertexData[4] = {'A','B','C','D'};
    int matrix[4][4] = {
        {1,1,1,1},
        {1,1,1,0},
        {1,1,0,0},
        {1,0,1,1}
    };

    printgraphs(matrix,4);
    printContection(matrix,vertexData,4);

    return 0;
}





