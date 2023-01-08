#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //Bisexto: Divisível por 4, não por 100, 400 sim
    //Huluculu: Divisível por 15 
    //Buluculu: Bissexto e divisivel por 55
    
    int ano;
    char anoStr[1001];
    char subAno[5];
    int tamanhoString;

    int bissexto;
    int anoComDatasEspeciais;

    while(scanf("%s", anoStr) != EOF){

        anoComDatasEspeciais = 0; 

        tamanhoString = strlen(anoStr);

        subAno[0] = anoStr[tamanhoString - 4];
        subAno[1] = anoStr[tamanhoString - 3];
        subAno[2] = anoStr[tamanhoString - 2];
        subAno[3] = anoStr[tamanhoString - 1];
        subAno[4] = '\0';

        ano = atoi(subAno);

        //Verificando se o ano é bissexto 
        if(ano%4 == 0 && (ano % 100 !=0 || ano % 400 == 0)){
            bissexto = 1;
            printf("This is leap year.\n");
            anoComDatasEspeciais = 1;
        }
        else{
            bissexto = 0;
        }
            
        if(ano % 15 == 0){
            printf("This is huluculu festival year.\n");
            anoComDatasEspeciais = 1;
        }

        if(bissexto && ano % 55 == 0){
            printf("This is huluculu festival year.\n");
        }

        if(!anoComDatasEspeciais)
            printf("This is an ordinary year.\n");


        printf("\n");
    }
    return 0;
}