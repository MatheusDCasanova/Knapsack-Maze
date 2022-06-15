#include <stdio.h>
#include <stdlib.h>


int max(int v1, int v2){
    if (v1 > v2){
        return v1;
    }
    return v2;
}


int solve(int ** toxi, int ** peso, int n, int c){
    // funcao que resolve o problema:
    /*
    - para cada elemento (i,j,c) temos a solucao otima para ir de (0,0) ate (i,j) em uma mochila de capacidade c
    - temos que encontrar o maximo entre os seguintes casos:
        1) considerando que veio de cima e coletando o atual (isso somente se o peso do atual for menor que c)
        2) considerando que veio de cima e nao coletando o atual
        3) considerando que veio da esquerda e coletando o atual (isso somente se o peso do atual for menor que c)
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
                if (peso[i-1][j-1] <= k){ //se couber o atual
                    //considerando que coleto o atual e veio de cima
                    sol[i][j][k] =  toxi[i-1][j-1] + sol[i-1][j][k - peso[i-1][j-1]];

                    //considerando nao coleto atual e veio de cima
                    sol[i][j][k] = max(sol[i][j][k], sol[i-1][j][k]); //ja pega o maximo entre coletando o atual ou n


                    //considerando coleto o atual e veio da esquerda
                    sol[i][j][k] = max(sol[i][j][k], toxi[i-1][j-1] + sol[i][j-1][k-peso[i-1][j-1]]);


                    //considerando nao coleto o atual e veio da esquerda
                    sol[i][j][k] = max(sol[i][j][k], sol[i][j-1][k]);

                } else{
                    //venho de cima e n coleto o atual (ja que o peso do atual eh maior q a capacidade)
                    sol[i][j][k] = sol[i-1][j][k];

                    //comparo com vindo da esquerda
                    sol[i][j][k] = max(sol[i][j][k], sol[i][j-1][k]);
                }
            }
        }
    }

    return sol[n][n][c];
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


    int resultado = solve(toxi, peso, n, c);
    printf("%d\n", resultado);

    return 0;
}