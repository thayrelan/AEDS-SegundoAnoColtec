#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"



void breadthSearch(control * path, int ** graph, int init, int qnt_vertex, Fila * queue){
    int i;
    for(i=0;i<qnt_vertex;i++){
        if(graph[init][i] == 1 && path[i].Color == 0){
            fila_insere_vet(queue, i);
            path[i].Prior = init;
            path[i].Color = 1;
        }
    }
    if(!fila_vazia_vet(queue)){
        breadthSearch(path, graph, fila_retira_vet(queue), qnt_vertex, queue);
    }
    path[init].Color = 2; 
}

void * breadthPath(control * path, int ** graph, int init, int qnt_vertex, Fila * queue){  
    int n, i, temp = 0;
    breadthSearch(path, graph, init, qnt_vertex, queue);
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
    control *breadth;
    Fila *queue;

    qnt_vertex = 10; // Quantidade de Vértices do Vetor a ser gerado
    start_point = 1; // Vértice inicial
    end_point = 3; // Vértice Final
    

    breadth = (control*)malloc(sizeof(control)*qnt_vertex);
    queue = fila_cria_vet();


    
    graph = gp_creates(qnt_vertex, qnt_vertex);
    gp_build(graph, qnt_vertex);
    convert(graph, qnt_vertex);
    gp_print(graph, qnt_vertex, qnt_vertex);



    breadthPath(breadth, graph, start_point, qnt_vertex, queue);
    printf("\nCaminho largura: ");
    print_percurss(breadth, qnt_vertex, start_point, end_point);


    fila_libera_vet(queue);
    free(breadth);
    for(int i = 0; i < qnt_vertex; i++){
        free(graph[i]);
    }

    return 0; 
}