#include <stdio.h>
#include <stdlib.h>



void solve(int ** toxi, int ** peso, int n, int c){
    // funcao que resolve o problema:
    /*
    - para cada elemento (i,j,c) temos a solucao otima para ir de (0,0) ate (i,j) em uma mochila de capacidade c
    - temos que encontrar o maximo entre os seguintes casos:
        1) considerando que veio de cima e coletando o atual (isso se o peso do atual for menor que c)
        2) considerando que veio de cima e nao coletando o atual
        3) considerando que veio da esquerda e coletando o atual (isso se o peso do atual for menor que c)
        4) considerando que veio da esquerda e nao coletando o atual
    - eh importante notar que caso esteja na borda esquerda ou superior, a solucao para o de cima ou da esquerda eh 0
    */    

    // alocar matriz 3D para armazenar as solucoes:
    int *** sol = (int ***)malloc(n*sizeof(int **));
    for(int i = 0; i <= n; i++){
        sol[i] = (int **)malloc(n*sizeof(int *));
        for(int j = 0; j <= n; j++){
            sol[i][j] = (int *)malloc((c+1)*sizeof(int));
        }
    }

    //para cada um dos elementos da primeira linha, inicializar todos os k valores com 0
    for (int j = 0; j <= n; j++){
        for (int k = 0 ; k <= c; k++){
            sol[0][j][k] = 0;
        }
    }

    //para cada um dos elementos da primeira coluna, inicializar todos os k valores com 0
    for (int i = 0; i <= n; i++){
        for (int k = 0 ; k <= c; k++){
            sol[i][0][k] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= c; k++){
                if (peso[i][j] <= k){
                    //considerando que coleto o atual:
                    sol[i][j][k] = 
                }
            }
        }
    }








/*for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
        for (int k = 0; k <= c; k++){
            if (i == 0 && j == 0){
                sol[i][j][k] = 0;
            }
            else if (i == 0){
                sol[i][j][k] = sol[i][j-1][k];
            }
            else if (j == 0){
                sol[i][j][k] = sol[i-1][j][k];
            }
            else if (peso[i-1][j-1] <= k){
                sol[i][j][k] = max(sol[i-1][j][k], sol[i][j-1][k-peso[i-1][j-1]] + peso[i-1][j-1]);
            }
            else{
                sol[i][j][k] = sol[i-1][j][k];
            }
        }
    }
*/
}


    
}




int main() {
    
    int n, c;
    scanf("%d %d", &n, &c);

    int **toxi, **peso;
    toxi = (int **) malloc(n * sizeof(int *));
    peso = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i <n; ++i) {
        toxi[i] = (int *) malloc(n * sizeof(int));
        peso[i] = (int *) malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &toxi[i][j]);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &peso[i][j]);

    

    // para exemplificar a saida
    int value = 42;
    char *solution = "CDDCBCBC";

    printf("%d\n%s\n", value, solution);

    return 0;
}