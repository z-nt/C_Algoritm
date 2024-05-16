#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 7

typedef struct GRAPH{
    int **adjacentM;
    char *vertexData;
    int size;
}GRAPH;


GRAPH* create_graph(int size ){
    GRAPH *newgraph = calloc(size,sizeof(GRAPH));
    newgraph->size = size;

    newgraph->adjacentM = calloc(size,sizeof(int *));

    for(int i = 0 ; i < size ; i++){
        newgraph->adjacentM[i] = calloc(size,sizeof(int));
    }
    newgraph->vertexData = calloc(size , sizeof(char));

    return newgraph;
}

void add_edge(GRAPH *g , int u , int v){
    if(u >= 0 && u < g->size && v >= 0 && v < g->size){
        g->adjacentM[u][v] = 1;
    }
}

void add_vertex_data(GRAPH *g,char vertex_data,int vertex){
    if(vertex >=0 && vertex < g->size){
        g->vertexData[vertex] = vertex_data;
    }
}

void print_graph(GRAPH *g){
    printf("adjacent Matrix:\n");
    
    for(int i = 0 ; i < g->size ; i++){
            for(int j = 0 ; j < g->size ; j++){
                printf("%d ",g->adjacentM[i][j]);
            }
            printf("\n");
    }

    printf("vertex DATA:\n");
    for(int i = 0 ; i < g->size ; i++){
        printf("%c ",g->vertexData[i]);
    }
}

/// function for dfs 
void dfs_utility(GRAPH *g , int v , bool *visited){
    visited[v]= true;
    printf("%c ",g->vertexData[v]);
    for(int i = 0 ; i < g->size ; i++){
        if(g->adjacentM[v][i] == 1 && !visited[i]){
            dfs_utility(g,i,visited);
        }
    }
}
void dfs(GRAPH *g , char startvertex ){
    bool *visited = calloc (g->size,sizeof(bool));
    int start_vertex = -1;


    for(int i = 0 ; i< g->size ; i++){
        if(g->vertexData[i] == startvertex){
            start_vertex = i ; 
            break;
        }
    }
    if(start_vertex != -1){
        dfs_utility(g,start_vertex,visited);
    }
    free(visited);    
}
///function bfs 

void bfs (GRAPH *g , char start_vertex_data){
    bool *visited = calloc(g->size,sizeof(bool));
    int  *queue = calloc(g->size,sizeof(int));
    int  queue_start = 0;
    int  queue_End = 0;
    int  start_vertex = -1;

    for(int i = 0 ; i < g->size ; i++){
        if(g->vertexData[i] == start_vertex_data){
            start_vertex = i;
            break;
        }
    }
    if(start_vertex != -1){
        queue[queue_End++] = start_vertex;
        visited[start_vertex] = true;

        while(queue_start < queue_End){
            int current_vertex = queue[queue_start++];

            printf("%c ",g->vertexData[current_vertex]);

            for(int i = 0 ; i < g->size ;i++){
                if(g->adjacentM[current_vertex][i] ==1 
                && !visited[i]
                ){
                    queue[queue_End++] = i;
                    visited[i]  = true;
                }
            }


        }

    free(visited);
    free(queue);


    }





}




int main(void){

    GRAPH *g = create_graph(7);

    add_vertex_data(g,'A',0);
    add_vertex_data(g,'B',1);
    add_vertex_data(g,'C',2);
    add_vertex_data(g,'D',3);
    add_vertex_data(g,'E',4);
    add_vertex_data(g,'F',5);
    add_vertex_data(g,'G',6);

    add_edge(g,3,0);
    add_edge(g,3,4);
    add_edge(g,4,0);
    add_edge(g,0,2);
    add_edge(g,2,5);
    add_edge(g,2,6);
    add_edge(g,5,1);
    add_edge(g,1,2);

    print_graph(g);
    printf("\n");
    printf("depth frist  search in graphs:\n");
    dfs(g,'D');




    printf("\n");
    printf("breath frist  search in graphs:\n");
    bfs(g,'D');
    return 0;
}




// typedef struct graphs
// {
//     int adjecencyMatrix[SIZE][SIZE];
//     char vertexdata[SIZE];
// }graphs;

// void initgraph(graphs *g){
//     for(int i = 0 ; i < SIZE ; i++){
//             for(int j = 0 ; j < SIZE ; j++){
//                 g->adjecencyMatrix[i][j] = 0;
//             }
//             g->vertexdata[i] = '\0';
//     }
// }

// void addEdge (graphs *g , int u , int v){
//     if(u >= 0 && u < SIZE  && v >= 0 && v < SIZE){
//         g->adjecencyMatrix[u][v] = 1;
//         g->adjecencyMatrix[v][u] = 1;
//     }
// }

// void addvertexData(graphs *g , int vertex , char data){
//         if(vertex < SIZE && vertex >=0){
//             g->vertexdata[vertex] = data;
//         }
// }

// void printfAddjacencyMatrix(graphs*g){
//     printf("adjacencyMatrix:\n");
//     for(int i = 0 ; i < SIZE ; i++){
//         for(int j = 0 ; j < SIZE ; j++){
//              printf("%d ",g->adjecencyMatrix[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\n");

//     for(int i = 0 ; i < SIZE ; i++){
//         printf("vertex:%d=%c\n",i, g->vertexdata[i]);
//     }
// }

// ///depth frist search {stack}
// void dfsutil(graphs *g , int v , bool visited[]){
//         visited[v] = true;
//         printf("%c ",g->vertexdata[v]);

//      for(int i = 0 ; i < SIZE ; i ++){
//         if(g->adjecencyMatrix[v][i] == 1 && !visited[i]){
//             dfsutil(g,i,visited);
//         }
//      }
// }

// void dfs(graphs *g , char vertexDate){
//     bool visited[SIZE] = {false};
//     int startVertex = -1;

//     for(int i = 0 ; i < SIZE ; i++){
//         if(g->vertexdata[i] == vertexDate){
//             startVertex = i;
//             break;
//         }
//     }
//         if(startVertex != -1){
//             dfsutil(g,startVertex,visited);
//         }
// }
// /// breadth frist search {queue}

// void bfs(graphs *g   , char startvertexdata){
//     bool visited[SIZE] = {false};
//     int startvertex = -1;
//     int queue[SIZE] , startqueu = 0 , endqueue = 0;
//    //check start data 
//     for(int i = 0 ; i < SIZE ; i++){
//         if(g->vertexdata[i] == startvertexdata){
//             startvertex = i ;
//             break;
//         }
//     }
//     //
//     if(startvertex != -1){
//         queue[endqueue++] = startvertex;
//         visited[startvertex] = true;
//         while(startqueu < endqueue){
//             int currentvertex = queue[startqueu++];
//             printf("%c ",g->vertexdata[currentvertex]);
//             for(int i = 0 ; i < SIZE ; i++){
//                 if(g->adjecencyMatrix[currentvertex][i] == 1 && !visited[i]){
//                     queue[endqueue++] = i ;
//                     visited[i] = true;
//                 }
//             }
//         }
//     }
// }




