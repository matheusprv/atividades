#include <string.h>
#include <stdio.h>
# include <stdlib.h>


int main(){
     char bases[301];
     int B, S, C, F;
     int tamanhoString;
     int podeVirar;
     int qtdConexoes;

     while(scanf("%s", bases) != EOF){
        B = 0; S = 0; C = 0; F=0;
        //B e S     C e F.

        podeVirar = 0; //Só pode quando o anteriro não estiver conectado

        tamanhoString = strlen(bases);

        qtdConexoes = 0;

        for(int i=0; i<tamanhoString-1; i++){
            if((bases[i] == 'B' && bases[i+1] == 'S') ||
            (bases[i] == 'S' && bases[i+1] == 'B') ||
            (bases[i] == 'C' && bases[i+1] == 'F') ||
            (bases[i] == 'F' && bases[i+1] == 'C') ){

                qtdConexoes ++;
                

            }
        }



     }
}