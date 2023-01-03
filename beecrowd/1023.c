//https://www.beecrowd.com.br/judge/pt/problems/view/1023
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qtdPessoas;
    int consumo;
    int consumoMedio;
}Consumo;

void ordernacao(Consumo *, int, int);

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
        ordernacao(casa, 0, qtdCasas-1);

        printf("Cidade# %d:\n", i);
        for(int j=0; j<qtdCasas; j++){
            printf("%d-%d ", casa[j].qtdPessoas, casa[j].consumoMedio);
        }
        printf("\nConsumo medio: %.2f m3.\n\n", ((float) totalConsumo /totalPessoas));

        free(casa);

        scanf("%d", &qtdCasas);
    }
}

void ordernacao(Consumo * a, int left, int right){
    
    int i, j;
    Consumo x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i].consumoMedio < x.consumoMedio && i < right)
        {
            i++;
        }
        while (a[j].consumoMedio > x.consumoMedio && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        ordernacao(a, left, j);
    }
    if (i < right)
    {
        ordernacao(a, i, right);
    }
}