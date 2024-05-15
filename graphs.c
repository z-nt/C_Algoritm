#include <stdio.h>

#define SIZE 4
#define NO_EDGE -1 


typedef struct graphs
{
    int adjecencyMatrix[SIZE][SIZE];
    char vertexdata[SIZE];
}graphs;

void initgraph(graphs *g){
    for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                g->adjecencyMatrix[i][j] = NO_EDGE;
            }
            g->vertexdata[i] = 0;
    }
}

void addEdge (graphs *g , int u , int v,int weigth){
    if(u >= 0 && u < SIZE  && v >= 0 && v < SIZE){
        g->adjecencyMatrix[u][v] = weigth;
    }
}

void addvertexData(graphs *g , int vertex , char data){
        if(vertex < SIZE && vertex >=0){
            g->vertexdata[vertex] = data;
        }
}

void printfAddjacencyMatrix(graphs*g){
    printf("adjacencyMatrix:\n");
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
           if(g->adjecencyMatrix[i][j]==NO_EDGE){
            printf("0 ");
           }else{
             printf("%d ",g->adjecencyMatrix[i][j]);
           }
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0 ; i < SIZE ; i++){
        printf("vertex:%d=%c\n",i, g->vertexdata[i]);
    }
}




// void printgraphs(int matrix[4][4],int size){
//     for(int i = 0 ; i < size ; i++){
//             for(int j = 0 ; j < size ; j++){
//                 printf("%d",matrix[i][j]);
//             }
//             printf("\n");
//     }
// }

// void printContection(int matrix[4][4] , char vertexdata[4] , int size){

//     for(int i = 0 ; i < size ; i++){
//         printf("%c: ",vertexdata[i]);
//         for(int j = 0 ; j < size ; j++){
//             if (matrix[i][j])
//             {
//                 printf("%c  " ,vertexdata[j]);
//             }
            
//         }
//         printf("\n");
//     }




// }



int main(void){
  graphs G;
  initgraph(&G);

  addvertexData(&G,0,'A');
  addvertexData(&G,1,'B');
  addvertexData(&G,2,'C');
  addvertexData(&G,3,'D');

/// 0 3 2 4
/// 0 0 1 0
/// 0 0 0 0
/// 0 0 0 0

  addEdge(&G,0,1,3);
  addEdge(&G,0,2,2);
  addEdge(&G,0,3,4);
  addEdge(&G,1,2,1);

  printfAddjacencyMatrix(&G);
  
  
    // char vertexData[4] = {'A','B','C','D'};
    // int matrix[4][4] = {
    //     {1,1,1,1},
    //     {1,1,1,0},
    //     {1,1,0,0},
    //     {1,0,1,1}
    // };

    // printgraphs(matrix,4);
    // printContection(matrix,vertexData,4);

    return 0;
}





