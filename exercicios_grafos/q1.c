#include <stdio.h>
#include <stdlib.h>

int main(){


    int **mat, tam, i, j, * grau; 
    scanf("%d", &tam);

    mat = (int **) malloc (sizeof(int*) * tam);
    grau = (int *) calloc (tam, sizeof(int));
    for(i = 0; i < tam; i++){
        mat[i] = (int *) malloc (sizeof(int) * tam);
    }


    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(i > j){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = 0;
            }
        }
    }

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(mat[i][j] != 0){
                grau[i]++;
            }
        }
    }

    for(i = 0; i < tam; i++){
        printf("GRAU DE [%d]: [%d]\n", i+1, grau[i]);
    }

    for(i = 0; i < tam; i++){
        free(mat[i]);
    }
    free(mat);
    return 0; 
}
