//https://www.beecrowd.com.br/judge/pt/problems/view/1023
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qtdPessoas;
    int consumo;
    int consumoMedio;
}Consumo;

int main(){
    int qtdCasas;
    scanf("%d", &qtdCasas);
    
    for(int i=1; qtdCasas!=0 ;i++){
        Consumo *casa = malloc(qtdCasas * sizeof(Consumo));

        int totalPessoas = 0;
        int totalConsumo = 0;

        for(int j=0; j<qtdCasas; j++){
            scanf("%d", &casa[j].qtdPessoas);
            scanf("%d", &casa[j].consumo);
            casa[j].consumoMedio = casa[j].consumo/casa[j].qtdPessoas;
            totalConsumo += casa[j].consumo;
            totalPessoas += casa[j].qtdPessoas;
        }

        //Ordenando o vetor a partir do consumo medio
        Consumo temp;
        for(int j=0; j<qtdCasas; j++){
            for(int k=0; k<qtdCasas; k++){
                if(casa[j].consumoMedio < casa[k].consumoMedio){
                    temp = casa[k];
                    casa[k] = casa[j];
                    casa[j] = temp;
                }
            }
        }

        printf("Cidade# %d:\n", i);
        for(int j=0; j<qtdCasas; j++){
            printf("%d-%d ", casa[j].qtdPessoas, casa[j].consumoMedio);
        }
        printf("\nConsumo medio: %.2lf m3.\n\n", ((double) totalConsumo /totalPessoas));

        free(casa);

        scanf("%d", &qtdCasas);
    }
}