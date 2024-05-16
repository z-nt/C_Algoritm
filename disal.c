#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph{
    int **adjucentm;
    char *vertext_data;
    int size ;

}graph;

graph* create_graph(int size){
    
    graph* newgraph = calloc(size,sizeof(graph));
    newgraph->size = size;

    newgraph->adjucentm = calloc(size , sizeof(int *));
    for(int i = 0 ; i < size ; i++){
        newgraph->adjucentm[i] = calloc(size , sizeof(int));
    }
    newgraph->vertext_data = calloc(size,sizeof(char ));


    return newgraph;

}
void add_edg(graph *g , int u , int v , int weigth){
    if(u >=0 && u < g->size && v >= 0 && v < g->size){
        g->adjucentm[u][v] = weigth;
        g->adjucentm[v][u] = weigth;
    }
}

void add_vertex_data(graph *g ,int vertex,char vertex_data){
    if(vertex >= 0 && vertex < g->size){
        g->vertext_data[vertex] = vertex_data;
    }
}

int min_distance(int distanc[],bool visited[],int size){
    int min = __INT_MAX__ ,min_index;
    for(int v =0 ; v < size ; v++){
        if(visited[v] == false && distanc[v] <= min){
            min = distanc[v];
            min_index = v;
        }
    }
    return min_index;
}

void dikstra(graph *g , char vertex_start_data){
    int start_vertex = -1;

    for(int i = 0 ; i< g->size ;i++){
        if(g->vertext_data[i] == vertex_start_data){
            start_vertex = i;
            break;
        }
    }

    int distance[g->size];
    bool visited[g->size];

    for(int i = 0 ; i < g->size ; i++){
        distance[i] = __INT_MAX__;
        visited[i] = false;
    }

    distance[start_vertex] = 0;
    for(int count = 0 ; count < g->size - 1 ; count++){
        int u = min_distance(distance,visited,g->size);
        visited[u] = true;

            for(int v = 0 ; v < g->size ; v++){
                if(!visited[v] && g->adjucentm[u][v] 
                && distance[u] != __INT_MAX__
                && distance[u] + g->adjucentm[u][v]< distance[v]){
                    distance[v] = distance[u] + g->adjucentm[u][v];
                }
            }
        }

    for(int i = 0 ; i < g->size ; i++){
        printf("Shortest distance from %c to %c : %d\n",
         vertex_start_data,g->vertext_data[i],distance[i]
        );
    }
}

void dijkstra_procedec(graph *g , int start_vertex, 
                        int *distances,int *predecessors)
{
    int visited[g->size];
    for(int i = 0 ; i < g->size;i++){
        distances[i] = __INT_MAX__;
        visited[i] = 0;
        predecessors[i]=-1;
    }

    distances[start_vertex] = 0;

    for(int count = 0 ; count < g->size -1 ; count++){
        int min = __INT_MAX__,min_index;
        for(int v = 0 ; v < g->size ; v++){
            if(!visited[v] && distances[v] <= min){
                min = distances[v];
                min_index = v;
            }
        }
        int u = min_index;
        visited[u] = 1;
        for(int v = 0 ; v < g->size ; v++){
            if(!visited[v] && g->adjucentm[u][v] && distances[u]
            != __INT_MAX__ && distances[u] + g->adjucentm[u][v] < distances[v]
            ){
            distances[v] = distances[u] + g->adjucentm[u][v];
            predecessors[v] = u;
            }
        }
    }
}
void print_path(graph *g , int *predec , int start_vertex , int end_vertex){
    int stack[g->size];
    int top = -1;
    int current = end_vertex;
    while(current != -1){
        stack[top++] = current;
        current = predec[current];
    }

    while(top != -1){
        printf("%c" , g->vertext_data[stack[top--]]);
        if(top != -1) printf("->");
    }
}





void free_graph(graph *g){
    for(int i = 0 ; i < g->size; i++){
        free(g->adjucentm[i]);
    }
    free(g->adjucentm);
    free(g->vertext_data);
    free(g);
}

int main(void){

graph *G = create_graph(7);


add_vertex_data(G,0,'A');
add_vertex_data(G,1,'B');
add_vertex_data(G,2,'C');
add_vertex_data(G,3,'D');
add_vertex_data(G,4,'E');
add_vertex_data(G,5,'F');
add_vertex_data(G,6,'G');
   
add_edg(G,3,0,4);
add_edg(G,3,4,2);
add_edg(G,0,2,3);
add_edg(G,0,4,4);
add_edg(G,4,2,4);
add_edg(G,4,6,5);
add_edg(G,2,5,5);
add_edg(G,1,2,2);
add_edg(G,1,5,2);
add_edg(G,6,5,5);

int distance[G->size];
int predecessors[G->size];
dijkstra_procedec(G,3,distance,predecessors);
printf("Dikstra Algorithm starting from vertex D:\n\n");

for(int i = 0 ; i < G->size ; i++){
    print_path(G,predecessors,3,distance[i]);
    printf(" , distance: %d\n",distance[i]);
}


free_graph(G);
   
    return 0;
}