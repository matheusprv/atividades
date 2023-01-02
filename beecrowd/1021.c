#include <stdio.h>

int main(){
    double valor;
    scanf("%lf", &valor);
    valor += 0.001;

    int valorInteiro = valor;
    double centavos = valor - valorInteiro;

    //[0]: 100 - [1]: 50 - [2]: 20 - [3]: 10 - [4]: 5 - [5]: 2
    int notas [] = {100, 50, 20, 10, 5, 2};
    int qtdNotas [] = {0,0,0,0,0,0};

    //[0]: 1.00 - [1]: 0.50 - [2]: 0.25 - [3]: 0.10 - [4]: 0.05 - [5]: 0.01
    double moedas [] = {1.0, 0.50, 0.25, 0.10, 0.05, 0.01};
    int qtdMoedas [] = {0, 0, 0, 0, 0, 0};

    printf("NOTAS:\n");
    for(int i=0; i<6; i++){
        while(valorInteiro >= notas[i]){
            valorInteiro -= notas[i];
            qtdNotas[i]++;
        }
        printf("%d nota(s) de R$ %d.00\n", qtdNotas[i], notas[i]);
    }

    centavos += valorInteiro;

    printf("MOEDAS:\n");
    for(int i=0; i<6; i++){
        while(centavos >= moedas[i]){
            centavos -= moedas[i];
            qtdMoedas[i]++;
            
        }
        printf("%d moeda(s) de R$ %.2lf\n", qtdMoedas[i], moedas[i]);
    }

    return 0;
    
}