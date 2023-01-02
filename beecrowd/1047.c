#include <stdio.h>

int main(){

    int horaInicio, minutoInicio, horaFim, minutoFim;
    
    scanf("%d", &horaInicio);
    scanf("%d", &minutoInicio);
    scanf("%d", &horaFim);
    scanf("%d", &minutoFim);

    int minutosTotalInicio = horaInicio*60 + minutoInicio;
    int minutosTotalFim = horaFim*60 + minutoFim;

    int tempoTotal = minutosTotalFim - minutosTotalInicio;

    if(tempoTotal < 0){
        tempoTotal = (1440 - minutosTotalInicio) + minutosTotalFim;
    }
    else if(tempoTotal == 0){
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
        return 0;
    }
    
    int minutosTotal = tempoTotal % 60;
    int horasTotal = (tempoTotal-minutosTotal)/60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horasTotal, minutosTotal);

    return 0;
}