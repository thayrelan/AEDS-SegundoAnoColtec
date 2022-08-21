#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "graph.h"

int ** gp_creates(int vertex_qnt, int conexao_max){

    int ** grafo = (int **) malloc (sizeof(int*) * vertex_qnt);
    for(int i = 0; i < conexao_max; i++){
        grafo[i] = (int *) calloc (conexao_max, sizeof(int));
    }
    return grafo; 
}

void gp_print(int ** grafo, int vertex_qnt, int conexao_max){
    int i;
    printf("   ");
    for(i = 0; i < vertex_qnt; i++){
        printf("[%d]", i);
    } 
    printf("\n");
    for(i = 0; i < vertex_qnt; i++){
        printf("[%d] ", i);
        for(int j = 0; j < conexao_max; j++){
            printf("%d  ", grafo[i][j]);
        }
        printf("\n");
    }
}

void convert(int **grafo, int vertex_qnt){
    int i, j;
    for(i = 0; i < vertex_qnt; i++){
        for(j = 0; j < vertex_qnt; j++){
            
            if(grafo[i][j] == -1){
                
                grafo[i][j] = 1;
            }
            else if(grafo[i][j] == -2){
                grafo[i][j] = 0;
            }
        }
        
    }
}

void gp_build(int **grafo, int vertex_qnt){
    int i, j;
    int connections;  
    srand(time(NULL));
    for(i = 0; i < vertex_qnt; i++){
        
        for(j = 0; j < vertex_qnt; j++){
            
            connections = rand() % (3 - 1 + 1) + 1;
         
            if(grafo[i][j] == -1 || grafo[i][j] == -2){
                if(grafo[i][j] == -1){
                    grafo[i][j] == 1;
                }else if(grafo[i][j] == -2){
                    grafo[i][j] == 0;
                }
            }
            else if(connections == 1){
                grafo[i][j] = 1;
                grafo[j][i] = -1; 
            }else{
                grafo[i][j] = 0;
                grafo[j][i] = -2;
            }
        }
    }
    
}

void printf_path(control * busca, int vertex_qnt){
    int i; 
    for(i=0;i<vertex_qnt;i++){
        if(busca[i].Distance == -5){
            printf("distancia: [N]  Prior: [N]  Color: [0]\n");
        }
        else if(busca[i].Distance == -3){
            printf("distancia: [F]  Prior: [F]  Color: [2]\n");
        }
        else{
            printf("distancia: [%d]  Prior: [%d]  Color: [%d]\n", busca[i].Distance, busca[i].Prior, busca[i].Color);
        }
    }
}

void print_percurss(control * busca, int vertex_qnt, int inicio, int fim){
    int i = fim, j = 0; 
    int temp = 0, *path;
    if(busca[fim].Color != 0){
        while(i != inicio){
            i = busca[i].Prior;
            temp++;
        }        
    }
    path = (int *)malloc(sizeof(int)*temp);
    i = fim;
    if(busca[fim].Color == 0){
        printf("vertice nao alcacahvel\n");
    }
    else{
        while(i != inicio){
            path[j] = i;
            i = busca[i].Prior;
            j++;
            
        }
        path[temp] = inicio;
        for(i = 0; i <= temp; i++){
            if(i == temp){
                printf("%d", path[temp-i]);    
            }
            else{
                printf("%d-->", path[temp-i]);
            }
        }
        printf("\n");
    }
    free(path);
}