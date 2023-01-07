#include <stdio.h>
#include <string.h>
#define TAM_MAX 50001

int main(){

    int casosDeTeste;
    while(scanf("%d", &casosDeTeste) != EOF){
        getchar();

        int tamMaiorPalindromo = 0;
        int tamPalavra;
        char palavra [TAM_MAX];

        for(int cont=0; cont<casosDeTeste; cont++){

            scanf("%s", palavra);
            tamPalavra = strlen(palavra);

            int palindromo = 1;

            for(int i = 0; i<tamPalavra; i++){
                if(palavra[i] != palavra[tamPalavra - i -1]){
                    palindromo = 0;
                    break;
                }
            }

            if(palindromo && tamPalavra > tamMaiorPalindromo)
                tamMaiorPalindromo = tamPalavra;

        }

        printf("%d\n", tamMaiorPalindromo);

    }


    return 0;
}