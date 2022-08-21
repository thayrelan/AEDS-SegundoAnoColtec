#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"



void depthSearch(control * path, int ** graph, int init, int qnt_vertex){
    int i;
    for(i = 0; i < qnt_vertex; i++){
        if(graph[init][i] == 1 && path[i].Color == 0){
            path[i].Prior = init;
            path[i].Color = 1; 
            path[init].Color = 2;
            depthSearch(path, graph, i, qnt_vertex);
        }
         
        
    }
}

void * depthPath(control * path, int ** graph, int init, int qnt_vertex){

    
    int n, i, temp = 0;
    depthSearch(path, graph, init, qnt_vertex);
    for(i = 0; i < qnt_vertex;i++){
        n = i;
        while(n != init && path[i].Color != 0){
           
            n = path[n].Prior;
            temp++;
            
        }
        if(n != init){
         path[i].Distance = -5;
         path[i].Prior = -5;
         path[i].Color = 0;

        }
        else{
            path[i].Distance = temp; 
        }
         path[init].Distance = -3;
         path[init].Prior = -3;
         path[init].Color = 2;
        temp = 0;
    }

}


int main(int argc, char*argv[]){
    int ** graph, qnt_vertex, start_point, end_point; 
    control *depth;

    qnt_vertex = 10; // Quantidade de Vértices do Vetor a ser gerado
    start_point = 1; // Vértice inicial
    end_point = 3; // Vértice Final
    

    depth = (control*)malloc(sizeof(control)*qnt_vertex);


    
    graph = gp_creates(qnt_vertex, qnt_vertex);
    gp_build(graph, qnt_vertex);
    convert(graph, qnt_vertex);
    gp_print(graph, qnt_vertex, qnt_vertex);



    depthPath(depth, graph, start_point, qnt_vertex);
    printf("\nCaminho profundidade: ");
    print_percurss(depth, qnt_vertex, start_point, end_point);


    free(depth);
    for(int i = 0; i < qnt_vertex; i++){
        free(graph[i]);
    }

    return 0; 
}