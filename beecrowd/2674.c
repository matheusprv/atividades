#include <stdio.h>
#include <math.h>
#include <string.h>

int verificaPrimo(int n);

int main(){

    int numero;
    char str[100001];

    while(scanf("%d", &numero) != EOF){

        if(verificaPrimo(numero)){
            
            sprintf(str, "%d", numero);
            int tamanhoString = strlen(str);
            int todosPrimos = 1;

            for(int i=0; i < tamanhoString; i++){                
                if(verificaPrimo(str[i] - '0') != 1){
                    todosPrimos = 0;
                    break;
                }
            }

            if(todosPrimos){
                printf("Super\n");
            }
            else{
                printf("Primo\n");
            }

        }
        else{
            printf("Nada\n");
        }
       
    }

    return 0;
}

int verificaPrimo(int n){
    if(n==1 || n==0)
        return 0;

    double raiz = sqrt(n);

    for(int i=2; i <= raiz; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
