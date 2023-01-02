#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void zerosEsquerda(char*, int, int);

int main(){

    while(1){
        char numero1[10];
        char numero2[10];
        
        scanf("%s",numero1);
        getchar();
        scanf("%s",numero2);

        if(strcmp(numero1, "0") == 0 && strcmp(numero2, "0") == 0){
            break;
        }

        //Adicionando zeros à esquerda do número com a menor quantidade de casas
        int tamNumero1 = strlen(numero1);
        int tamNumero2 = strlen(numero2);

        int qtdZeros = tamNumero1 - tamNumero2;

        if(qtdZeros != 0){
            if(qtdZeros > 0){
                zerosEsquerda(numero2, tamNumero2, qtdZeros);
                
            }
            else{
                zerosEsquerda(numero1, tamNumero1, -1 * qtdZeros);
            }
        }


        //Transformando os valores em inteiros
        int tamanho = tamNumero1 >= tamNumero2 ? tamNumero1 : tamNumero2;
        int* n1 = calloc(tamanho, sizeof(int));
        int* n2 = calloc(tamanho, sizeof(int));

        int carry = 0;

        for(int i=tamanho-1; i>=0; i--){
            n1[i] += numero1[i] - '0';
            n2[i] += numero2[i] - '0';

            //Verificando se ocorre o vai 1. Se sim, acresce em um o valor da próxima casa caso ela não seja a última        
            if(n1[i] + n2[i] >= 10){
                carry++;
                if(i!=0)
                    n1[i-1]++;
            }
        }

        if(carry == 0)
            printf("No carry operation.\n");
        else if(carry == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", carry);

        free(n1);
        free(n2);

    }

    return 0;
}

void zerosEsquerda(char* numero, int tamanho, int qtdZeros){
    //Aumentando o tamanho da string em 1 e alterando e colocando o número 1 casa para frente enquanto a posição original recebe 0
    for(int cont = 0; cont<qtdZeros; cont++){
        for(int i=tamanho; i>=0; i--){
            numero[i+1] = numero[i];
            numero[i] = '0';
        }
        tamanho++;
    }

}
