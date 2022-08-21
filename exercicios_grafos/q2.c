#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int main(){

    /*Obs: Utilizar o arquivo ent.txt como entrada padrão*/
    Lista **graph, *temp;
    int qnt_vert, qnt_arest, i = 0, j = 0;

    scanf("%d", &qnt_vert);
    graph = (Lista **) malloc (sizeof(Lista *) * qnt_vert);
    do{
        
        scanf("%d", &qnt_arest);
        for(j = 0; j <= qnt_arest; j ++){
            if(j != i){
                graph[i] = lst_insere(graph[i], j+1);
            }
        }
        i++;
        
    }while(i != qnt_vert);
    
    for(i = 0; i < qnt_vert; i++){
        j = 0;
        for(temp = graph[i]; temp != NULL; temp = temp->prox){
            j++;
        }
        printf("GRAFO[%d] GRAU: %d\n", i+1, j);
    }

    return 0; 
}