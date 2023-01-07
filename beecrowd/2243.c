#include <stdio.h>
#include <stdlib.h>

int main(){

    int colunas;
    scanf("%d", &colunas);

    int ** muro = malloc(colunas * sizeof(int*)) ;
    int * alturas = malloc(colunas * sizeof(int));
    
    int maiorAltura = -1;
    int menorAltura = 500000;

    for(int i=0; i < colunas; i++){
        scanf("%d", &alturas[i]);
    
        if(alturas[i] > maiorAltura)
            maiorAltura = alturas[i];
        
        else if(alturas[i] < menorAltura)
            menorAltura = alturas[i]; 

        muro[i] = calloc(maiorAltura, sizeof(int));
        for(int j=0; j<alturas[i]; j++){
            muro[i][j] = 1;
        }
    }
/*
    for(int i=0; i< colunas; i++){
        muro[i] = calloc(maiorAltura, sizeof(int));
        for(int j=0; j<alturas[i]; j++){
            muro[i][j] = 1;
        }
    }*/

    for(int i=0; i< colunas; i++){
        muro[i] = malloc(maiorAltura * sizeof(int));
        for(int j=0; j<alturas[i]; j++){
            muro[i][j] = 1;
        }
    }

    int trianguloEncontrado = 0;

    //Percorrendo todas as linhas
    for(int alturaAtual = maiorAltura-1; alturaAtual >= menorAltura; alturaAtual--){
        
        //Percorrendo todas as colunas procurando um valor 1 para começar a procurar o triângulo
        for(int colunaAtual = menorAltura-1; colunaAtual < colunas - menorAltura; colunaAtual++){
            
            //Verificando se essa posição pode chegar até a base
            if(muro[colunaAtual][alturaAtual] && (colunaAtual - alturaAtual >= 0 && colunaAtual + alturaAtual <= colunas-1)){
                
                trianguloEncontrado = 1;
                
                //Verificando se irá formar o triângulo
                for(int k = 0; k < alturaAtual; k++){
                    
                    if(!(muro[colunaAtual + k][alturaAtual - k] && muro[colunaAtual - k][alturaAtual - k] )){
                        trianguloEncontrado = 0;
                        break;
                    }
                
                }
            
            }

            if(trianguloEncontrado){
                printf("%d\n", alturaAtual+1);
                for(int i=0; i< colunas; i++)
                    free(muro[i]);
                free(muro);

                free(alturas);

                return 0;
            }
        }
    }
    
    printf("1\n");

    for(int i=0; i< colunas; i++)
        free(muro[i]);
    free(muro);

    free(alturas);


    return 0;
}

