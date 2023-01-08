#include <stdio.h>


int main(){

    int qtd = 0;
    for(int i = 2000; i <= 100000; i++){
        if(i % 55 == 0)
            qtd++;
    }

    printf("QTD Divisíveis por 55: %d\n", qtd);

    qtd = 0;
    for(int i = 2000; i <= 100000; i++){
        if(i % 15 == 0)
            qtd++;
    }

    printf("QTD Divisíveis por 15: %d\n", qtd);


}