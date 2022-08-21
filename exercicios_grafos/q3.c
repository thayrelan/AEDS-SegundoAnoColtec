#include <stdio.h>
#include <stdlib.h>

void verifica_conexao(int ***graph_coltec){
    int i, j, x; 
    for(i = 0; i < 2; i++){
        for(j = 0; j < 10; j++){
                if(i == 0){
                    for(x = 0; x <10; x++){
                        if(graph_coltec[i][j][x] != 1){
                            printf("SERVIDOR [%d]  FALHOU EM COMUNICAR-SE COM O SERVIDOR [%d]\n", j+1, x+1);
                        }
                    }   
                }
                else{
                    for(x = 0; x < 8; x++){
                        if(graph_coltec[i][j][x] != 1){
                            printf("SERVIDOR [%d]  FALHOU EM COMUNICAR-SE COM O SERVIDOR [%d]\n", j+1, x+1);
                        }
                    }   
                }
        }
    }
}

int main(){

    /*Grafo tridimensional representando a conexao entre servidor-computador e servidor-servidor*/
    int ***graph_coltec, i, j, x;
    graph_coltec = (int ***) malloc (sizeof(int**) * 2);
    graph_coltec[0] = (int **) malloc (sizeof(int *) * 10);
    graph_coltec[1] = (int **) malloc (sizeof(int *) * 10);
        for(j = 0; j < 10; j++){
            graph_coltec[0][j] = (int *) malloc (sizeof(int) * 10);
             graph_coltec[1][j] = (int *) malloc (sizeof(int) * 8);
        }
    for(i = 0; i < 2; i++){
        for(j = 0; j < 10; j++){
                if(i == 0){
                    for(x = 0; x <10; x++){
                        graph_coltec[i][j][x] = 1;
                    }
                }
                else{
                    for(x = 0; x < 8; x++){
                        graph_coltec[i][j][x] = 1;
                    }
                }
        }
      
    }
    for(i = 0; i < 2; i++){
        for(j = 0; j < 10; j++){
                if(i == 0){
                    for(x = 0; x <10; x++){
                        printf("%d  ", graph_coltec[i][j][x]);
                    }
                    printf("\n");
                }
                else{
                    for(x = 0; x < 8; x++){
                        printf("%d  ", graph_coltec[i][j][x]);
                    }
                    printf("\n");
                }
        }
        printf("\n\n\n");
    }


    /*Inicialmente a conexao é ideal, então, manualmente alteramos o estado, deligamos a conexao
      entre um dos servidores e entre um dos servidores e seus comoputadores*/
    graph_coltec[0][2][6] = 0;
    graph_coltec[1][5][3] = 0;

    /*Chamamos a função que verifica e identificamos onde encontra-se a anomalia*/
    verifica_conexao(graph_coltec);

    return 0; 
}