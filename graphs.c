#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 7


typedef struct graphs
{
    int adjecencyMatrix[SIZE][SIZE];
    char vertexdata[SIZE];
}graphs;

void initgraph(graphs *g){
    for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j < SIZE ; j++){
                g->adjecencyMatrix[i][j] = 0;
            }
            g->vertexdata[i] = '\0';
    }
}

void addEdge (graphs *g , int u , int v){
    if(u >= 0 && u < SIZE  && v >= 0 && v < SIZE){
        g->adjecencyMatrix[u][v] = 1;
        g->adjecencyMatrix[v][u] = 1;
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
             printf("%d ",g->adjecencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0 ; i < SIZE ; i++){
        printf("vertex:%d=%c\n",i, g->vertexdata[i]);
    }
}

void dfsutil(graphs *g , int v , bool visited[]){
        visited[v] = true;
        printf("%c ",g->vertexdata[v]);

     for(int i = 0 ; i < SIZE ; i ++){
        if(g->adjecencyMatrix[v][i] == 1 && !visited[i]){
            dfsutil(g,i,visited);
        }
     }
}

void dfs(graphs *g , char vertexDate){
    bool visited[SIZE] = {false};
    int startVertex = -1;

    for(int i = 0 ; i < SIZE ; i++){
        if(g->vertexdata[i] == vertexDate){
            startVertex = i;
            break;
        }
    }
        if(startVertex != -1){
            dfsutil(g,startVertex,visited);
        }
}





int main(void){
  graphs G;
  initgraph(&G);

  addvertexData(&G,0,'A');
  addvertexData(&G,1,'B');
  addvertexData(&G,2,'C');
  addvertexData(&G,3,'D');
  addvertexData(&G,4,'E');
  addvertexData(&G,5,'F');
  addvertexData(&G,6,'G');


  addEdge(&G,3,0);
  addEdge(&G,0,2);
  addEdge(&G,0,3);
  addEdge(&G,0,4);
  addEdge(&G,4,2);
  addEdge(&G,2,5);
  addEdge(&G,2,1);
  addEdge(&G,2,6);
  addEdge(&G,1,5);

  printfAddjacencyMatrix(&G);

    printf("\n");
    printf("depth frist  search in graphs:\n");
    dfs(&G,'D');

    return 0;
}





